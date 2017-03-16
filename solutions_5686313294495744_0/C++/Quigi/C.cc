// 2016 Round 1B, Problem C. Technobabble
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

typedef std::vector<int> VI;
struct Topic {
  std::string word[2];
};

static int do_case() {
  const int N = read_int();
  std::map<std::string, int> freq[2]; // word frequencies
  std::vector<Topic> topic(N);
  for (Topic& t : topic) 
    for (int j = 0; j < 2; ++j) {
      std::cin >> t.word[j];
      ++freq[j][t.word[j]];
    }
  int n_fake = 0;
  for (Topic& t : topic)        // Q: is one pass enough?
    if (freq[0][t.word[0]] > 1 && freq[1][t.word[1]] > 1) {
      std::cerr << "topic " << t.word[0] << "(" << freq[0][t.word[0]]
                << ") " << t.word[1]<< "(" << freq[1][t.word[1]] << ") could be fake."
                << std::endl;
      ++n_fake;                 // possibly
      --freq[0][t.word[0]];
      --freq[1][t.word[1]];
    }
  return n_fake;
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
