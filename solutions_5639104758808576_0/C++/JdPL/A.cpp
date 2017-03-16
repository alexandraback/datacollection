#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    uint64_t a, friends=0, standing=0;
    std::string str;
    input >> a;
    input >> str;
    for(uint16_t i=0; i<=a; i++) {
      if(str[i]!='0') {
        if(standing<i) {
          friends+=i-standing;
          standing+=friends;
        }
        standing+=str[i]-'0';
      }
    }
    
    
    output << "Case #" << count << ": ";
    output << friends;
    output << '\n';
  }
}
