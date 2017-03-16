#include <cstdio>

inline int mv(int v, int dig) {
  return (v/10) + (v%10)*dig;
}

long long cc(int v, int a, int b, int dig) {
  int k = mv(v, dig);
  long long res = 0;
  while (k != v) {
    if (k > v && k >= a && k <= b) res++;
    k = mv(k, dig);
  }
  return res;
}

void test() {
  int a,b;
  long long res = 0;
  scanf("%d%d", &a, &b);
  int dig = 1;
  for (int u = a; u > 0; u/=10) dig *= 10;
  dig /= 10;
  for (int i = a; i<=b; i++) {
    res += cc(i,a,b,dig);
  }
  printf("%lld\n", res);
}

main() {
  int t, cid=1;
  scanf("%d", &t);
  while (t--) {
    printf("Case #%d: ", cid++);
    test();
  }
}