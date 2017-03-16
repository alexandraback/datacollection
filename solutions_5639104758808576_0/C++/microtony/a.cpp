#include <bits/stdc++.h>
using namespace std;
char s[10000];
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    int n;
    scanf("%d %s", &n, s);
    int sum = 0, ans = 0;
    for (int i = 0; i <= n; i++) {
      s[i] -= 48;
      if (s[i] && sum < i) {
        ans += i - sum;
        sum = i;
      }
      sum += s[i];
    }
    printf("Case #%d: %d\n", caseno, ans);
  }
  return 0;
}

