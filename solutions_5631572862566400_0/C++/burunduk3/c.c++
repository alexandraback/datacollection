#include <cassert>
#include <cstdio>
#include <cstring>

int *a, *c;
int ans, n;

void dfs ( bool ok1, bool ok2, int i1, int i2 ) {
  int k = 0;
  // fprintf (stderr, "dfs (%s, %s, %d, %d)\n", ok1 ? "true" : "false", ok2 ? "true" : "false", i1, i2);
  for (int i = 0; i < n; i++)
    k += c[i];
  if ((ok1 || a[i1] == i2) && (ok2 || a[i2] == i1) && k > ans)
    ans = k;
  // fprintf (stderr, "dfs (%s, %s, %d, %d), n = %d\n", ok1 ? "true" : "false", ok2 ? "true" : "false", i1, i2, n);
  for (int i = 0; i < n; i++) {
    // fprintf (stderr, " --> %d\n", i);
    if (c[i])
      continue;
    if (!(ok2 || a[i2] == i))
      continue;
    c[i] = 1;
    dfs (ok1, a[i] == i2, i1, i);
    c[i] = 0;
  }
}

int main () {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n;
    assert (scanf ("%d", &n) == 1);
    ::n = n;
    int a[n], c[n];
    for (int i = 0; i < n; i++)
      assert (scanf ("%d", &a[i]) == 1), a[i]--;
    ::a = a, ::c = c;
    memset (c, 0, sizeof (c[0]) * n);
    ans = 1;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++) {
        c[i] = c[j] = 1;
        dfs (a[i] == j, a[j] == i, i, j);
        c[i] = c[j] = 0;
      }
    printf ("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

