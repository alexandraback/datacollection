
#include <cstdio>
#include <cmath>
#include <algorithm>

int cases;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&cases);
	for(int i=0;i<cases;++i)
	{
		int a,n,s[100];
		scanf("%d%d",&a,&n);
		for(int j=0;j<n;++j)scanf("%d",&s[j]);
		std::sort(s,s+n);
		int ans=0,now=0;
		while(now<n)
		{
			if(a==1)
			{
				ans=n;
				break;
			}
			while(now<n && s[now]<a)a+=s[now++];
			if(now==n)break;
			int need=0;
			while(a<=s[now])
			{
				a=a*2-1;
				++need;
			}
			if(n-now<=need)
			{
				ans+=n-now;
				break;
			}
			ans+=need;
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
