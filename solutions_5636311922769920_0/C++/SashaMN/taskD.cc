// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

void PrintInt64Vector(const std::vector<int64_t> & to_print) {
  for (int64_t elem : to_print) {
    std::cout << elem + 1 << " ";
  }
  std::cout << std::endl;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int64_t k, c, s;
    std::cin >> k >> c >> s;
    std::vector<int64_t> positions(k);
    std::iota(positions.begin(), positions.end(), 0);
    for (int j = 0; j < c - 1; ++j) {
      for (int u = 0; u < k; ++u) {
        positions[u] = u + k * positions[u];
      }
    }
    std::cout << "Case #" << i + 1 << ": ";
    PrintInt64Vector(positions);
  }
  return 0;
}

