// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

void PrintDeque(const std::deque<char> & to_print) {
  for (char c : to_print) {
    std::cout << c;
  }
  std::cout << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    std::string s;
    std::cin >> s;
    std::deque<char> ans;
    ans.push_back(s[0]);
    for (int j = 1; j < s.length(); ++j) {
      if (s[j] >= ans[0]) {
        ans.push_front(s[j]);
      } else {
        ans.push_back(s[j]);
      }
    }
    std::cout << "Case #" << i + 1 << ": ";
    PrintDeque(ans);
  }
  return 0;
}

