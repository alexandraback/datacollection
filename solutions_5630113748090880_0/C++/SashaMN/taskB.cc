// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(2 * n - 1, std::vector<int>(n));
    std::map<int, int> counter;
    for (int i = 0; i < 2 * n - 1; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> a[i][j];
        ++counter[a[i][j]];
      }
    }
    std::vector<int> ans;
    for (const auto & item : counter) {
      if (item.second % 2 == 1) {
        ans.push_back(item.first);
      }
    }
    std::cout << "Case #" << tt + 1 << ": ";
    for (int elem : ans) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

