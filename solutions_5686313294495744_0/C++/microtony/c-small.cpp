#include <bits/stdc++.h>
using namespace std;
char s[1005][25], t[1005][25];
int solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %s", s[i], t[i]);
  }
  int m = 1 << n;
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    set<string> s1, t1, s2, t2;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        cnt++;
        s1.insert(s[j]);
        t1.insert(t[j]);
      } else {
        s2.insert(s[j]);
        t2.insert(t[j]);
      }
    }
    bool ok = true;
    for (string x : s1) {
      ok &= s2.count(x);
    }
    for (string x : t1) {
      ok &= t2.count(x);
    }
    if (ok) {
      ans = max(ans, cnt);
    }
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    printf("Case #%d: %d\n", t, solve());
  }
  return 0;
}
