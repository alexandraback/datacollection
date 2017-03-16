#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

void rd() { }
template<typename... T> void rd(int &h, T &... t) { scanf("%d", &h); rd(t...); }
template<typename... T> void rd(long long &h, T &... t) { scanf("%lld", &h); rd(t...); }
template<typename... T> void rd(double &h, T &... t) { scanf("%lf", &h); rd(t...); }

const int maxN = 20;
int n, best[maxN], deg[maxN], dset[maxN], ds[maxN];

int popcnt(int mask) {
  int r = 0;
  while (mask) {
    if (mask & 1) r += 1;
    mask >>= 1;
  }
  return r;
}

bool inm(int mask, int i) {
  return ((mask >> (i-1)) & 1);
}

void init() {
  for (int i = 1; i <= n; ++i) dset[i] = i;
}

int find(int u) {
  if (u == dset[u]) return u;
  dset[u] = find(dset[u]);
  return dset[u];
}

void unite(int u, int v) {
  u = find(u), v = find(v);
  dset[u] = v;
}

bool check(int mask) {
  memset(deg, 0, sizeof(deg));
  if (mask == 0) return 0;
  init();
  for (int i = 1; i <= n; ++i) {
    if (inm(mask, i)) {
      int j = best[i];
      if (!inm(mask, j)) return false;
      if (best[j] == i) {
        if (i < j) ++deg[i], ++deg[j], unite(i, j);
      } else ++deg[i], ++deg[j], unite(i, j);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (inm(mask, i)) {
      if (deg[i] > 2) {
        return false;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (inm(mask, i)) {
      if (find(i) == i) ++cnt;
    }
  }
  if (cnt == 1) return true;
  set<int> s;
  for (int i = 1; i <= n; ++i) {
    if (inm(mask, i)) {
      int f = find(i);
      if (deg[i] < 2) s.insert(f);
    }
  }
  if (s.size() == cnt) return true;
  return false;
}

int main() {
  int tests;

  freopen("C-small-attempt0.in", "r", stdin);
  
  rd(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    printf("Case #%d: ", tt);
    rd(n);
    for (int i = 1; i <= n; ++i) {
      rd(best[i]);
    }
    int limit = 1 << n, answer = 0;
    for (int mask = 0; mask < limit; ++mask) {
      if (check(mask)) answer = max(answer, popcnt(mask));
    }
    printf("%d\n", answer);
  }
  return 0;
}
