// {{{ C++ headers
#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <forward_list>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
/// }}}

class Problem {
public:
  Problem(int case_num) : case_num_(case_num) {}
  ~Problem() {}

  void Input();
  void Solve();
  void Output() const;

  static void Initialize();
  static void Finalize();

private:
  int case_num_;

  std::string name_;
  int n_;

  int64_t n_value_;
};

void Problem::Input() {
  std::cin >> name_ >> n_;
}

void Problem::Solve() {
  int length = static_cast<int>(name_.length());
  n_value_ = 0;
  for (int begin = 0; begin < length; begin++) {
    for (int end = begin + 1; end <= length; end++) {
      int c = 0;
      int m = 0;
      for (int i = begin; i < end; i++) {
        switch (name_[i]) {
          case 'a': case 'e': case 'i': case 'o': case 'u':
            m = std::max(m, c);
            c = 0;
            break;
          default:
            ++c;
            break;
        }
      }
      m = std::max(m, c);
      if (m >= n_) {
        ++n_value_;
      }
    }
  }
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << n_value_ << std::endl;
}

void Problem::Initialize() {
}

void Problem::Finalize() {
}

int main() {
  std::ios_base::sync_with_stdio(false);
  Problem::Initialize();
  int num_cases = 0;
  std::cin >> num_cases;
  for (int case_num = 1; case_num <= num_cases; case_num++) {
    Problem problem(case_num);
    problem.Input();
    problem.Solve();
    problem.Output();
  }
  Problem::Finalize();
}
