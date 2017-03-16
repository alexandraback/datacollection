#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T,t,N,ans,a[15],b[15],now[15],pow3[15],flag[60000];

void Dfs(int x,int y,int t)
{
	if (flag[y]<=t) return;
	flag[y]=t;
	if (x==2*N)
	{
		ans=min(ans,t);
		return;
	}
	for (int i=1;i<=N;i++) 
		if (x>=b[i] && now[i]==0)
		{
			now[i]=2;
			Dfs(x+2,y+pow3[i-1]*2,t+1);
			now[i]=0;
		} else
		if (x>=b[i] && now[i]==1)
		{
			now[i]=2;
			Dfs(x+1,y+pow3[i-1],t+1);
			now[i]=1;
		} else
		if (x>=a[i] && now[i]==0)
		{
			now[i]=1;
			Dfs(x+1,y+pow3[i-1],t+1);
			now[i]=0;
		}
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	pow3[0]=1;
	for (int i=1;i<=10;i++) pow3[i]=pow3[i-1]*3;
	scanf("%d",&T);
	for (;T>0;T--)
	{
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
			scanf("%d%d",&a[i],&b[i]);
		ans=2100000000;
		memset(flag,127,sizeof flag);
		memset(now,0,sizeof now);
		Dfs(0,0,0);
		if (ans==2100000000) 
			printf("Case #%d: Too Bad\n",++t);
		else
			printf("Case #%d: %d\n",++t,ans);
	}
	return 0;
}
