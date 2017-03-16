#include<cstdio>
#include<cstring>
int g[210][22],a[22];
int tes,k,n,d[1100000],nex[1100000];
int dp(int st)
{
	if(d[st]!=-1)	return d[st];
	if(st==(1<<n)-1)	return d[st]=1;
	for(int i=0;i<n;++i)if(((st>>i)&1)^1)
	{
		int num=g[n][a[i]];
		for(int j=0;j<n;++j)if((st>>j)&1){
			num+=g[j][a[i]];
			num-=(a[i]==a[j]);
		}
		if(num<=0)	continue;
		if(!dp(st|(1<<i)))	continue;
		nex[st]=i;
		return d[st]=1;
	}
	return d[st]=0;
}
int main()
{
	//freopen("D-small-attempt0.in","r",stdin);
	//freopen("D-small-attempt0.out","w",stdout);
	scanf("%d",&tes);
	for(int h=1;h<=tes;++h)
	{
		memset(g,0,sizeof(g));
		scanf("%d %d",&k,&n);
		int x;
		while(k--)
		{
			scanf("%d",&x);
			g[n][x]++;
		}
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&x);
				g[i][x]++;
			}
		}
		memset(d,-1,sizeof(d));
		printf("Case #%d: ",h);
		if(!dp(0))
			puts("IMPOSSIBLE");
		else
		{
			for(int i=0;i!=(1<<n)-1;i|=(1<<nex[i]))
			{
				if(i)	putchar(' ');
				printf("%d",nex[i]+1);
			}
			puts("");
		}
	}
	return 0;
}