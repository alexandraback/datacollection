#include <stdio.h>

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int ti = 0; ti < T; ++ti) {
    long long r = 0;
    long long t = 0;
    long long ans = 0;
    scanf("%lld%lld", &r, &t);
    r += 1;
    long long required = 2*r-1;
    while (required <= t) {
      ++ans;
      required += (2*r+4*ans-1);
    }

    printf("Case #%d: %d\n", ti+1, ans);
  }
  return 0;
}
