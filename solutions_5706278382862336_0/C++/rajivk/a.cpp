#include<stdio.h>
using namespace std;

long long gcd(long long a, long long b)
{
  if(a > b)
    return gcd(b, a);
  else if(a == 0)
    return b;
  else 
    return gcd(b%a, a);
}

bool ifPowerOfTwo(long long x)
{
  return x && (!(x&(x-1)));
}

int main()
{
  int t, T;
  scanf("%d", &T);
  for(t=0;t<T;t++)
    {
      long long P, Q, G;
      scanf("%lld/%lld", &P, &Q);
      G = gcd(P, Q);
      P /= G;
      Q /= G;
      if(ifPowerOfTwo(Q))
	{
	  int pwP, pwQ;
	  for(pwP=0; P>>pwP; pwP++);
	  for(pwQ=0; Q>>pwQ; pwQ++);
	  printf("Case #%d: %d\n", t+1, pwQ-pwP);
	}
      else
	{
	  printf("Case #%d: impossible\n", t+1);
	}
    }
}
