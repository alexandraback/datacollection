#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("INSOMNIA");
    return ;
  }
  bool x[10];
  memset(x, 0, sizeof x);
  int cnt = 0;
  for (int i = n; ; i += n) {
    int j = i;
    while (j) {
      cnt += x[j % 10]++ == 0;
      j /= 10;
      if (cnt == 10) {
        printf("%d", i);
        return ;
      }
    }
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: ", t);
    solve();
    printf("\n");
  }
  return 0;
}

