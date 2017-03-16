#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  bool exist[10];
  memset(exist, 0x00, sizeof(exist));
  for (int i = 1; ; ++i) {
    for (int j = i * n; j; j /= 10) {
      exist[j % 10] = true;
    }
    bool flag = true;
    for (int j = 0; j < 10; ++j) {
      if (!exist[j]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      return i;
    }
  }
}

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      printf("Case #%d: INSOMNIA\n", test);
    } else {
      printf("Case #%d: %d\n", test, solve(n) * n);
    }
  }
  return 0;
}
