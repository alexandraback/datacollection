#include <cassert>
#include <cstdio>
#include <cstring>

#include <map>
#include <string>

using namespace std;

const int maxl = 50;
const int maxn = 2010;
const int maxm = 10010;

int he[maxn], c[maxn], k;
int ne[maxm], to[maxm], re[maxm], ca[maxm];

void edge ( int a, int b, int c ) {
  assert (k + 2 <= maxm);
  ne[k] = he[a], to[k] = b, re[k] = k + 1, ca[k] = c;
  he[a] = k++;
  ne[k] = he[b], to[k] = a, re[k] = k - 1, ca[k] = 0;
  he[b] = k++;
}

bool dfs ( int u ) {
  c[u] = 1;
  if (u == 1)
    return true;
  for (int t = he[u]; t != -1; t = ne[t]) {
    if (ca[t] == 0 || c[to[t]])
      continue;
    if (dfs (to[t])) {
      ca[t]--, ca[re[t]]++;
      return true;
    }
  }
  return false;
}

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    int m, n = 2;
    assert (scanf ("%d", &m) == 1);
    map <string, int> node1, node2;
    int xa[m], xb[m];
    for (int i = 0; i < m; i++) {
      char a[maxl + 1], b[maxl + 1];
      assert (scanf ("%s%s", a, b) == 2);
      string sa = a, sb = b;
      if (node1.count (sa) == 0)
        node1[sa] = n++;
      if (node2.count (sb) == 0)
        node2[sb] = n++;
      xa[i] = node1[sa], xb[i] = node2[sb];
    }
    assert (n <= maxn);

    int cnt[n], lf[n], rt[n];
    memset (cnt, 0, sizeof (cnt[0]) * n);
    memset (lf, 0, sizeof (lf[0]) * n);
    memset (rt, 0, sizeof (rt[0]) * n);
    for (int i = 0; i < m; i++) {
      cnt[xa[i]]++, cnt[xb[i]]++;
      lf[xa[i]] = 1;
      rt[xb[i]] = 1;
    }
    assert (lf[0] == 0 && rt[0] == 0);
    assert (lf[1] == 0 && rt[1] == 0);

    k = 0;
    memset (he, -1, sizeof (he[0]) * n);
    for (int i = 2; i < n; i++) {
      assert (lf[i] + rt[i] == 1);
      assert (cnt[i] > 0);
      if (lf[i])
        edge (0, i, cnt[i] - 1);
      else
        edge (i, 1, cnt[i] - 1);
    }
    for (int i = 0; i < m; i++)
      edge (xa[i], xb[i], 1);

    memset (c, 0, sizeof (c[0]) * n);
    int ans = 0;
    while (dfs (0)) {
      ans++;
      memset (c, 0, sizeof (c[0]) * n);
    }
    printf ("Case #%d: %d\n", t, ans);
  }
  return 0;
}

