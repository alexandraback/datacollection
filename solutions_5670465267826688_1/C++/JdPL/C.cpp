#include <iostream>
#include <fstream>
#include <string>



struct quaternion {
  bool negative;
  char c;
  void add(char a);
};

void quaternion::add(char a) {
  switch (c) {
    case '1':
      c=a;
      break;
    case 'i':
      switch (a) {
        case 'i':
          negative=!negative;
          c='1';
          break;
        case 'j':
          c='k';
          break;
        case 'k':
          negative=!negative;
          c='j';
          break;
      }
      break;
    case 'j':
      switch (a) {
        case 'i':
          negative=!negative;
          c='k';
          break;
        case 'j':
          negative=!negative;
          c='1';
          break;
        case 'k':
          c='i';
          break;
      }
      break;
    case 'k':
      switch (a) {
        case 'i':
          c='j';
          break;
        case 'j':
          negative=!negative;
          c='i';
          break;
        case 'k':
          negative=!negative;
          c='1';
          break;
      }
      break;
  }
}

bool check(std::string word, uint64_t length) {
  uint64_t i=0;
  quaternion q;
  q.negative=false;
  q.c='1';
  while((q.negative) || (q.c!='i')) {
    if(i==length) return false;
    q.add(word[i]);
    i++;
  }
  q.negative=false;
  q.c='1';
  while((q.negative) || (q.c!='j')) {
    if(i==length) return false;
    q.add(word[i]);
    i++;
  }
  q.negative=false;
  q.c='1';
  while((q.negative) || (q.c!='k')) {
    if(i==length) return false;
    q.add(word[i]);
    i++;
  }
  q.negative=false;
  q.c='1';
  while(i<length) {
    q.add(word[i]);
    i++;
  }
  if(q.negative) return false;
  if(q.c!='1') return false;
  return true;
}


int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    std::cout << "Case #" << count << "\n";
    uint64_t L, X;
    std::string str, word;
    input >> L >> X;
    input >> str;
    if(X>12) X=12+X%4;
    for(uint16_t i=1; i<=X; i++) {
      word+=str;
    }
    
    
    output << "Case #" << count << ": ";
    if(check(word, L*X)) {
      output << "YES";
    } else {
      output << "NO";
    }
    output << '\n';
    std::cout << '\n';
  }
}
