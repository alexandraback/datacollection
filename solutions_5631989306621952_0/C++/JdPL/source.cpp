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
    std::string in, out;
    input >> in;
    out = in[0];
    for(uint64_t i=1; i<in.length(); i++) {
      if(in[i]>=out[0]) {
        out=in[i]+out;
      } else {
        out=out+in[i];
      }
    }
    output << "Case #" << count << ": ";
    output << out;
    output << '\n';
  }
}
