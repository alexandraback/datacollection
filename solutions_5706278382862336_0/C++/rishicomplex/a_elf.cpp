#include <cstdio>

typedef long long int ll;

ll greatestCommonDivisor(ll m, ll n)
{
    ll r;

    /* Check For Proper Input */
    if((m == 0) || (n == 0))
        return 0;
    else if((m < 0) || (n < 0))
        return -1;

    do
    {
        r = m % n;
        if(r == 0)
            break;
        m = n;
        n = r;
    }
    while(true);

    return n;
}

void work(int caseno) {
  printf("Case #%d: ", caseno);
  ll P, Q;
  scanf("%lld/%lld", &P, &Q);
  ll gcd = greatestCommonDivisor(P, Q);
  P /= gcd;
  Q /= gcd;
  ll q = Q;
  //printf("q=%lld\n", q);
  int cnt = 0;
  int flag = 0;
  for(cnt = 0; cnt <= 40; cnt++) {
    if(q == 1) break;
    if(q % 2 == 1) {
      flag = 1;
      break;
    }
    q /= 2;
  }
  if(flag == 1 || cnt == 41) {
    printf("impossible\n");
    return;
  }
  ll p = P;
  
  while(p != 1) {
    p /= 2;
    cnt--;
  }
  printf("%d\n", cnt);
  
}

int main () {
  int T;
  scanf("%d", &T);
  for(int i = 0; i < T; i++) {
    work(i + 1);
  }
  return 0;
}
