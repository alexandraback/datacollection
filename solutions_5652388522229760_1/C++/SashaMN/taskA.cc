// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

std::vector<int> GetDigits(int64_t number) {
  std::vector<int> result;
  while (number > 0) {
    result.push_back(number % 10);
    number /= 10;
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int64_t n;
    std::cin >> n;
    if (n == 0) {
      std::cout << "Case #" << i + 1 << ": " << "INSOMNIA" << std::endl;
      continue;
    }
    std::set<int> all_digits;
    int64_t cur_value = n;
    while (true) {
      const std::vector<int> digits = GetDigits(cur_value);
      all_digits.insert(digits.begin(), digits.end());
      if (all_digits.size() == 10) {
        break;
      }
      cur_value += n;
    }
    std::cout << "Case #" << i + 1 << ": " << cur_value << std::endl;
  }
  return 0;
}

