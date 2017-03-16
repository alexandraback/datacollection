#include <cassert>
#include <cstdio>
#include <cstring>

int r, n, m, k;
int a[20], x[20], res[20];
int ok[1000];
int cnt = 0;

bool dfs( int t ) {
  // fprintf(stderr, "dfs(t=%d/%d)\n", t, n);
  if (t < n) {
    for (x[t] = 2; x[t] <= m; x[t]++)
      if (dfs(t + 1))
        return true;
    return false;
  }
  ++cnt;
  for (int pr = 0; pr <= (1 << n); pr++) {
    int mul = 1;
    for (int i = 0; i < n; i++)
      if (pr & (1 << i))
        mul *= x[i];
    ok[mul] = cnt;
  }
  for (int i = 0; i < k; i++)
    if (ok[a[i]] != cnt)
      return false;
  for (int i = 0; i < n; i++)
    res[i] = x[i];
  return true;
}

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1 && tn == 1);
  puts("Case #1:");
  assert(scanf("%d%d%d%d", &r, &n, &m, &k) == 4);
  memset(ok, 0, sizeof(ok));
  for (int t = 0; t < r; t++) {
    for (int i = 0; i < k; i++)
      assert(scanf("%d", &a[i]));
    for (int i = 0; i < n; i++)
      res[i] = 2;
    dfs(0);
    for (int i = 0; i < n; i++)
      printf("%d", res[i]);
    puts("");
  }
  return 0;
}

