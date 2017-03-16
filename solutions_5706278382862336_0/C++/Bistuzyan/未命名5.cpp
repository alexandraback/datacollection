#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std ;
typedef __int64 ll ;
ll gcd(ll a,ll b)
{
	return b==0?a:gcd(b,a%b) ;
}
int main()
{
	freopen("D:\A-small-attempt0.in","r",stdin) ;
	freopen("D:\A-small-attempt0.out","w",stdout) ;
	int T ;
	scanf("%d",&T) ;
	for(int cas=1 ;cas<=T ;cas++)
	{
		ll p,q ;
		scanf("%I64d/%I64d",&p,&q) ;
		ll a=gcd(p,q) ;
		p/=a ;q/=a ;
		ll maxn=1 ;
		for(int i=0 ;i<40 ;i++)
			maxn*=2 ;
		printf("Case #%d: ",cas) ;
		if(maxn%q)
		{
			puts("impossible") ;
			continue ;
		}
		p=maxn/q*p ;
		int ans=41 ;
		while(p)
		{
			p/=2 ;
			ans-- ;
		}
		printf("%d\n",ans) ;
	}
	return 0 ;
}