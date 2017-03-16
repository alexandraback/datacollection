// 2016 Qualification Round.  Problem A. Counting Sheep
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <sstream>


static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

static void do_case() {
  const int N = read_int();
  std::vector<int> seen(10);
  int need = 10;
  for (int j = N; j > 0; j += N) {
    std::ostringstream decimal;
    decimal << j;
    for (const char digit : decimal.str()) {
      need -= !seen[digit-'0']++;
    }
    if (!need) {
      std::cout << j;
      return;
    }
  }
  std::cout << "INSOMNIA";
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
