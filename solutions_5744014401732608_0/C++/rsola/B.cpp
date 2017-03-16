#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 55;
const int M = 1000000007;

int n; ll k;
int a[N][N];

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    memset(a, 0, sizeof(a));
    scanf("%d%I64d", &n, &k);
    printf("Case #%d: ", C);
    if (k > 1LL << (n - 2)) { puts("IMPOSSIBLE"); continue; }
    puts("POSSIBLE");
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        a[i][j] = 1;
      }
    }
    ll tot = 1LL << (n - 2), to = tot - k;
    for (int u = 0; k && u < n - 1; u++) {
      for (int v = u + 2; v < n; v++) {
        if (to >= max(1LL, 1LL << (n - v - 2))) { a[u][v] = 0; to -= max(1LL, 1LL << (n - v - 2)); }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d", a[i][j]);
      }
      puts("");
    }
  }
}
