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
  struct Tribe {
    int day0;
    int num_attacks;
    int west0;
    int east0;
    int strength0;
    int delta_day;
    int delta_pos;
    int delta_str;
  };

  int case_num_;

  int num_tribes_;
  std::vector<Tribe> tribes_;

  int num_successful_attacks_;
};

void Problem::Input() {
  std::cin >> num_tribes_;
  tribes_.resize(num_tribes_);
  for (int i = 0; i < num_tribes_; i++) {
    std::cin >> tribes_[i].day0;
    std::cin >> tribes_[i].num_attacks;
    std::cin >> tribes_[i].west0;
    std::cin >> tribes_[i].east0;
    std::cin >> tribes_[i].strength0;
    std::cin >> tribes_[i].delta_day;
    std::cin >> tribes_[i].delta_pos;
    std::cin >> tribes_[i].delta_str;
  }
}

void Problem::Solve() {
  std::unordered_map<int, int> wall;
  num_successful_attacks_ = 0;
  for (int day = 0; day <= 676060; day++) {
    for (int tribe_num = 0; tribe_num < num_tribes_; tribe_num++) {
      const Tribe& tribe = tribes_[tribe_num];
      int day_diff = day - tribe.day0;
      if (!(day_diff >= 0 && day_diff < tribe.num_attacks * tribe.delta_day && day_diff % tribe.delta_day == 0)) {
        continue;
      }
      int attack_num = day_diff / tribe.delta_day;
      bool success = false;
      int east = tribe.east0 + attack_num * tribe.delta_pos;
      int west = tribe.west0 + attack_num * tribe.delta_pos;
      int strength = tribe.strength0 + attack_num * tribe.delta_str;
      for (int pos = west; pos < east; pos++) {
        if (wall[pos] < strength) {
          success = true;
        }
      }
      if (success) {
        ++num_successful_attacks_;
      }
    }
    for (const Tribe& tribe : tribes_) {
      int day_diff = day - tribe.day0;
      if (!(day_diff >= 0 && day_diff < tribe.num_attacks * tribe.delta_day && day_diff % tribe.delta_day == 0)) {
        continue;
      }
      int attack_num = day_diff / tribe.delta_day;
      int east = tribe.east0 + attack_num * tribe.delta_pos;
      int west = tribe.west0 + attack_num * tribe.delta_pos;
      int strength = tribe.strength0 + attack_num * tribe.delta_str;
      for (int pos = west; pos < east; pos++) {
        wall[pos] = std::max(wall[pos], strength);
      }
    }
  }
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << num_successful_attacks_ << std::endl;
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
