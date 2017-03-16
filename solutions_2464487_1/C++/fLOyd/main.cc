#include <iostream>
#include <algorithm>
#include <cmath>

long long solve() {
  long long r, t, left, right, k;
  std::cin >> r >> t;
  left = 1; right = std::min(sqrt(2 * t) / 2 + 1,
                             1000000000000000000.0 / (2 * r - 1));
  while (left < right) {
    k = (left + right) / 2 + 1;
    long long res = 2 * k * k + (2 * r - 1) * k;
    if (res >= 0 &&  res <= t) {
      left = k;
    } else {
      right = k - 1;
    }
  }
  return left;
}

int main(int argc, char *argv[]) {
  int T;
  std::cin >> T;
  for (int i = 1; i <= T; ++i) {
    std::cout << "Case #" << i << ": " << solve() << "\n";
  }
  return 0;
}
