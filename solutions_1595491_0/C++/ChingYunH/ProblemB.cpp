#include <cstdio>
#include <algorithm>
int main()
{
	freopen("inputB.in","r",stdin);
	freopen("outputB.out","w",stdout);
	int cn,ti,surp,t,n,i,s,p,ans,lim1,lim2;
	scanf("%d",&t);
	for(cn=1;cn<=t;cn++)
	{
		ans = surp = 0;
		scanf("%d%d%d",&n,&s,&p);
		lim1 = 3*p-2;
		if(p == 0) lim1 = 0;
		lim2 = 3*p-4;
		if(p == 1) lim2 = lim1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&ti);
			if(ti >= lim1)
				ans++;
			else if(ti >= lim2)
				surp++;
		}
		ans += std::min(surp,s);
		printf("Case #%d: %d\n",cn,ans);	
	}	
}
