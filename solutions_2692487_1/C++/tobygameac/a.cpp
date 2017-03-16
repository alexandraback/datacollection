#include <cstdio>
#include <algorithm>

int ans, n, num[999];

void solve(int len, int now, int a) {
  if (now == n) {
    if (len < ans) ans = len;
    return;
  }
  if (a > num[now]) {
    solve(len, now + 1, a + num[now]);
  } else {
    solve(len + 1, now + 1, a);
    if (a > 1) {
      while (a <= num[now]) {
        a = a + a - 1;
        len++;
      }
      solve(len, now + 1, a + num[now]);
    }
  }
}

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    int a;
    scanf("%d%d", &a, &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &num[i]);
    std::sort(num, num + n);
    ans = 2e9;
    solve(0, 0, a);
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
