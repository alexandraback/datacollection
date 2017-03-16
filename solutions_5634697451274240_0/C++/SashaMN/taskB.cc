// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

int GetAns(const std::string & s) {
  int result = 0;
  for (int i = 0; i + 1 < s.length(); ++i) {
    if (s[i] != s[i + 1]) {
      ++result;
    }
  }
  if (s.back() == '-') {
    ++result;
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::string s;
    std::cin >> s;
    std::cout << "Case #" << i + 1 << ": " << GetAns(s) << std::endl;
  }
  return 0;
}

