#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

typedef long long int lld;

struct great_wall {
  const int max = 400;
  std::vector<int> wall;
  great_wall() : wall(2*max) {};

  int operator [](int a) { return wall.at(max+a); }

  std::vector<int>::iterator it_at(int a) { return wall.begin() + (max+a); }

  int range_min(int l, int r) {
    return *std::min_element(it_at(l), it_at(r));
  }

  void update_max(int l, int r, int v) {
    for (auto it = it_at(l), end=it_at(r); it != end; ++it)
      *it = std::max(*it, v);
  }
};

struct tribe {
  int d,  n,  w,  e,  s,  delta_d, delta_p, delta_s;
};
std::istream& operator>>(std::istream& in, tribe& t)
{
  in >> t.d >> t.n >> t.w >> t.e >> t.s >> t.delta_d >> t.delta_p >> t.delta_s;
  t.w = 2*t.w;
  t.e = 2*t.e+1;
  t.delta_p *= 2;
  return in;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
  int testcases = 0; std::cin >> testcases;

  for (int case_nr=1; case_nr<=testcases; ++case_nr) {
    std::cout << "Case #" << case_nr << ": ";

    std::vector<tribe> tribes;
    std::vector<std::vector<int> > attacks(2*676060+3);

    int n; std::cin >> n;
    for (int i=0; i<n; ++i) {
      tribe t; std::cin >> t;
      attacks[t.d].push_back(tribes.size());
      tribes.push_back(t);
    }

    great_wall wall;
    int succeeded = 0;

    for (int i=0; i<=676060; ++i) {
      //if (!attacks[i].empty()) std::cout << "\nat " << i << '\n';
      for (auto ti : attacks[i]) {
        tribe& t = tribes[ti];

        //std::cout << "tribe " << ti+1 << ": attack with " << t.s << " at " << t.w/2.0 << " - " << t.e/2.0 << " => " << ((wall.range_min(t.w, t.e) < t.s) ? "succeeded" : "failed") << '\n';

        if (wall.range_min(t.w, t.e) < t.s)
          ++succeeded;
      }    

      for (auto ti : attacks[i]) {
        tribe& t = tribes[ti];
        wall.update_max(t.w, t.e, t.s);

        t.d += t.delta_d;
        t.w += t.delta_p;
        t.e += t.delta_p;
        t.s += t.delta_s;

        if (--t.n)
          attacks[t.d].push_back(ti);
      }
    }

    std::cout << succeeded;

    std::cout << '\n';
  }

}

/*
 * Local variables:
 * mode:c++
 * compile-command:"rm -f fast-greatwall && g++ -Ofast -flto -march=native -std=c++11 greatwall.cc -o fast-greatwall >/dev/null &; g++ -g -ggdb3 -O0 -D_GLIBCXX_DEBUG -Wall -Wextra -pedantic -Wno-long-long -std=c++11 greatwall.cc -o greatwall && for f in *.in; do echo \"--- $f -------------\"; ./greatwall <$f; done"
 * end:
 */
