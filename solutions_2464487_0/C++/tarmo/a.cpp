#include<cstdio>
#define md ((ll+rr)/2)
long long r,t;
bool check(long long x)
{
	if((2*r+2*x-1)>(t/x))return 0;
	else return 1;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%I64d%I64d",&r,&t);
		long long ll=1,rr=1e18;
		while(ll<rr)
		{
			if(check(md))ll=md+1;
			else rr=md;
		}
		printf("Case #%d: %I64d\n",tt,ll-1);
	}
}