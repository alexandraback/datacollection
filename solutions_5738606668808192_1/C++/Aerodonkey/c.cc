#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string ToBinaryString(int num, int len) {
  std::string str(len, '0');
  for (int i = 0; i < len; i++) {
    str[len - i - 1] = char('0' + num % 2);
    num /= 2;
  }
  return str;
}

int Mod(int p, int q) {
  int r = p % q;
  if (r < 0) r += q;
  return r;
}

bool Check(int num, int len, std::vector<int>& factors) {
  int sum = 2;
  int even = 1 + (len % 2 == 0 ? 0 : 1);
  int odd = sum - even;
  for (int i = 1; i < len - 1; i++) {
    int bit = num % 2;
    num /= 2;
    if (bit == 1) {
      sum++;
      if (i % 2 == 1) {
        odd++;
      } else {
        even++;
      }
    }
  }
  int diff = even - odd;
  if (Mod(diff, 3) == 0) {
    factors[0] = 3;
  } else {
    return false;
  }
  if (Mod(sum, 2) == 0) {
    factors[1] = 2;
  } else if (Mod(diff, 2) == 0) {
    factors[1] = 2;
  } else {
    return false;
  }
  if (Mod(sum, 3) == 0) {
    factors[2] = 3;
  } else if (Mod(diff, 5) == 0) {
    factors[2] = 5;
  } else {
    return false;
  }
  if (Mod(sum, 2) == 0) {
    factors[3] = 2;
  } else if (Mod(diff, 2) == 0) {
    factors[3] = 2;
  } else if (Mod(diff, 3) == 0) {
    factors[3] = 3;
  } else {
    return false;
  }
  if (Mod(sum, 5) == 0) {
    factors[4] = 5;
  } else if (Mod(diff, 7) == 0) {
    factors[4] = 7;
  } else {
    return false;
  }
  if (Mod(sum, 2) == 0) {
    factors[5] = 2;
  } else if (Mod(sum, 3) == 0) {
    factors[5] = 3;
  } else if (Mod(diff, 2) == 0) {
    factors[5] = 2;
  } else {
    return false;
  }
  if (Mod(sum, 7) == 0) {
    factors[6] = 7;
  } else if (Mod(diff, 3) == 0) {
    factors[6] = 3;
  } else {
    return false;
  }
  if (Mod(sum, 2) == 0) {
    factors[7] = 2;
  } else if (Mod(diff, 2) == 0) {
    factors[7] = 2;
  } else if (Mod(diff, 5) == 0) {
    factors[7] = 5;
  } else {
    return false;
  }
  if (Mod(sum, 3) == 0) {
    factors[8] = 3;
  } else if (Mod(diff, 11) == 0) {
    factors[8] = 11;
  } else {
    return false;
  }
  return true;
}

int main() {
  int T;
  int N;
  int J;
  std::cin >> T >> N >> J;
  for (int i = 0; i < T; i++) {
    std::cout << "Case #" << (i + 1) << ":" << std::endl;
    int M = 1 << (N - 2);
    int j = 0;
    std::vector<int> factors(9);
    for (int m = 0; m < M; m++) {
      if (Check(m, N, factors)) {
        std::cout << '1' << ToBinaryString(m, N - 2) << '1';
        for (int f : factors) {
          std::cout << ' ' << f;
        }
        std::cout << std::endl;
        if (++j == J) {
          break;
        }
      }
    }
  }
}
