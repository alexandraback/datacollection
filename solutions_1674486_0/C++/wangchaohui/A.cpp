#include <stdio.h>
#include <string.h>

int N;
int M[1000];
int d[1000][10];

int f[1000];



int dfs(int x)
{
	int i;
	for(i=0;i<M[x];i++)
	{
		int y=d[x][i];
		if(f[y])return 1;
		f[y]=1;
		if(dfs(y))return 1;
	}
	return 0;
}

int solve()
{
	int i,j;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%d",&M[i]);
		for(j=0;j<M[i];j++)
		{
			scanf("%d",&d[i][j]);
			d[i][j]--;
		}
	}
	for(i=0;i<N;i++)
	{
		memset(f,0,sizeof(f));
		if(dfs(i))return 1;
	}
	return 0;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,Tc=0;
	scanf("%d",&T);
	while(++Tc<=T)
	{
		printf("Case #%d: ",Tc);
		if(solve())
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}
