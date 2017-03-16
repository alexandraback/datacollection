#include <iostream>
#include <vector>

int main() {
  int number_of_tests;
  std::cin >> number_of_tests;
  for (int test_index = 0; test_index < number_of_tests; ++test_index) {
    long long b, m;
    std::cin >> b >> m;
    long long sum = 1;
    std::cout << "Case #" << test_index + 1 << ": ";
    if ((1LL << (b - 2)) < m) {
      std::cout << "IMPOSSIBLE" << std::endl;
      continue;
    } else {
      std::cout << "POSSIBLE" << std::endl;
    }
    bool flag = ((1LL << (b - 2)) == m);
    for (int i = 0; i < b; ++i) {
      std::cout << '0';
      for (int j = 1; j + 1 < b; ++j) {
        std::cout << (j > i);
      }
      if (i + 1 < b && (flag || (i > 0 && (m & (1LL << (i - 1)))))) {
        std::cout << '1';
      } else {
        std::cout << '0';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
