#include <iostream>
#include <fstream>
#include <string>
#include <vector>

uint64_t pot(uint64_t base, uint64_t exp) {
  uint64_t res;
  res=1;
  while(exp--) res*=base;
  return res;
}

int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  output.precision(7);
  input >> T;
  for(uint16_t caseNum=1; caseNum<=T; caseNum++) {
    std::cout << "Case #" << caseNum << "\n";
    uint64_t K,L,S, off, words, count, max;
    double avg;
    bool test;
    input >> K >> L >> S;
    std::vector <char> key(K);
    std::vector <char> word(L);
    std::vector <char> tWord(S);
    for(uint64_t i=0; i<K; i++) {
      input >> key[i];;
    }
    for(uint64_t i=0; i<L; i++) {
      input >> word[i];
    }
    test=false;
    off=0;
    for(uint64_t i=1; i<L; i++) {
      if(test==false) {
        test=true;
        for(uint64_t j=0; j+i<L; j++) {
          if(word[j]!=word[j+i]) test=false;
        }
        if(test==true) off=i;
      }
    }
    words = pot(K, S);
    count = 0; 
    for(uint64_t i=0; i<words; i++) {
      uint64_t copy=i;
      for(uint64_t j=0; j<S; j++) {
        tWord[j]=key[copy%K];
        copy/=K;
      }
      for(uint64_t j=0; j<=S-L; j++) {
        test=true;
        for(uint64_t k=0; k<L; k++) {
          if(word[k]!=tWord[j+k]) test=false;
        }
        if(test==true) count++;
      }
    }
    
    if(off==0) off=L;
    max=1+((S-L)/off);
    max*=words;
    if(count==0) {
      avg=0;
    } else {
      avg = (double) (max-count)/words;
    }
    
    output << "Case #" << caseNum << ": ";
    output << avg;
    output << '\n';
  }
}
