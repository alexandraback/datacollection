#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

// #include <gtest/gtest.h>

/**
 *

 7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE

Case #1: CAB
Case #2: MJA
Case #3: OCDE
Case #4: BBAAA
Case #5: CCCABBBAB
Case #6: CCCBAABAB
Case #7: ZXCASDQWE

 */

using namespace std;

void solve(std::string line) {
  char last=line[0];
  std::string ret;
  for (char c : line) {
    if (last <= c) {
      ret = c + ret;
      last = c;
    } else {
      ret = ret + c;
    }
  }
  cout << ret  << "\n";
}

int main(int argc, char* argv[]) {
  int t;
  std::cin >> t;
  std::string line;
  getline(std::cin, line);
  for (int i=0;i<t;i++) {
    cout << "Case #" << i+1 << ": ";
    getline(std::cin, line);
    solve(line);
  }
  
  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();
}
