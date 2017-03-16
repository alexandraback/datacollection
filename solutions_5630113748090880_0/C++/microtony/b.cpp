#include <bits/stdc++.h>
using namespace std;
int f[3000];
void solve() {
  memset(f, 0, sizeof f);
  int n;
  scanf("%d", &n);
  int m = n * (2 * n - 1);
  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    f[x]++;
  }
  for (int i = 1; i <= 2500; i++) {
    if (f[i] % 2) printf(" %d", i);
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d:", t);
    solve();
    printf("\n");
  }
  return 0;
}
