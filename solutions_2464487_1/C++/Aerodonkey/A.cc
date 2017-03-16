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

#include <gmpxx.h>

template <class T>
std::string ToString(T value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

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

  int64_t radius_;
  int64_t paint_;
  int64_t num_black_rings_;
};

void Problem::Input() {
  std::cin >> radius_ >> paint_;
}

void Problem::Solve() {
  mpz_class r(ToString(radius_));
  mpz_class t(ToString(paint_));
  mpz_class x = 2 * r - 1;
  mpz_class k = (sqrt(x * x + 8 * t) - x) / 4;
  num_black_rings_ = k.get_si();
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << num_black_rings_ << std::endl;
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
