#define CW 5 // CW+
#define CCW 6 // CCW+

void CW_n(int n) {
  for (int i = 0; i < n; i++) {
    digitalWrite(CW, HIGH);
    delayMicroseconds(1000); 
    digitalWrite(CW, LOW);
    delayMicroseconds(1000);
  }
}

void CCW_n(int n) {
  for (int i = 0; i < n; i++) {
    digitalWrite(CCW, HIGH);
    delayMicroseconds(1000);
    digitalWrite(CCW, LOW);
    delayMicroseconds(1000);
  }
}

void setup() {
  pinMode(CW, OUTPUT);
  pinMode(CCW, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "CW") {
      CW_n(3600); // Rotate 360 degrees clockwise
    } else if (command == "CCW") {
      CCW_n(3600); // Rotate 360 degrees counterclockwise
    } else {
      // do nothing
    }
  }
}
