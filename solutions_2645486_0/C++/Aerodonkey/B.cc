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

  int energy_;
  int regain_;
  int num_activities_;
  std::vector<int> values;

  int64_t max_gain_;
};

void Problem::Input() {
  std::cin >> energy_ >> regain_ >> num_activities_;
  values.resize(num_activities_);
  for (int i = 0; i < num_activities_; i++) {
    std::cin >> values[i];
  }
}

void Problem::Solve() {
  std::vector<int64_t> last_gain(energy_ + 1, -1);
  std::vector<int64_t> this_gain(energy_ + 1);
  last_gain[energy_] = 0;
  for (int i = 0; i < num_activities_; i++) {
    std::swap(this_gain, last_gain);
    std::fill(this_gain.begin(), this_gain.end(), -1);
    for (int e = 0; e <= energy_; e++) {
      int64_t v = last_gain[e];
      if (v < 0) {
        continue;
      }
      for (int s = 0; s <= e; s++) {
        int64_t u = v + (e - s) * values[i];
        int r = std::min(s + regain_, energy_);
        this_gain[r] = std::max(this_gain[r], u);
      }
    }
  }
  max_gain_ = *std::max_element(this_gain.begin(), this_gain.end());
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << max_gain_ << std::endl;
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
