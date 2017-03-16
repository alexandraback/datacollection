// 2016 qualification round. Problem B. Revenge of the Pancakes
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <string>

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

static int do_case() {
  std::string stack;
  std::cin >> stack;
  int n = 0;
  char prev = '+';
  for (int j = stack.size(); j--;) {
    n += prev != stack[j];
    prev = stack[j];
  }
  return n;
}

int main() {
  const int T = read_int();
  for (int j = 1; j <= T; ++j) {
    std::cout << "Case #" << j << ": "
              << do_case()
              << std::endl;
  }
  return 0;
}
