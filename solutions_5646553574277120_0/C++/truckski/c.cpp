#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int C,D,V;
int coin[101], v[101];

int __cnt=0;

int dfs(int x)
{
	int v_mask=(1<<(1+V))-1;
//	printf("%x %X\n",x,v_mask);
//	if(x==v_mask || __cnt++>100) return 0;
	if(x==v_mask) return 0;
	int min_ans=V+1;
	for(int i = 0; i <=V; i++)
	{
		if(x&(1<<i))continue;
		int y=1, z=0, X=x;
		for(int j = 1; j <= C; j++)
		{
			if(j*i<=min(30,V))
				y|=(1<<(j*i));
		}
		for(;X && y; X<<=1, X&=v_mask, y>>=1)
			if(y&1) z|=X;
//		int tmp=dfs(z);
//		min_ans=min(min_ans,tmp);
		min_ans=dfs(z);
		break;
	}
	return min_ans+1;
}

int solve()
{
	scanf("%d%d%d",&C,&D,&V);
	for(int i = 0; i < D; i++)
		scanf("%d",&coin[i]);
	for(int i = 1; i <= V; i++)
		v[i]=0;
	v[0]=1;
	for(int i = 0; i < D; i++)
		for(int j = V; j > 0; j--)
			for(int k = C; k > 0; k--)
				if(j-k*coin[i]>=0)
					v[j]|=v[j-k*coin[i]];
	int x=0;
	for(int i = 0; i <= (V); i++)
	{
//		printf("%d%c",v[i],i==V?'\n':' ');
		if(v[i]) x|=(1<<i);
	}
	return dfs(x);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i =1; i<=T; i++)
		printf("Case #%d: %d\n",i,solve());
	return 0;
}
