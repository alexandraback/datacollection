#include <bits/stdc++.h>
using namespace std;
char s[105];
int solve() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  int j = n - 1;
  while (true) {
    while (j >= 0 && s[j] == '+') j--;
    if (j == -1) return ans;
    int k = 0;
    while (s[k] == '+') s[k++] = '-';
    if (k) ans++;
    for (int p = 0, q = j; p < q; p++, q--) {
      swap(s[p], s[q]);
    }
    for (int p = 0; p <= j; p++) {
      s[p] = s[p] == '+' ? '-' : '+';
    }
    ans++;
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: %d\n", t, solve());
  }
  return 0;
}

