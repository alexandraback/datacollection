#include <iostream>
#include <iterator>
#include <vector>


int main () {
  int T;
  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    int k, c, s;
    std::cin >> k >> c >> s;
    std::cout << "Case #" << t << ':';

    if (c * s < k) {
      std::cout << " IMPOSSIBLE\n";
      continue;
    }

    long long num = 0;
    long long power = 1;
    int digit = 0;

    // Build C-digit K-based numbers so that each digit is featured at least
    // once.
    while (digit < k) {
      num += digit * power;

      if (++digit % c) {
        power *= k;
      }
      else {
        std::cout << ' ' << num + 1;
        power = 1;
        num = 0;
      }
    }

    if (k % c) {
      std::cout << ' ' << num + 1;
    }

    std::cout << '\n';
  }
}
