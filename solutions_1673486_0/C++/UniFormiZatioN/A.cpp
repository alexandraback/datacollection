#include<stdio.h>
#include<string.h>
#define A_max 3
double p[A_max],key[A_max+2];
int a,b;
bool corr[A_max];
void dfs(int now)
{
	if(now==a)
	{
		double poss=1.0;
		int i,j=0;
		for(i=0;i<a;i++)
			if(corr[i]) poss=poss*p[i];
			else poss=poss*(1-p[i]),j++;
		for(i=0;i<=a;i++)
			if(j)
			{
				key[i]+=poss*(i+i+b-a+b+2);
				if(!corr[a-1-i]) j--;
			}
			else key[i]+=poss*(i+i+b-a+1);
		return;
	}
	corr[now]=1;
	dfs(now+1);
	corr[now]=0;
	dfs(now+1);
}
main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.txt","w",stdout);
	int testcase,t,i;
	double k;
	scanf("%d",&testcase);
	for(t=1;t<=testcase;t++)
	{
		scanf("%d %d",&a,&b);
		for(i=0;i<a;i++) scanf("%lf",p+i);
		memset(key,0,sizeof(key));
		dfs(0);
		key[a+1]=b+2;
		k=100000000;
		for(i=0;i<=a+1;i++)
			if(key[i]<k) k=key[i];
		printf("Case #%d: %.6lf\n",t,k);
	}
}
