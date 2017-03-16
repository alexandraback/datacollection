#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[200];

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, n, s, p, tmp1, tmp2, ans, cnt, u, i;
  cin >> T;
  for(u = 1; u <= T; ++u) {
    ans = 0;
    cnt = 0;
    cin >> n >> s >> p;
    tmp1 = p + max(0, p - 1) + max(0, p - 1);
    tmp2 = p + max(0, p - 2) + max(0, p - 2);
    for(i = 1; i <= n; ++i) {
      cin >> a[i];
      if(a[i] >= tmp1)
        ++ans;
      if(a[i] >= tmp2 && a[i] < tmp1)
        ++cnt;
    }
    ans += min(cnt, s);
    printf("Case #%d: ", u);
    printf("%d\n", ans);
  }
  return 0;
}
