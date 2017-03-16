#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

long long r, t, ans;

void solve() {
  long long b = 2LL * r - 1;
  long long lo = 1;
  long long hi = min((long long)sqrt(t) + 1, t / b);
  long long mid = 0;
  while (lo + 1 < hi) {
    mid = (lo + hi) / 2;
    if (2 * mid * mid + b * mid <= t)
      lo = mid;
    else hi = mid;
  }
  if (2 * hi * hi + b * hi <= t)
    ans = hi;
  else
    ans = lo;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tcase = 1; tcase <= T; ++tcase) {
    cin >> r >> t;
    solve();
    printf("Case #%d: ", tcase);
    cout << ans << endl;
  }
  return 0;
}
