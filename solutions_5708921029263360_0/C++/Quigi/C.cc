// 2016 Round 1C, Problem C
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <map>

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

typedef std::vector<int> VI;
typedef std::vector<VI> VVI;

static void do_case() {
  const int J = read_int(), P = read_int(), S = read_int(), K = read_int();
  for (int count = 2; count--;) {
    int n_day = 0;
    VVI jp(J,VI(P)), js(J,VI(S)), ps(P,VI(S));
    std::vector<bool> jps(J*P*S);
    while (1) {
      int best = K,             // lame
        bj,bp,bs;
      for (int j = J; j--;)
        for (int p = P; p--;) {
          if (jp[j][p] >= best) break;
          for (int s = S; s--;) {
            const int rep = std::max(jp[j][p], std::max(js[j][s], ps[p][s]));
            if (!jps[j+J*(p+P*s)] && rep < best) {
              best = rep;
              bj = j;
              bp = p;
              bs = s;
            }
          } // s
        } // p
      if (best == K) break;
      ++n_day;
      jps[bj+J*(bp+P*bs)] = true;
      ++jp[bj][bp];
      ++js[bj][bs];
      ++ps[bp][bs];
      if (!count) {
//         std::cerr << "jp" << jp[bj][bp]
//                   << ", js " << js[bj][bs]
//                   << ", ps " << ps[bp][bs]
//                   << " -- ";
        std::cout << bj+1 << " " << bp+1 << " " << bs+1 << std::endl;
      }
    }
    if (count)
      std::cout << n_day << std::endl;
  }
}

int main() {
  const int T = read_int();
  for (int j = 1; j <= T; ++j) {
    std::cout << "Case #" << j << ": ";
    do_case();
  }
  return 0;
}
