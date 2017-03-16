#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

namespace BM {
#define MAXN0 1024
#define MAXN1 1024
#define MAXM (1<<21)
  int n0, n1, m, ptr[MAXN0], next[MAXM], zu[MAXM];
  int to[MAXN0], fr[MAXN1], us[MAXN1], total;
  int lev[MAXN0], que[MAXN0], *qb, *qe;
  void init(int _n0, int _n1) {
    n0 = _n0; n1 = _n1; m = 0; memset(ptr, ~0, n0 * 4);
  }
  void ae(int u, int v) {
    next[m] = ptr[u]; ptr[u] = m; zu[m] = v; ++m;
  }
  int augment(int u) {
    int i, v, w;
    us[u] = total;
    for (i = ptr[u]; ~i; i = next[i]) {
      if (!~(w = fr[v = zu[i]]) || us[w] != total && lev[u] < lev[w] && augment(w)) {
        to[u] = v; fr[v] = u; return 1;
      }
    }
    return 0;
  }
  int solve() {
    int f, i, u, w;
    memset(to, ~0, n0 * 4); memset(fr, ~0, n1 * 4); memset(us, ~0, n1 * 4);
    for (total = 0;; total += f) {
      qb = qe = que;
      memset(lev, ~0, n0 * 4);
      for (u = 0; u < n0; ++u) if (!~to[u]) lev[*qe++ = u] = 0;
      for (; qb != qe;) for (i = ptr[u = *qb++]; ~i; i = next[i]) {
        if (~(w = fr[zu[i]]) && !~lev[w]) lev[*qe++ = w] = lev[u] + 1;
      }
      for (f = 0, u = 0; u < n0; ++u) if (!~to[u]) f += augment(u);
      if (!f) return total;
    }
  }
}

void solve() {
  int N = in();
  map<string, int> F, S;
  vector<int> fi, si;
  for (int i = 0; i < N; ++i) {
    char fs[32], ss[32];
    scanf("%s%s", fs, ss);
    if (F.count(fs) == 0) {
      int k = F.size(); F[fs] = k;
    }
    if (S.count(ss) == 0) {
      int k = S.size(); S[ss] = k;
    }
    fi.push_back(F[fs]);
    si.push_back(S[ss]);
  }

  BM::init(F.size(), S.size());
  for (int i = 0; i < N; ++i) {
    BM::ae(fi[i], si[i]);
  }
  int match = BM::solve();
  int res = N - (F.size() + S.size() - match);
  printf("%d\n", res);
}

int main() {
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
