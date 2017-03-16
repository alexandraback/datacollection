#include <bits/stdc++.h>

using namespace std;

void update(int &ok, int b) {
  if (b == 0)
    ok |= 1;
  while (b) {
    ok |= (1 << (b % 10));
    b /= 10;
  }
}

int solve(int n) {
  if (n == 0) return -1;
  int ok = 0;
  for (int i = 1; ; ++i) {
    update(ok, i * n);
    if (ok == (1 << 10) - 1) {
     return i * n;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int _ = 1, n; _ <= t; ++_) {
    scanf("%d", &n);
    printf("Case #%d: ", _);
    int t = solve(n);
    if (t > 0)
      printf("%d\n", t);
    else
      puts("INSOMNIA");
  }
  return 0;
}
