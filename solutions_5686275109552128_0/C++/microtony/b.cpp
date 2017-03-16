#include <bits/stdc++.h>
using namespace std;
int s[10000];
int main() {
  int t;
  scanf("%d", &t);
  for (int caseno = 1; caseno <= t; caseno++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &s[i]);
    }
    int ans = 2147483647;
    for (int i = 1; i <= 1000; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
        sum += max(0, (s[j] - 1) / i);
      }
      ans = min(ans, i + sum);
    }
    printf("Case #%d: %d\n", caseno, ans);
  }
  return 0;
}

