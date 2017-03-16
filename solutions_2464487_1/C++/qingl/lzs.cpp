#include<cstdio>
#include<cstring>
typedef unsigned __int64 ull;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	ull r,t;
	int ca=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64u%I64u",&r,&t);
		ull ret;
		r=r+r+1;
		if(t<r)
		{
			ret=0;
		}
		else
		{
			ull low=0,high=t+1,mid;
			while(low<high-1)
			{
				mid=(low+high)/2;
				if(r+mid+mid<=t/(mid+1))low=mid;
				else high=mid;
			}
			ret=low+1;
		}
		printf("Case #%d: %I64u\n",ca++,ret);
	}
	return 0;
}