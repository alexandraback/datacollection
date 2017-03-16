#include <bits/stdc++.h>

using namespace std;

char s[1234];

int main() {
  freopen("A.in", "rt", stdin);
  freopen("A.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int n; scanf("%d %s", &n, s);
    int ans = 0;
    int standing = 0;
    for(int i = 0; i <= n; ++i) {
      if(standing < i) {
        ans += i - standing;
        standing = i;
      }
      standing += s[i] - '0';
    }
    printf("Case #%d: %d\n", test, ans);
  }
  return 0;
}
