#include<stdio.h>
#define ull unsigned long long

ull gcd(ull,ull);
int isPowerOfTwo(ull);
ull elf(ull, ull);
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        ull P,Q;
        char dummmy;
        scanf("%llu %c %llu",&P, &dummmy, &Q);
        ull g = gcd(Q,P);
        P /= g;
        Q /= g;
        if(isPowerOfTwo(Q))
            printf("Case #%d: %llu\n",i,elf(P,Q));
        else
            printf("Case #%d: impossible\n",i);
    }
    return 0;
}

ull gcd(ull a, ull b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a%b);
}

ull elf(ull P,ull Q)
{
    if(2*P >= Q)
        return 1;
    else
        return 1 + elf(P,Q/2);
}

int isPowerOfTwo(ull n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}
