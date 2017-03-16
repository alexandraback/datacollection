#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int a[10005];
int n,r,e;
int ans;
void dfs(int id,int en,int tmp)
{
	if(id>n)
	{
		ans=max(ans,tmp);
		return ;
	}
	for(int i=0;i<=en;i++)
	{
		dfs(id+1,min(e,en-i+r),tmp+i*a[id]);
	}

}
int main()
{
	int t,d=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&e,&r,&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ans=0;
		dfs(1,e,0);
		printf("Case #%d: %d\n",d++,ans);
	}
	return 0;
}

