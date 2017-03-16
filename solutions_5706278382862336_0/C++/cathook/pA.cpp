#include <cstdio>

typedef long long lnt;

lnt gcd(lnt a, lnt b){
  while((a %= b) && (b %= a));
  return a + b;
}


int main(){
  for(int TT, T = (scanf("%d", &TT), 1); T <= TT; T++){
    printf("Case #%d: ", T);
    lnt P, Q;
    scanf("%lld/%lld", &P, &Q);
    lnt k = gcd(P, Q);
    P /= k;
    Q /= k;
    int count = 0;
    for (lnt x = Q; x > 0; x /= 2) {
      if (x & 1) {
        count++;
      }
    }
    if (count > 1) {
      printf("impossible\n");
    } else {
      int count = 0;
      while (P < Q) {
        P *= 2;
        count++;
      }
      printf("%d\n", count);
    }
  }
  return 0;
}
