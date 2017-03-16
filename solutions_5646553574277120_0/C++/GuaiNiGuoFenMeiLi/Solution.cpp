#include <bits/stdc++.h>

using namespace std;

int T, C, D, V;
int a[5];
bool f[31], g[31];

#define IS(i, j) (((i) >> (j)) & 1)

void add(bool *f, int v) {
  for (int i = V; i - v >= 0; --i)
    f[i] = f[i] || f[i - v];
}

bool check(bool *f) {
  for (int i = 1; i <= V; ++i)
    if (!f[i]) return false;
  return true;
}

int solve() {
  cin >> C >> D >> V;
  memset(f, 0x00, sizeof(f));
  f[0] = true;
  for (int i = 0; i < D; ++i) {
    cin >> a[i];
    add(f, a[i]);
  }
  int res = 0;
  if (check(f)) return res;
  if (!f[1]) {
    res++;
    add(f, 1);
  }
  if (check(f)) return res;
  if (!f[2]) {
    res++;
    add(f, 2);
  }
  if (check(f)) return res;

  vector<int> b;
  for (int i = 1; i <= V && i <= 20; ++i)
    if (!f[i]) b.push_back(i);
  int n = (int)b.size();
  int opt = V - D;
  for (int i = 1; i < (1 << n); ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j)
      if (IS(i, j)) cnt++;
    if (cnt + res >= opt) continue;
    for (int j = 0; j <= V; ++j)
      g[j] = f[j];
    for (int j = 0; j < n; ++j)
      if (IS(i, j)) add(g, b[j]);
    if (check(g)) opt = min(opt, cnt + res);
  }
  return opt;
}

int main() {

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int res = solve();
    printf("Case #%d: %d\n", test, res);
  }
  return 0;
}
