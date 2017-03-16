
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

int cases;
int v[10000];
long long sum,ans;

bool cmp(int a,int b)
{
	return a>b;
}

 int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&cases);
	for(int i=0;i<cases;++i)
	{
		long long e,r,n;
		sum=0;
		scanf("%I64d%I64d%I64d",&e,&r,&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&v[i]);
			sum+=v[i];
		}
		std::sort(v,v+n,cmp);
		if(r<=e)ans=sum*r+(e-r)*v[0];
		else ans=sum*e;
		printf("Case #%d: %I64d\n",i+1,ans);
	}
}