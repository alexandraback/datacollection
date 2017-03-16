#include <cstdio>
char arr[1111];
int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int s;
    scanf("%d", &s);
    scanf("%s", arr);
    int sum = arr[0] - '0';
    int ans = 0;
    for (int i = 1; i <= s; i++) {
      int x = arr[i] - '0';
      if (sum < i) {
        ans += i - sum;
        sum += i - sum + x;
      } else sum += x;
    }
    printf("Case #%d: %d\n", tc, ans);
  }
}

