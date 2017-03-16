#include <cassert>
#include <cstdio>

#include <algorithm>

int main() {
  using std::max;
  int tn;
  assert (scanf("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    int n;
    assert (scanf ("%d ", &n) == 1);
    int a[n + 1];
    for (int i = 0; i <= n; i++) {
      char c;
      assert (scanf ("%c", &c) == 1);
      a[i] = c - '0';
    }
    int ans = 0, sum = 0;
    for (int i = 0; i <= n; i++) {
      if (!a[i])
        continue;
      ans = max (ans, i - sum);
      sum += a[i];
    }
    printf ("Case #%d: %d\n", t, ans);
  }
  return 0;
}

