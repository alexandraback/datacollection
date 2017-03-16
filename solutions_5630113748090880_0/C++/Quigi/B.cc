// 2016 Round 1A, Problem B. Rank and File
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <string>
#include <vector>


static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

static int do_case() {
  std::vector<int> tally(2501);
  const int N = read_int();
  for (int j = (2*N-1) * N; j--; )
    ++tally[read_int()];
  for (int h = 1; h <= 2500; ++h)
    if (tally[h]&1)             // missing is odd
      std::cout << " " << h;
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
