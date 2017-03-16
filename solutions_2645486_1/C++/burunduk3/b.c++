#include <cassert>
#include <cstdio>

#include <algorithm>

using namespace std;

const int maxn = 10010;

int e, rr, n;
int v[maxn];
int l[maxn], r[maxn], p[maxn];
long long sz[maxn];
 
int dsz( int u ) {
  // fprintf(stderr, "dsz[u=%d]: l=%d, r=%d, v=%d\n", u, l[u], r[u], v[u]);
  if (u == -1)
    return 0;
  return sz[u] = 1 + dsz(l[u]) + dsz(r[u]);
}
int gsz( int u ) {
  return u == -1 ? 0 : sz[u];
}

long long solve( int u, long long x, long long y ) {
  if (u == -1)
    return 0;
  assert(0 <= x && x <= e);
  assert(0 <= y && y <= e);
  assert(x + (sz[u] - 1) * (long long)rr >= y);
  long long left = min((long long)e, x + (long long)rr * gsz(l[u]));
  long long right = max(0ll, y - (long long)rr * gsz(r[u]));
  // fprintf(stderr, "u=%d, left = %lld, right = %lld\n", u, left, right);
  assert(left >= right);
  return (left - right) * v[u] + solve(l[u], x, max(0ll, left - rr)) + solve(r[u], min((long long)e, right + rr), y);
}

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    assert(scanf("%d%d%d", &e, &rr, &n) == 3);
    for (int i = 0; i < n; i++)
      assert(scanf("%d", &v[i]) == 1);
    int cr = -1;
    for (int i = 0; i < n; i++) {
      while (cr != -1 && p[cr] != -1 && v[p[cr]] < v[i])
        cr = p[cr];
      int lt = -1;
      if (cr != -1 && v[cr] < v[i])
        lt = cr, cr = p[cr];

      if (lt != -1)
        p[lt] = i;
      l[i] = lt;

      if (cr != -1)
        r[cr] = i;
      p[i] = cr;

      r[i] = -1;
      cr = i;
    }
    while (p[cr] != -1)
      cr = p[cr];
    dsz(cr);
    long long ans = solve(cr, e, 0);
    printf("Case #%d: %lld\n", tt, ans);
  }
  return 0;
}

