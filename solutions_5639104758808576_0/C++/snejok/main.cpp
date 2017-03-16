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
int main(int argc, const char * argv[]) {
  A();
  
  return 0;
}
