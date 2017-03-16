#include <iostream>
#include <cstring>
#include <cstdio>
typedef long long ll;
using namespace std;

int t;
ll a,b,cur,ans,tmp;

ll gcd(ll A,ll B)
{
	return B==0?A:gcd(B,A%B);
}

int main()
{
	
	freopen("e:/A-large.in","rb",stdin);
	freopen("e:/test.out","wb",stdout);
	
	int T,cas=0;
	scanf("%d",&T);  
	while (T--)
	{
		scanf("%lld/%lld",&a,&b);
		if (a==0)
		{
			printf("Case #%d: impossible\n",++cas);
			continue;
		}
		tmp=gcd(a,b);
		a/=tmp,b/=tmp;
		cur=b;
		while (cur>1 && cur%2==0) cur/=2;
		if (cur>1 || a>b) 
		{
			printf("Case #%d: impossible\n",++cas);
			continue;
		}
		if (a==b)
		{
			printf("Case #%d: 0\n",++cas);
			continue;
		}
		ans=1;
		while (a*2<b) ans++,a*=2;
		printf("Case #%d: %lld\n",++cas,ans);
	}
    return 0;
}
