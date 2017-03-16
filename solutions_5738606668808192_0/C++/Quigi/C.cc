// 2016 Qualification Round.  Problem C. Coin Jam
// Copyright 2016 Christian Brechbuehler alias Quigi
// $Id: C.cc,v 1.2 2016/04/09 03:55:26 brech Exp $
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
static int divisible(int64_t n, const VI &prime) {
  for (int i : prime) {
    if (n % i == 0) return i;
    if (i * i > n) return 0;
  }
  std::cerr << "warning: exhausted primes" << std::endl;
  return -1;                     // meaning there's a bug
}

// whether coin is non-prime in any base
static int valid(const VI& coin_digit, VI::iterator factor, const VI &prime) {
  for (int j_base = 2; j_base <= 10; ++j_base) {
    int64_t coin = 0;             // interpreted in this base
    for (int i_d : coin_digit)
      coin = j_base*coin + i_d; // OR: update interpretation in all bases
    factor[j_base] = divisible(coin, prime);
    if (factor[j_base] <= 0)    // if we exhaust our divisors, it might be prime
      return 0;
  }
  return 1;
}


static void primes_to(double x, VI* prime) {
  // Upper limit of pi(x), the number of primes <= x
  const double kDusart = (x/log(x)) * (1 + 1.2762/log(x));
  prime->reserve(static_cast<int>(kDusart));
  prime->push_back(2);
  prime->push_back(3);
  for (int cand = 5, inc = 4; cand < x; cand += (inc ^= 6))
    if (! divisible(cand, *prime)) {
      prime->push_back(cand);
    }
}

static void do_case() {
  const int N = read_int(), J = read_int();
  VI digit(N);
  digit[0] = digit[N-1] = 1;
  VI prime;
  primes_to(exp10(N/2.0)/3.0, &prime); // sqrt of largest coin, decimal all ones
  for (int j = J; j;) {
    VI divisor(9); // [0] for 2,.. [8] for 10
    if (valid(digit, divisor.begin()-2, prime)) {
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
