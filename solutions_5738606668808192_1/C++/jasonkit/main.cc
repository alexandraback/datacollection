#include <boost/multiprecision/cpp_int.hpp>
#include <ctime>
#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

#include "prime.h"

namespace mp = boost::multiprecision;

std::vector<int> computeFactorsForJamCoin(uint64_t jamcoin);
mp::cpp_int computeJamCoinInBaseN(uint64_t jamcoin, int base);
uint64_t generateJamCoinCandidate(int len);
std::string jamCoinInString(uint64_t jamcoin);
int main(int argc, char** argv);
int primeTest(mp::cpp_int n);

std::mt19937_64 generator;
std::uniform_int_distribution<uint64_t> distribution(0, ULONG_MAX);

uint64_t generateJamCoinCandidate(int len) {
  uint64_t midVal = distribution(generator) % ((uint64_t)(1 << (len - 2)));
  return ((uint64_t)1 << (len - 1)) | (midVal << 1) | 1;
}

int primeTest(mp::cpp_int n) {
  for (int i = 0; i < nPrime; i++) {
    if (n % primes[i] == 0 && n != primes[i]) {
      return primes[i];
    }
  }
  return 0;
}

void computeFactorsForJamCoin(uint64_t jamcoin, std::vector<int>& factors) {
  factors.clear();

  int factor = primeTest(jamcoin);
  if (!factor) {
    factors.clear();
    return;
  }

  factors.push_back(factor);

  for (int base = 3; base <= 10; base++) {
    mp::cpp_int jamCoinInBaseN = computeJamCoinInBaseN(jamcoin, base);
    factor = primeTest(jamCoinInBaseN);
    if (!factor) {
      factors.clear();
      return;
    }
    factors.push_back(factor);
  }
}

mp::cpp_int computeJamCoinInBaseN(uint64_t jamcoin, int base) {
  mp::cpp_int val = 0;
  mp::cpp_int weight = 1;
  while (jamcoin) {
    if (jamcoin & 1) {
      val += weight;
    }
    weight *= base;
    jamcoin >>= 1;
  }

  return val;
}

std::string jamCoinInString(uint64_t jamcoin) {
  std::string str;
  while (jamcoin) {
    if (jamcoin & 1) {
      str += "1";
    } else {
      str += "0";
    }
    jamcoin >>= 1;
  }

  int halfLen = str.length() >> 1;
  for (int i = 0; i < halfLen; i++) {
    char tmp = str[str.length() - i - 1];
    str[str.length() - i - 1] = str[i];
    str[i] = tmp;
  }
  return str;
}

int main(int argc, char** argv) {
  int T;
  std::cin >> T;

  srand(time(NULL));

  for (int t = 1; t <= T; t++) {
    std::unordered_set<uint64_t> jamcoins;
    std::unordered_set<uint64_t> notJamcoins;
    int N, J;
    std::cin >> N;
    std::cin >> J;

    std::cout << "Case #" << t << ":" << std::endl;
    for (int i = 0; i < J; i++) {
      while (true) {
        uint64_t candidate;
        std::vector<int> factors;

        do {
          candidate = generateJamCoinCandidate(N);
        } while (jamcoins.count(candidate) || notJamcoins.count(candidate));

        computeFactorsForJamCoin(candidate, factors);
        if (factors.size() == 0) {
          notJamcoins.insert(candidate);
          continue;
        }

        jamcoins.insert(candidate);

        std::cout << jamCoinInString(candidate);

#if 0
        std::cout << std::endl;
        std::cout << "base 2:" << candidate << std::endl;
        for (int j = 3; j <= 10; j++) {
          std::cout << "base " << j << " :"
                    << computeJamCoinInBaseN(candidate, j) << std::endl;
        }
#endif

        for (int j = 0; j < 9; j++) {
          std::cout << " " << factors[j];
        }
        std::cout << std::endl;
        break;
      }
    }
  }
  return 0;
}
