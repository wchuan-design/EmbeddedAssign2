#include <Arduino.h>

// 定义LED引脚
const int LED1_PIN = 13;  // 改用引脚13
const int LED2_PIN = 12;  // 改用引脚12

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(115200);
  // 添加初始化提示
  delay(1);  // 等待串口稳定
  Serial.println("System ready. Send '1' or '2' to control LEDs.");
}

void loop() {
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c == '1'){
      int val1 = digitalRead(LED1_PIN);
      if(val1 == HIGH){
        Serial.println("LED 1 off");
        digitalWrite(LED1_PIN, LOW);
      }
      else{
        Serial.println("LED 1 on");
        digitalWrite(LED1_PIN, HIGH);
      }
    }
    else if(c == '2'){
      int val2 = digitalRead(LED2_PIN);
      if(val2 == HIGH){
        Serial.println("LED 2 off");
        digitalWrite(LED2_PIN, LOW);
      }
      else{
        Serial.println("LED 2 on");
        digitalWrite(LED2_PIN, HIGH);
      }
    }
    else{
      Serial.println("Invalid command");
    }
  }
}

