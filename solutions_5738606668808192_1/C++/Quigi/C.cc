// 2016 Qualification Round.  Problem C. Coin Jam
// Copyright 2016 Christian Brechbuehler alias Quigi
// $Id: C.cc,v 1.5 2016/04/09 14:11:39 brech Exp $
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <stdint.h>
#include <cmath>
#include <iostream>
#include <vector>


static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

typedef std::vector<int> VI;

// if yes, return a factor
static int divisible(const VI& coin_digit, const int base) {
  const static int prime[] = {
    2, 3, 7, 5, 11, 13, 17, 43, 31, 37, 73, 19, 23, 29, 41, 71, 47, 101,
    53, 61, 83, 67, 149, 59, 239, 317, 79, 89, 131, 103, 113, 157
  };
  for (int p : prime) {
    int mod = 0;                // coin % p
    for (int d : coin_digit)
      mod  = (base*mod  + d) % p;
    if (!mod) return p;         // we found a divisor
  }
  return 0;                     // may be prime
}

// whether coin is non-prime in any base
static int valid(const VI& coin, VI::iterator factor) {
  for (int j_base = 2; j_base <= 10; ++j_base) {
    factor[j_base] = divisible(coin, j_base);
    if (factor[j_base] <= 0) return 0; // may be prime
  }
  return 1;
}

static void do_case() {
  const int N = read_int(), J = read_int();
  VI digit(N);
  digit[0] = digit[N-1] = 1;
  // a handful of assorted primes to try as potential divisors.
  for (int j = J; j;) {
    VI divisor(9); // [0] for 2,.. [8] for 10
    if (valid(digit, divisor.begin()-2)) {
      for (int dig : digit  ) std::cout <<        dig;
      for (int div : divisor) std::cout << " " << div;
      std::cout << std::endl;
      --j;
    }
    // advance to next candiate coin:
    for (int j_d = N-1; !(digit[--j_d] ^= 1); ) {
      if (j && ! j_d) {
        std::cerr << "bug: " << j << " coins missing." << std::endl;
        return;
      }
    }
  }
}

int main() {
  const int T = read_int();
  for (int j = 1; j <= T; ++j) {
    std::cout << "Case #" << j << ":"<< std::endl;
    do_case();
  }
  return 0;
}
