#include <iostream>
#include <fstream>
#include <vector>

int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    uint64_t N;
    input >> N;
    std::vector <uint64_t> h(2501);
    for(uint64_t i=0; i<2*N-1; i++) {
      for(uint64_t j=0; j<N; j++) {
        uint64_t tmp;
        input >> tmp;
        h[tmp]++;
      }
    }
    output << "Case #" << count << ":";
    for(uint64_t i=0; i<2501; i++) {
      if(h[i]%2==1) output << ' ' << i;
    }
    output << '\n';
  }
}
