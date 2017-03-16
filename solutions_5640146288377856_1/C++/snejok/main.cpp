#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <math.h>


template <typename T>
void printAnswer(int c, const T& msg) {
  std::cout << "Case #" << c <<  ": " << msg << std::endl;
}


void A() {
  int T = 0;
  std::cin >>T;
  
  for (int i = 0; i<T; ++i) {
    int R,C,W;
    std::cin >> R >> C >> W;
    
    int answer;// = R * (C/W) + W;
    if (C % W) {
      answer = R*(C/W) + W;
    } else {
      answer = R*(C/W)+W-1;
    }
//    if (C % W) {
//      answer = R * (std::ceil(float(C)/W)) + W;
//      if (C % W == W-1)
//        answer -= 1;
//    } else {
//      answer = R * (C/W) + W;
//    }
    printAnswer(i+1, answer);
  }
}


int main(int argc, const char * argv[]) {
  A();
  return 0;
}
