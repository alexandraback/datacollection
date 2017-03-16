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
    std::vector <uint64_t> BFF(N+1), C(N+1);
    for(uint64_t i=1; i<=N; i++) {
      input >> BFF[i];
    }
    uint64_t maxcirc = 0;
    for(uint64_t i=1; i<=N; i++) {
      uint64_t temp=i;
      for(uint64_t j=1; j<=N+2; j++) {
        if(BFF[BFF[temp]]==temp) {
          if(C[temp]<j) C[temp]=j;
          break;
        }
        if(BFF[temp]==i) {
          if(maxcirc < j) maxcirc = j;
          break;
        }
        temp = BFF[temp];
      }
    }
    uint64_t sum=0;
    for(uint64_t i=1; i<=N; i++) {
      sum+=C[i];
    }
    if(sum < maxcirc) sum = maxcirc;
    output << "Case #" << count << ": ";
    output << sum;
    output << '\n';
  }
}
