#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}

int check(ll n)
{
  int cnt=0;
  while(n)
    {
      cnt+= (n&1);
      n>>=1;
    }
  return cnt==1;
}

int main()
{
  int T;
  cin>>T;
  long long P,Q;
  char c;
  for(int t=1;t<=T;t++)
    {
      cin>>P>>c>>Q;
      ll g = gcd(P,Q);
      P/=g;
      Q/=g;
      if(!check(Q))
	printf("Case #%d: impossible\n",t);
      else
	{
	  int res=0;
	  ll q=2;
	  while(q<=Q)
	    {
	      res++;
	      ll p = (Q/q);
	      if(p<=P)
		break;
	      q*=2;
	    }
	  printf("Case #%d: %d\n",t,res);
	}
    }
  return 0;
}
