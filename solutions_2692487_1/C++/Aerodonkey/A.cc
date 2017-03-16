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

  int initial_size_;
  int num_motes_;
  std::vector<int> sizes_;

  int num_operations_;
};

void Problem::Input() {
  std::cin >> initial_size_ >> num_motes_;
  sizes_.resize(num_motes_);
  for (int i = 0; i < num_motes_; i++) {
    std::cin >> sizes_[i];
  }
}

void Problem::Solve() {
  std::sort(sizes_.begin(), sizes_.end());
  num_operations_ = num_motes_;
  int current_size = initial_size_;
  int num_add_operations = 0;
  for (int i = 0; i < num_motes_; i++) {
    if (current_size <= 1) {
      break;
    }
    while (current_size <= sizes_[i]) {
      current_size += current_size - 1;
      ++num_add_operations;
    }
    current_size += sizes_[i];
    num_operations_ = std::min(num_operations_, num_add_operations + (num_motes_ - i - 1));
  }
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << num_operations_ << std::endl;
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
