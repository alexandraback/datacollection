#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <complex>
#include <numeric>
#include <ext/numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

struct Hiker {
  int p;
  int m;
  int idx;
  Hiker(int p, int m, int idx) : p(p), m(m), idx(idx)  {}
  Hiker() {}
};

struct HikerPCmp {
  bool operator()(const Hiker& a, const Hiker& b) const {
    if (a.p != b.p) return a.p < b.p;
    return a.m > b.m;
  }
};
struct HikerSCmp {
  bool operator()(const Hiker& a, const Hiker& b) const {
    return a.m < b.m;
  }
};

int f(int m0, int mi, int p0, int pi) {
  double t = ((double)p0)/(360.0/m0);

  if (mi != m0) {
    int n = 0;
    if (p0 > pi || (p0 == pi && m0 < mi)) {
      // we jumped past this guy
      n += 1;
    }

    if (m0 < mi) {
      // m0 is actually faster than mi
      swap(m0, mi);
      swap(p0, pi);
    }

    if (mi < m0) {
      // i faster than 0
      double d = t*(360.0/mi - 360.0/m0);

      double to_travel = 0;
      if (p0 > pi) {
        // pi has to catch up
        to_travel = pi - p0;
      } else {
        to_travel = 360 - pi + p0;
      }

      if (d >= to_travel) {
        n += 1;
        d -= to_travel;
        n += d/360.0;
      }
    
      return n;
    } else {
      // as if we're catching up to mi
      double d = t*(360.0/m0 - 360.0/mi);

      double to_travel = 0;
      if (p0 > pi) {
        to_travel = 360 - pi + p0;
      } else {
        // p0 has to catch up
        to_travel = pi - p0;
      }

      if (d >= to_travel) {
        n += 1;
        d -= to_travel;
        n += d/360.0;
      }
    
      return n;
      
    }
    
  } else {
    return p0 > pi;
  }
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  Hiker hikers[16];
  Hiker hikers2[16];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int p, h, m;
      scanf("%d %d %d", &p, &h, &m);
      for (int j = 0; j < h; ++j) {
        hikers[cnt] = Hiker(p, m+j, cnt);
        hikers2[cnt] = hikers[cnt];
        cnt++;
      }
    }
    sort(hikers, hikers+cnt, HikerPCmp());
    //sort(hikers2, hikers2+cnt, HikerSCmp());

    if (cnt == 1) {
      printf("Case #%d: %d\n", ctr+1, 0);
      continue;
    }
    // go straight
    int ans = cnt;

    if (hikers[0].m < hikers[1].m) {
      // first guy is faster than second (note first guy must be positioned before second)

      // strat 1: trail first
      int v = f(hikers[0].m, hikers[1].m, hikers[0].p, hikers[1].p);
      //printf("x %d\n", v);
      ans = min(ans, v);
      
      // strat 2: trail second
      v = f(hikers[1].m, hikers[1].m, hikers[1].p, hikers[1].p);
      v += f(hikers[1].m, hikers[0].m, hikers[1].p, hikers[0].p);
      //printf("x %d\n", v);
      ans = min(ans, v);
      // strat 2: trail second
      v = f(hikers[1].m, hikers[1].m, hikers[0].p, hikers[1].p);
      v += f(hikers[1].m, hikers[0].m, hikers[0].p, hikers[0].p);
      //printf("x %d\n", v);
      ans = min(ans, v);

    } else if (hikers[0].m == hikers[1].m) {
      // everyone equal
      ans = 0;
    } else {
      // second guy is faster than first

      // strat 1: trail first
      int v = f(hikers[0].m, hikers[1].m, hikers[0].p, hikers[1].p);
      ans = min(ans, v);

      // strat 2: trail first until second exceeds, then jump.
      ans = min(ans, 1);
    }
    printf("Case #%d: %d\n", ctr+1, ans);
  }
  return 0;
}
