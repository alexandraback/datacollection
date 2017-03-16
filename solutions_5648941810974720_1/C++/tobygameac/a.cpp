#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

size_t digit[10] = {0, 2, 6, 8, 3, 4, 7, 5, 1, 9};
char target[10] = {'Z', 'W', 'X', 'G', 'H', 'R', 'S', 'V', 'O', 'N'};
std::string alphabets[10] = {"ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR", "SEVEN", "FIVE", "ONE", "NINE"};

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    std::string s;
    std::cin >> s;
    std::map<char, size_t> char_count;
    for (char c : s) {
      ++char_count[c];
    }
    std::vector<size_t> answer;
    for (size_t i = 0; i < 10; ++i) {
      while (char_count[target[i]] > 0) {
        for (size_t j = 0; alphabets[i][j]; ++j) {
          --char_count[alphabets[i][j]];
        }
        answer.push_back(digit[i]);
      }
    }
    std::sort(answer.begin(), answer.end());
    std::cout << "Case #" << t << ": ";
    for (int n : answer) {
      std::cout << n;
    }
    std::cout << "\n";
  }
  return 0;
}
