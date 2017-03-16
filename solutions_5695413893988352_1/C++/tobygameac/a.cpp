#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

size_t min_difference;
std::string s1_answer, s2_answer;

void Solve(std::string s1, std::string s2, size_t index, long long s1_value, long long s2_value) {
  if (!s1[index]) {
    size_t difference = std::abs(s1_value - s2_value);
    if (difference < min_difference) {
      min_difference = difference;
      s1_answer = s1;
      s2_answer = s2;
    }
    return;
  }

  if (s1_value < s2_value) {
    s1[index] = s1[index] == '?' ? '9' : s1[index];
    s2[index] = s2[index] == '?' ? '0' : s2[index];
  }

  if (s2_value < s1_value) {
    s1[index] = s1[index] == '?' ? '0' : s1[index];
    s2[index] = s2[index] == '?' ? '9' : s2[index];
  }

  if (s1[index] == '?' && s2[index] == '?') {
    s1[index] = s2[index] = '0';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
    s1[index] = '0';
    s2[index] = '1';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
    s1[index] = '1';
    s2[index] = '0';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
  } else if (s1[index] == '?') {
    s1[index] = s2[index];
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
    s1[index] = ((s2[index] - '0') - 1 + 10) % 10 + '0';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
    s1[index] = ((s2[index] - '0') + 1) % 10 + '0';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
  } else if (s2[index] == '?') {
    s2[index] = s1[index];
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
    s2[index] = ((s1[index] - '0') - 1 + 10) % 10 + '0';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
    s2[index] = ((s1[index] - '0') + 1) % 10 + '0';
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
  } else {
    Solve(s1, s2, index + 1, s1_value * 10 + s1[index] - '0', s2_value * 10 + s2[index] - '0');
  }
}

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    min_difference = (long long)1 << 50;
    Solve(s1, s2, 0, 0, 0);
    std::cout << "Case #" << t << ": " << s1_answer << " " << s2_answer << "\n";
  }
  return 0;
}
