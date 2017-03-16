// 2016 Round 1C, Problem B
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <algorithm>

static long read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

typedef std::vector<int> VI;

static void do_case() {
  const long B = read_int(), M = read_int();
  const long max = 1L << B-2;
  if (M > max) {
    std::cout << "IMPOSSIBLE";
    return;
  }
  std::cout << "POSSIBLE";
  const long m = 2*M - (M == max);
  for (int i = 0; i < B; ++i) {
    std::cout << std::endl;
    for (int j = 0; j < B-1; ++j)
      std::cout << (j > i);
    std::cout << ((m>>i)&1);
  }
}

int main() {
  const int T = read_int();
  for (int j = 1; j <= T; ++j) {
    std::cout << "Case #" << j << ": ";
    do_case();
    std::cout << std::endl;
  }
  return 0;
}
