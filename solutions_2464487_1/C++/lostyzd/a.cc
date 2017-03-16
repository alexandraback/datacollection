#include <iostream>

int main() {
  int T;
  std::cin >> T;
  for (int test = 1; test <= T; ++test) {
    unsigned long long r, t;
    std::cin >> r >> t;

    unsigned long long left = 1, right = 1414213563;
    while (left < right) {
      unsigned long long mid = ((right - left) >> 1) + left;

      if (t / (2 * r) + 1 <= mid) {
        right = mid;
        continue;
      }

      unsigned long long x = (2 * r + 2 * mid - 1) * mid;
      if (x < t) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (t < ((2 * r + 2 * left - 1) * left)) --left;

    std::cout << "Case #" << test << ": " << left << std::endl;
  }
}
