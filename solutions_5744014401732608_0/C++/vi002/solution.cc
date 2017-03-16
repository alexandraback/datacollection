#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

bool Build(int b, int64_t m, std::vector<std::vector<bool>> &graph) {
  std::vector<uint64_t> counts(b);
  counts[0] = 1;
  for (int i = 1; i < b; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (counts[i] + counts[j] <= m) {
        counts[i] += counts[j];
        graph[j][i] = true;
      }
    }
  }
  return counts[b - 1] == m;
}

int main() {
  int num_tests;
  std::cin >> num_tests;
  for (int test_num = 0; test_num < num_tests; ++test_num) {
    int b;
    uint64_t m;
    std::cin >> b >> m;

    std::vector<std::vector<bool>> graph(b, std::vector<bool>(b, false));

    std::cout << "Case #" << (test_num + 1) << ": ";
    if (!Build(b, m, graph)) {
      std::cout << "IMPOSSIBLE" << std::endl;
      continue;
    }

    std::cout << "POSSIBLE" << std::endl;
    for (int i = 0; i < b; ++i) {
      for (int j = 0; j < b; ++j) {
        if (graph[i][j])
          std::cout << "1";
        else
          std::cout << "0";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
