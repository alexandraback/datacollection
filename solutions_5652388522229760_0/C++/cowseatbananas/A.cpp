#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T;
long long N;
bool digits[10];

void fill(long long x) {
  bool nonzero = true;
  while (x) {
    nonzero = false;
    digits[x % 10] = 1;
    x /= 10;
  }
  if (nonzero) digits[0] = true;
}

int main() {
  scanf("%d", &T);
  REP (t, T) {
    scanf("%lld", &N);
    if (N == 0) {
      printf("Case #%d: INSOMNIA\n", t);
      continue;
    }

    memset(digits, 0, sizeof digits);
    long long x = 0, ans = -1;
    while (true) {
      x += N;
      fill(x);
      int total = 0;
      FOR (j, 10) total += digits[j];
      if (total == 10) {
        ans = x;
        break;
      }
    }

    printf("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
