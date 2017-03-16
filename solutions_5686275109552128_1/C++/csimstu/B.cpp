#include <cstdio>
#include <algorithm>
using namespace std;
int a[1111];

int ceil_div(int a, int b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}

int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int n;
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      mx = max(mx, a[i]);
    }
    int best = -1;
    for (int k = 1; k <= mx; k++) {
      int cost = k;
      for (int i = 0; i < n; i++)
        if (a[i] > k) {
          cost += ceil_div(a[i], k) - 1;
        }
      if (best == -1 || cost < best) {
        best = cost;
      }
    }
    printf("Case #%d: %d\n", tc, best);
  }
}
