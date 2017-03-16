// 2016 Round 1B, Problem B. Close Match
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

struct Score {
  std::string c, j;
};

long abs(long x) {
  return x<0 ? -x : x;
}

static bool better(const Score &l, const Score &r) {
  const long
    lc = std::stol(l.c),
    lj = std::stol(l.j),
    rc = std::stol(r.c),
    rj = std::stol(r.j);
  const long l_diff = abs(lc - lj), r_diff = abs(rc-rj);
  if (l_diff != r_diff) return l_diff < r_diff;
  if (lc != rc) return lc < rc;
  return lj < rj;
}

static Score best(std::string c, std::string j) {
  std::cerr << "best(\"" << c << "\", \"" << j << "\")" << std::endl;
  Score s {"", ""};             // OK to return for length 0; otherwise "worst"
  if (c.size() == 0) return s;
  if (c[0] == '?') {
    char j0 = j[0] == '?' ? '0' : j[0];
    for (c[0] = std::max('0', char(j0-1)); c[0] <= std::min('9', char(j0+1)); ++c[0]) {
      Score chal = best(c, j);
      if (s.c == "" || better(chal, s)) s = chal;
    }
  } else if (j[0] == '?') {
    for (j[0] = std::max('0', char(c[0]-1)); j[0] <= std::min('9', char(c[0]+1));
         ++j[0]) {
      Score chal = best(c, j);
      if (s.c == "" || better(chal, s)) s = chal;
    }
  } else if (j[0] == c[0]) {
    s = best(c.substr(1), j.substr(1));
    s.c.insert(s.c.begin(), c[0]);
    s.j.insert(s.j.begin(), j[0]);
  } else {
    for (char& ch : c)
      if (ch == '?')
        ch = c[0]<j[0] ? '9' : '0';
    s.c = c;
    for (char& ch : j)
      if (ch == '?')
        ch = c[0]<j[0] ? '0' : '9';
    s.j = j;
  }
  return s;
}

static void do_case() {
  std::string c_pat, j_pat;
  std::cin >> c_pat >> j_pat;
  Score ans = best(c_pat, j_pat);
  std::cout << ans.c << " " << ans.j;
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
