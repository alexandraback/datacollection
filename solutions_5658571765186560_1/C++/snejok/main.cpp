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
#include <sstream>

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


typedef std::pair<int, char> q;
q mq(int sign, char ch) { return std::make_pair(sign,ch); }

int idx(char ch)
{
  switch (ch){
    case '1': return 0;
    case 'i': return 1;
    case 'j': return 2;
    case 'k': return 3;
  }
  
  return -1;
}
q mul(const q& q1, const q& q2) {
  static const q qs[][4] = {
    { mq(1, '1'), mq(1, 'i'),  mq(1,'j'),   mq(1,'k') },
    { mq(1, 'i'), mq(-1,'1'),  mq(1, 'k'),  mq(-1, 'j') },
    { mq(1, 'j'), mq(-1, 'k'), mq(-1, '1'), mq(1, 'i') },
    { mq(1, 'k'), mq(1, 'j'),  mq(-1, 'i'), mq(-1, '1') }
  };
  
  q res = qs[idx(q1.second)][idx(q2.second)];
  return mq(q1.first * q2.first * res.first, res.second);
}

q prod(const std::string& str) {
  q res = mq(1, '1');
  for (size_t i = 0; i<str.size(); ++i)
    res = mul(res, mq(1, str[i]));
  
  return res;
}

q power(const q& q1, long pow) {
  if (pow == 1)
    return q1;
  
  q tmp = power(q1, pow / 2);
  tmp = mul(tmp, tmp);
  if (pow % 2)
    tmp = mul(tmp, q1);
  
  return tmp;
}

void printAnswer(int c, const char* msg) {
  std::cout << "Case #" << c <<  ": " << msg << std::endl;
}

void C() {
  int T = 0;
  std::cin >> T;
  
  for (int i = 0; i<T; ++i) {
    int L; long X;
    std::cin >> L >> X;
    
    std::string str;
    std::cin >> str;
    
    q blockProd = prod(str);
    q blockPow = power(blockProd, X);
    if (blockPow.first > 0 || blockPow.second != '1') {
      printAnswer(i+1, "NO");
      continue;
    }
    
    X = std::min<long>(X, 6);
    std::string concatenation = "";
    std::stringstream s;
    for (int j = 0; j<X; ++j)
      s << str;
    concatenation = s.str();
    
    int idxToFind = 1;
    q curRes = mq(1, '1');
    for (int j = 0; j<concatenation.size(); ++j) {
      q ch = mq(1,concatenation[j]);
      curRes = mul(curRes, ch);
      if (curRes.first > 0 && idx(curRes.second) == idxToFind) {
        if (idxToFind == 3) {
          printAnswer(i+1, "YES");
          ++idxToFind;
          break;
        } else {
          curRes = mq(1,'1');
        }
        ++idxToFind;
      }
    }
    
    if (idxToFind != 4) {
      printAnswer(i+1, "NO");
    }
  }
}


void D() {
  int T = 0;
  std::cin >> T;
  
  for (int i = 0; i<T; ++i) {
    int X, R, C;
    std::cin >> X >> R >> C;
    
    
    bool anySideGreater = false;
    for (int j = 1; j<X; ++j) {
      if ((j > R || X-j+1 > C) && (j > C || X-j+1 > R))
        anySideGreater = true;
    }
    if (R * C % X || anySideGreater)
      printAnswer(i+1, "RICHARD");
    else {
      if (X == R * C / 2 && (!(R%2) || !(C%2)) && (R>=4 || C>=4) && (R!=1 && C!=1))
        printAnswer(i+1, "RICHARD");
      else
        printAnswer(i+1, "GABRIEL");
    }
  }
}

int main(int argc, const char * argv[]) {
  //A();
  //B();
  //C();
  D();
  return 0;
}
