#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<iterator>
#include <algorithm>

struct solver_2016_q_b {
  int run(std::string S) {
    // top ... bottom
    // std::cerr << flip(S, 0) << std::endl;
    int cnt_chg = count_change(S);
    if((*S.rbegin()) == '+') {
      return cnt_chg;
    }else{
      return cnt_chg + 1;
    }

    return 0;
  }

  int count_change(std::string str) {
    int cnt = 0;
    std::string::iterator it = str.begin();
    char before = *it;
    ++it;
    for(; it != str.end(); ++it) {
      if(before != *it) ++cnt;
      before = *it;
    }
    return cnt;
  }

  /*
  std::string flip(std::string str, int i) {
    ++i;
    std::string before, after, before_flip = "";
    before = str.substr(0, i);
    after = str.substr(i);
    std::reverse(before.begin(), before.end());
    for(std::string::iterator it = before.begin(); it != before.end(); ++it) {
      before_flip += (*it == '-') ? '+' : '-';
    }
    return before_flip + after;
  }

  int count_hapy_from_back(std::string str) {
    int i = 0;
    for(std::string::iterator it = str.rbegin(); it != str.rend(); ++it) {
      if(*it == '+') {
        ++i;
      }else{
        break;
      }
    }
    return i;
  }

  bool ok(std::string str) {
    int num_happy = count_hapy_from_back(str);
    if(str.size() == num_happy) return true;
    return false;
  }
  */

};

int main(void) {
  solver_2016_q_b solver;

  int T;
  std::string S;

  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    std::cin >> S;
    std::cout << "Case #" << (i + 1) << ": " << solver.run(S) << std::endl;
  }

  return 0;
}
