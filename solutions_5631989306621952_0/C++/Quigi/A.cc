// 2016 Round 1A
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <string>
#include <algorithm>


static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

static std::string do_case() {
  std::string orig, best = "";
  std::cin >> orig;
  for (char c : orig)
    if (best.empty() || c >= best[0])
      best.insert(best.begin(),c); // inefficient, but 1000^2 won't kill us
    else
      best.push_back(c);
  return best;
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
