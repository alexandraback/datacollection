#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>


void Fill(const std::string &s, size_t index, size_t answer, std::vector<size_t> &solutions) {
  if (index == s.size()) {
    solutions.push_back(answer);
    return;
  }
  if (s[index] != '?') {
    Fill(s, index + 1, (answer * 10) + s[index] - '0', solutions);
  } else {
    for (size_t i = 0; i <= 9; ++i) {
      Fill(s, index + 1, answer * 10 + i, solutions);
    }
  }
}

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    std::vector<size_t> s1_solutions, s2_solutions;
    Fill(s1, 0, 0, s1_solutions);
    Fill(s2, 0, 0, s2_solutions);

    size_t min_difference = 2e9;
    long long s1_ans, s2_ans;

    for (long long n1 : s1_solutions) {
      for (long long n2 : s2_solutions) {
        if (std::abs(n1 - n2) < min_difference) {
          min_difference = std::abs(n1 - n2);
          s1_ans = n1;
          s2_ans = n2;
        }
      }
    }

    std::cout << "Case #" << t << ": " << std::setfill('0') << std::setw(s1.length()) << s1_ans << " " << std::setfill('0') << std::setw(s1.length()) << s2_ans << "\n";
  }
  return 0;
}
