#include <cstdio>
int p[1000],T,d;
int main()
{
	int ans,cnt,max;
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("%d",&d);
		max=0;
		for(int i=0;i<d;i++)
		{
			scanf("%d",p+i);
			if(p[i]>max) max=p[i];
		}
		ans=max;
		while(--max)
		{
			cnt=0;
			for(int i=0;i<d;i++) if(p[i])
				cnt+=(p[i]-1)/max;
			if(max+cnt<ans) ans=max+cnt;
		}
		printf("Case #%d: %d\n",j,ans);
	}
	return 0;
}
