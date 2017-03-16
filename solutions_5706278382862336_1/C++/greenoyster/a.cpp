#include <stdio.h>

long long int gcd(long long int a, long long int b) {
  long long int t;
  while(b) {
    t = a%b;
    a = b;
    b = t;
  }
  return a;
}

int main() {
  int T;
  scanf("%d", &T);
  for(int N = 1; N <= T; ++N) {
    long long int a, b, t;
    scanf("%lld/%lld", &a, &b);
    printf("Case #%d: ", N);
    t = gcd(a, b);
    a/=t;
    b/=t;

    t = b;
    while(t%2 == 0  && t !=1) {
      t/=2;
    }
    if (t != 1) {
      printf("impossible\n");
    } else {
      int ans = 0;
      while (a < b) {
        a*=2;
        t = gcd(a, b);
        a/=t;
        b/=t;
        ++ans;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
