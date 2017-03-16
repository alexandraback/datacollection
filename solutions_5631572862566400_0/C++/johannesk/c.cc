#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
#include <boost/range.hpp>
#include "../../prettyprint.hpp"
using namespace std;
using boost::irange;
using boost::make_iterator_range;

#ifdef NDEBUG
#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/device/null.hpp>
boost::iostreams::stream<boost::iostreams::null_sink> logs((boost::iostreams::null_sink()));
#else
auto& logs = cerr;
#endif

using int_ = int;
#define int int_fast64_t

namespace cycler {
struct node {
  int next=-1;
  bool vis=false;
};

vector<node> g;

int dfs(int i, int target) {
  if (g[i].vis)
    return -1e9;
  g[i].vis = true;
  if (i == target)
    return 1;
  return dfs(g[i].next, target) + 1;
}
}


namespace pather {
struct node {
  vector<int> adj;
};

vector<node> g;

int dfs(int i, int forbidden) {
  int best = 1;
  for (auto& n : g[i].adj)
    if (n != forbidden)
      best = max(best, dfs(n, forbidden) + 1);
  return best;
}
}

int solve() {
  int n; cin >> n;
  cycler::g.clear();
  pather::g.clear();
  pather::g.resize(n);
  for (int i=0; i<n; ++i) {
    int nxt; cin >> nxt; --nxt;
    cycler::g.emplace_back();
    cycler::g.back().next = nxt;

    pather::g[nxt].adj.push_back(i);
  }
  int best_cycle = 0;
  for (int i : irange<int>(0, n)) {
    for (auto& n : cycler::g) n.vis = false;
    best_cycle = max(best_cycle, cycler::dfs(cycler::g[i].next, i));
  }
  int tot_paths = 0;
  for (int i : irange<int>(0, n)) {
  for (int j : irange<int>(0, i)) {
    if (cycler::g[i].next == j &&
        cycler::g[j].next == i)
      tot_paths += pather::dfs(i, j) + pather::dfs(j, i);
  }
  }
  return max(best_cycle, tot_paths);
}

int_ main() {
  int testcases; cin >> testcases;
  for (auto i : irange(int(1), testcases+1)) {;
    cout << "Case #" << i << ": ";
    auto res = solve();
    if (res == -1) cout << "IMPOSSIBLE";
    else cout << res;
    cout << '\n';
  }
}

/*
 * Local variables:
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g3 -ggdb3 -O0 -Wall -Wextra -std=c++14 c.cc -o c && for f in *.in; do echo \"--- $f -------------\"; ./c <$f; done"
 * end:
 */
