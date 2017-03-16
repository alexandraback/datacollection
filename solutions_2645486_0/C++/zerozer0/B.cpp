#include <stdio.h>
#include <stdlib.h>
int a[21],E,R,n,ans;
int cmp(const void *p,const void *q)
{
	return *(int *)p-*(int *)q;
}
void dfs(int deep,int now,int value)
{
	int i=0,tmp;
	if(deep==n+1)
	{
		if(value>ans)
			ans=value;
		return ;
	}
	for(i=0;i<=now;i++)
	{
		tmp=now-i+R;
		if(tmp>E)
			tmp=E;
		dfs(deep+1,tmp,value+i*a[deep]);
	}

}
int main()
{	
	int t,i,test=0;
//	freopen("B-small-attempt0.in","r",stdin);
//	freopen("Bs.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&E,&R,&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		dfs(1,E,0);
		printf("Case #%d: %d\n",++test,ans);
	}

	return 0;
}