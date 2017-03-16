#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <array>

class CoinGenerator {
 public:
  static std::string generateCoin(long long middleNumber, unsigned middleN) {
    std::string coin = "1";

    while(middleNumber > 0) {
      if (middleNumber % 2 == 0)
        coin.push_back('0');
      else
        coin.push_back('1');
      middleNumber /= 2;
    }

    while(coin.size() < middleN + 1)
      coin.push_back('0');

    coin.push_back('1');
    return coin;
  }
};

class PrimeChecker {
 public:
  static int checkPrime(long long n) {
    if (n % 2 == 0)
      return 2;

    for(int i = 3; i < std::sqrt(n) + 1; i += 2) {
      if(n % i == 0)
        return i;
    }

    return 0;
  }
};

class NumberBaseGenerator {
 public:
  static long long generateFromCoin(const std::string& s, unsigned base) {
    long long number = 0;
    long long multiplier = 1;
    for (int p = s.size()-1; p >= 0; --p) {
      if(s.at(p) == '1')
       number += multiplier;
      multiplier *= base;
    }
    return number;
  }
};

int main() {
  int T;
  std::cin >> T;

  for (int i=0; i<T; ++i) {
    int N;
    int J;
    std::cin >> N;
    std::cin >> J;

    int middleN = N-2;

    std::cout << "Case #" << i+1 << ":" << std::endl;

    /*
    long long maxMiddleNumber = (1 << middleN) - 1;
    for(long long i = 0; i <= maxMiddleNumber; ++i) {
      std::string coin = CoinGenerator::generateCoin(i, middleN);
      std::cout << coin << std::endl;
      for (unsigned b = 2; b <= 10; ++b) {
        auto number = NumberBaseGenerator::generateFromCoin(coin,b);
        std::cout << " Base " << b << ": " << number;
        auto div = PrimeChecker::checkPrime(number);
        if (div == 0)
          std::cout << " --> prime! ";
        else
          std::cout << " div: " << div;
        std::cout << std::endl;
      }
    }
    */

    long long middleNumber = 0;
    std::array<int,11> divisors;
    while (J > 0) {
      std::string coin = CoinGenerator::generateCoin(middleNumber, middleN);
      bool isJamCoin = true;
      for (unsigned b = 2; b <= 10; ++b) {
        auto number = NumberBaseGenerator::generateFromCoin(coin,b);
        divisors[b] = PrimeChecker::checkPrime(number);
        if (divisors[b] == 0) {
          isJamCoin = false;
          break;
        }
      }

      if(isJamCoin) {
        --J;
        std::cout << coin;
        for (unsigned b = 2; b <= 10; ++b) {
          std::cout << " " << divisors[b];
        }
        std::cout << std::endl;
      }
      middleNumber++;
    }
  }

  return 0;
}
