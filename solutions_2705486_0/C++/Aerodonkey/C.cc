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
#include <fstream>
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

  std::string string_;

  int min_changed_letters_;

  static const int kMaxWordLength = 10;
  static const int kMinChangedIndexDiff = 5;

  static std::vector<std::string> dict_;
};

std::vector<std::string> Problem::dict_;

void Problem::Input() {
  std::cin >> string_;
}

void Problem::Solve() {
  int length = static_cast<int>(string_.length());
  std::vector<std::vector<int>> min(length + 1);
  for (int i = 0; i <= length; i++) {
    min[i].resize(std::min(i + 1, kMinChangedIndexDiff), std::numeric_limits<int>::max());
  }
  min[0][0] = 0;
  for (int i = 1; i <= length; i++) {
    for (const std::string& word : dict_) {
      int word_length = static_cast<int>(word.length());
      if (i < word_length) {
        continue;
      }
      int j = i - word_length;
      std::vector<int> diff_indices;
      for (int k = 0; k < word_length; k++) {
        int p = j + k;
        if (string_[p] != word[k]) {
          if (!diff_indices.empty() && p - diff_indices.back() < kMinChangedIndexDiff) {
            goto next_word;
          }
          diff_indices.push_back(p);
        }
      }
      for (int k = 0; k < static_cast<int>(min[j].size()); k++) {
        if (k > 0 && !diff_indices.empty() && diff_indices.front() - (j - k) < kMinChangedIndexDiff) {
          continue;
        } else if (min[j][k] == std::numeric_limits<int>::max()) {
          continue;
        }
        int p = 0;
        if (!diff_indices.empty()) {
          p = diff_indices.back();
        } else {
          if (k > 0) {
            p = j - k;
          } else {
            p = -1;
          }
        }
        p = i - p;
        if (p >= kMinChangedIndexDiff) {
          p = 0;
        }
        min[i][p] = std::min(min[i][p], min[j][k] + static_cast<int>(diff_indices.size()));
      }
next_word:
      ;
    }
  }
  min_changed_letters_ = *std::min_element(min[length].begin(), min[length].end());
}

void Problem::Output() const {
  std::cout << "Case #" << case_num_ << ": " << min_changed_letters_ << std::endl;
}

void Problem::Initialize() {
  std::ifstream dict_file("garbled_email_dictionary.txt");
  std::string word;
  while (dict_file >> word) {
    dict_.push_back(word);
  }
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
