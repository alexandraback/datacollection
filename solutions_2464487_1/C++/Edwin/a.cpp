#include <stdio.h>

unsigned long long int ink(unsigned long long int n, unsigned long long int r) {
  unsigned long long ans = 0;
  // n circles radius r
  ans += n * (2 * r + 1);
  ans += 2 * n * (n - 1);
  return ans;
}

int main()
{
  int T;

  scanf("%d", &T);

  for (int num = 1; num <= T; num++) {
    unsigned long long int r, t;
    scanf("%llu%llu", &r, &t);
    unsigned long long int nlow = 1, nhigh=1, nmid;
    while (ink(nhigh, r) < t) {
      nhigh *= 2;
    }

    while (nhigh - nlow > 1) {
      nmid = (nlow + nhigh) / 2;
      if (ink(nmid, r) == t) {
        nhigh = nlow = nmid;
      } else if (ink(nmid, r) > t) {
        nhigh = nmid;
      } else { 
        nlow = nmid;
      }
    }

    unsigned long long int ans = nhigh;
    if (ink(nhigh, r) > t) {
      ans = nlow;
    }

    printf("Case #%d: %lld\n", num, ans);
  }

  return 0;
}
