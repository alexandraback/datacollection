// 2016 Round 1B, Problem A. 
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <string>

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

typedef std::vector<int> VI;

static void do_case() {
  static const std::string name[] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
  };
  static const int  digit[] = { 0 ,  2,   4 ,  6,   8 ,   1 ,  3 ,  5 ,  7 ,   9 };
  static const char pivot[] = {'Z', 'W', 'U', 'X', 'G',  'O', 'H', 'F', 'S',  'I'};

  std::string s;
  std::cin >> s;
  VI n_char('Z' + 1), n_digit(10);
  for (char c: s) ++n_char[c];
  for (int j = 0; j < 10; ++j) {
    n_digit[digit[j]] = n_char[pivot[j]];
    std::cerr << "pivot " << pivot[j] << "; digit " << digit[j] << " occurs "
              << n_digit[digit[j]] << " times." << std::endl;
    for (char c: name[digit[j]])             // back out what's explained
      n_char[c] -= n_digit[digit[j]];
  }
  for (int j = 0; j < 10; ++j)
    for (int k = n_digit[j]; k--; std::cout << j);
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
