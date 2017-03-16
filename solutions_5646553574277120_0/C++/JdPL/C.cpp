#include <iostream>
#include <fstream>
#include <vector>

std::vector <uint64_t> coin(50);

bool notRep(uint64_t c, uint64_t min) {
  if(c==0) return false;
  for(uint64_t i=min; i<=c; i++) {
    if(coin[i]==1) {
      if(notRep(c-i, i+1)==false) return false;
    }
  }
  return true;
}

int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t caseNum=1; caseNum<=T; caseNum++) {
    std::cout << "Case #" << caseNum << "\n";
    uint64_t C, D, V, solution=0;
    input >> C >> D >> V;
    for(uint64_t i=0; i<50; i++) {
      coin[i]=0;
    }
    for(uint64_t i=0; i<D; i++) {
      uint64_t temp;
      input >> temp;
      coin[temp]=1;
    }
    for(uint64_t i=1; i<=V; i++) {
      if(notRep(i, 1)) {
        coin[i]=1;
        solution++;
      }
    }
    
    output << "Case #" << caseNum << ": ";
    output << solution;
    output << '\n';
  }
}
