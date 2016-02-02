#define NOTE_LC1 131
#define NOTE_LC2 147
#define NOTE_LC3 165
#define NOTE_LC4 175
#define NOTE_LC5 196
#define NOTE_LC6 221
#define NOTE_LC7 248

#define NOTE_MC1 262
#define NOTE_MC2 294
#define NOTE_MC3 330
#define NOTE_MC4 350
#define NOTE_MC5 393
#define NOTE_MC6 441
#define NOTE_MC7 495

#define NOTE_HC1 525
#define NOTE_HC2 589
#define NOTE_HC3 661
#define NOTE_HC4 700
#define NOTE_HC5 786
#define NOTE_HC6 882
#define NOTE_HC7 990

unsigned int pinOutput = 12; // speaker
unsigned int pinTouch  = 4; // touch pad

void setup() {
  boot_notice();
  pinMode(pinTouch, INPUT);
}

void loop() {
  if (digitalRead(pinTouch) == HIGH) {
    touch_notice();
  }
}

void boot_notice() {
  int melody[] = {
    NOTE_MC3, NOTE_MC3, 0, NOTE_MC3, 0, NOTE_MC1, NOTE_MC3, 0, NOTE_MC5, 0, NOTE_LC5
  };

  int melodyDurations[] = {
    8, 8, 8, 8, 8, 10, 8, 8, 4, 6, 4
  };
  for (int thisNote = 0; thisNote < 11; thisNote++) {
    int melodyDuration = 1000 / melodyDurations[thisNote];
    int pauseBetweenNotes = melodyDuration * 1.30;
    tone(pinOutput, melody[thisNote], melodyDuration);
    delay(pauseBetweenNotes);
    noTone(pinOutput);
  }
}

void touch_notice() {
  int birthday[] = {
    NOTE_MC5, 0, NOTE_MC5, 0, NOTE_MC6, 0, NOTE_MC5, 0, NOTE_HC1, 0, NOTE_MC7, 0, 
    NOTE_MC5, 0, NOTE_MC5, 0, NOTE_MC6, 0, NOTE_MC5, 0, NOTE_HC2, 0, NOTE_HC1, 0, 
    NOTE_MC5, 0, NOTE_MC5, 0, NOTE_HC5, 0, NOTE_HC3, 0, NOTE_HC1, 0, NOTE_MC7, NOTE_MC6, 0, 
    NOTE_HC4, 0, NOTE_HC4, 0, NOTE_HC3, 0, NOTE_HC1, 0, NOTE_HC2, 0, NOTE_HC1
  };

  int birthdayDurations[] = {
    4, 64, 24, 16, 3, 64, 3, 64, 3, 64, 2, 6, 
    4, 64, 24, 16, 3, 64, 3, 64, 3, 64, 2, 6,
    4, 64, 24, 16, 3, 64, 3, 32, 3, 32, 3, 2, 6,
    4, 64, 24, 16, 3, 32, 3, 32, 3, 32, 1
  };

  for (int thisNote = 0; thisNote < 48; thisNote++) {
    int birthdayDuration = 1000 / birthdayDurations[thisNote];
    int pauseBetweenNotes = birthdayDuration * 1.30;
    tone(pinOutput, birthday[thisNote], birthdayDuration);
    delay(pauseBetweenNotes);
    noTone(pinOutput);
  }
}
