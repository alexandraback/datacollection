#include <cstdio>

typedef long long ll;

ll gcd(ll x,ll y)
{
  ll t;
  while (y)
  {
    t=x%y;
    x=y;
    y=t;
  }
  return x;
}

inline bool check(ll x)
{
  while (x>1)
  {
    if (x&1) return false;
    x>>=1;
  }
  return true;
}

int main()
{
  int T,o;
  ll p,q,t;
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    printf("Case #%d: ",o);
    scanf("%lld/%lld",&p,&q);
    t=gcd(q,p);
    q/=t;
    p/=t;
    if (!check(q)) puts("impossible");
    else
    {
      int ans;
      ans=0;
      while (p<q)
      {
	p<<=1;
	ans++;
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}
