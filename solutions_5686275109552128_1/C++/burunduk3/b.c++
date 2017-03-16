#include <cassert>
#include <cstdio>

int main() {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    int n;
    assert (scanf ("%d", &n) == 1);
    int a[n];
    for (int i = 0; i < n; i++)
      assert (scanf ("%d", &a[i]) == 1);
    int ans = (int)1e9;
    for (int limit = 1; limit <= 1000; limit++) {
      int res = limit;
      for (int i = 0; i < n; i++) {
        res += (a[i] - 1) / limit;
      }
      if (res < ans)
        ans = res;
    }
    printf ("Case #%d: %d\n", t, ans);
  }
  return 0;
}

