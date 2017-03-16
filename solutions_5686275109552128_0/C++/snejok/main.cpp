//
//  main.cpp
//  CodeJam
//
//  Created by Artem on 4/11/15.
//  Copyright (c) 2015 Artem. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

void A() {
  int T = 0;
  std::cin >> T;

  for (int i = 0; i<T; ++i) {
    int sMax = 0;
    std::cin >> sMax;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> ss(s.size());
    for (size_t i = 0; i<s.size(); ++i)
      ss[i] = s[i] - '0';

    int friends = 0;
    int acc = 0;
    for (size_t j = 0; j<ss.size(); ++j) {
      int newFriends = std::max<int>(0, j-acc);
      friends += newFriends;
      acc += ss[j] + newFriends;
    }
    
    std::cout << "Case #" << i+1 <<  ": " << friends << std::endl;
  }
}


int countDivision(int number, int stop) {
  return (number + stop - 1) / stop - 1;
}

int countSpecialTimes(std::vector<int>& eaters, int stop) {
  int acc = 0;
  for (int i = 0; i<eaters.size(); ++i) {
    acc += countDivision(eaters[i], stop);
  }
  
  return acc;
}

void B() {
  int T = 0;
  std::cin >> T;
  for (int i = 0; i<T; ++i) {
    int D = 0;
    std::cin >> D;
    
    std::vector<int> eaters(D);
    for (int j = 0; j<D; ++j)
      std::cin >> eaters[j];
    
    int maxNumber = 0;
    for (int j = 0; j<eaters.size(); ++j)
      maxNumber = std::max(maxNumber, eaters[j]);
    
    std::vector<int> specialTimes(maxNumber, maxNumber);
    for (int j = 1; j<specialTimes.size(); ++j) {
      specialTimes[j] = countSpecialTimes(eaters, j);
    }
    
    int bestTime = INT_MAX;
    for (int j = 0; j<specialTimes.size(); ++j)
      bestTime = std::min(bestTime, specialTimes[j] + j);
    
    std::cout << "Case #" << i+1 <<  ": " << bestTime << std::endl;
  }
}

int main(int argc, const char * argv[]) {
  //A();
  B();
  
  return 0;
}
