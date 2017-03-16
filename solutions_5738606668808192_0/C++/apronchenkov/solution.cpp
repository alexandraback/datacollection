#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

struct JamCoin {
  unsigned long coin;
  std::array<unsigned long, 9> witnesses;
};

template <typename T>
std::string toBinaryString(T value) {
  std::string result;
  do {
    result.push_back('0' + value % 2);
    value /= 2;
  } while (value > 0);
  std::reverse(result.begin(), result.end());
  return result;
}

bool ValidateJamCoin(unsigned long coin, int base, unsigned long witness) {
  long remainder = 0;
  auto bit = 1UL << (8 * sizeof(coin) - 2);
  for (; bit; bit >>= 1) {
    remainder *= base;
    if (coin & bit) {
      ++remainder;
    }
    remainder %= witness;
  }
  return remainder == 0;
}

bool ValidateJamCoin(const JamCoin& jamCoin) {
  for (size_t i = 0; i < jamCoin.witnesses.size(); ++i) {
    if (!ValidateJamCoin(jamCoin.coin, i + 2, jamCoin.witnesses[i])) {
      return false;
    }
  }
  return true;
}

std::vector<JamCoin> generateJamCoins(int length, size_t numberOfCoins) {
  std::vector<JamCoin> result;
  unsigned long coin = 3 * (((1UL << (length - 1)) + 2) / 3);
  if (coin % 2 == 0) {
    coin += 3;
  }
  for (; result.size() < numberOfCoins; coin += 6) {
    const JamCoin jamCoin{
        coin, {{3, 2, 5, 2, 7, 2, 3, 2, 11}},
    };
    if (ValidateJamCoin(jamCoin)) {
      result.push_back(jamCoin);
    }
  }
  return result;
}

int main() {
  int numberOfCases;
  std::cin >> numberOfCases;
  for (int caseNo = 0; caseNo < numberOfCases; ++caseNo) {
    int n, j;
    std::cin >> n >> j;
    std::cout << "Case #" << caseNo + 1 << ":\n";
    for (const auto& jamcoin : generateJamCoins(n, j)) {
      std::cout << toBinaryString(jamcoin.coin);
      for (const auto& witness : jamcoin.witnesses) {
        std::cout << ' ' << witness;
      }
      std::cout << '\n';
    }
  }
  return 0;
}
