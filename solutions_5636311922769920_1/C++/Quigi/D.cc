// 2016 Qualification Round.  Problem D. Fractiles
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <stdint.h>             // for int64_t

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

static void do_case() {
  const int K = read_int(), C = read_int(), S = read_int();
  if (S * C < K) {              // each student can cover C original tiles
    std::cout << " IMPOSSIBLE";
    return;
  }
  for (int j_k = 0; j_k < K;) { // test original tile j_k, base 0
    int64_t tile = j_k;         // final tile to clean, base 0
    for (int j_c = 1; j_c < C; j_c++) {
      if (j_k +1 < K) ++j_k;
      tile = K*tile + j_k;
    }
    ++j_k;
    std::cout << " " << tile+1;
  }
}

int main() {
  const int T = read_int();
  for (int j = 1; j <= T; ++j) {
    std::cout << "Case #" << j << ":";
    do_case();
    std::cout << std::endl;
  }
  return 0;
}
