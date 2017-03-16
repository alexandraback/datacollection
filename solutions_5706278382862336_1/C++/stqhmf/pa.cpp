#include <cstdio>

typedef unsigned long long ull;

ull gcd(ull a, ull b)
{
  while ( b!=0 ) {
    ull t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    printf("Case #%d: ", t);

    ull P, Q;
    scanf("%llu/%llu", &P, &Q);
    ull PQ_gcd = gcd(P,Q);
    P /= PQ_gcd;
    Q /= PQ_gcd;

    P *= 1ull << 40;
    PQ_gcd = gcd(P,Q);
    P /= PQ_gcd;
    Q /= PQ_gcd;

    if ( Q != 1 ) {
      puts("impossible");
    }
    else {
      //printf("P=%llx, Q=%llx\n", P, Q);
      int len = 0;
      ull R = P;
      while ( R>0 ) {
	++len;
	R >>= 1;
      }
      //printf("len = %d\n", len);

      int pos = 40 - len + 1;
      //printf("pos = %d\n", pos);

      printf("%d\n", pos);
    }
  }
}
