#include <array>
#include <cassert>
#include <iostream>


long long sheepNumber (int n) {
  assert(n > 0);

  std::array<bool, 10> digits {};
  int digitsLeft = 10;

  for (long long number = n;; number += n) {
    for (int k = number; k; k /= 10) {
      int digit = k % 10;

      if (digits[digit]) {
        continue;
      }

      digits[digit] = true;

      if (!--digitsLeft) {
        return number;
      }
    }
  }
}


int main () {
  int T;

  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    int n;

    std::cin >> n;
    std::cout << "Case #" << t << ": ";

    if (n > 0) {
      std::cout << sheepNumber(n) << '\n';
    }
    else {
      std::cout << "INSOMNIA\n";
    }
  }
}
