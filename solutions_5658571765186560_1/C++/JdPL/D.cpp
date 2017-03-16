#include <iostream>
#include <fstream>


int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    std::cout << "Case #" << count << "\n";
    uint64_t X, R, C, max, min;
    bool solved = false;
    input >> X >> R >> C;
    if(R>C) {
      max=R; min=C;
    } else {
      max=C; min=R;
    }
    
    
    output << "Case #" << count << ": ";
    if(solved==false && X==1) {
      solved=true;
      output << "GABRIEL";
    }
    if(solved==false && (R*C)%X!=0) {
      solved=true;
      output << "RICHARD";
    }
    if(solved==false && X>max) {
      solved=true;
      output << "RICHARD";
    }
    if(solved==false && (X+1)/2>min) {
      solved=true;
      output << "RICHARD";
    }
    if(solved==false && X==2) {
      solved=true;
      output << "GABRIEL";
    }
    if(solved==false && (X+1)/2==min && X/2==min) {
      solved=true;
      output << "RICHARD";
    }
    if(solved==false && X>=7) {
      solved=true;
      output << "RICHARD";
    }
    if(solved==false) {
      solved=true;
      output << "GABRIEL";
    }
    output << '\n';
    std::cout << '\n';
  }
}
