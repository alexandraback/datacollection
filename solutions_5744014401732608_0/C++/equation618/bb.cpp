#include <bits/stdc++.h>
using namespace std;

int N,S,M;
bool found=0;
bool b[55][55];

void init()
{
	scanf("%d%d",&N,&M);
}

void dfss(int u)
{
	if (u==N)
	{
		S++;
		return;
	}
	for (int i=1; i<=N; i++) if (b[u][i]) dfss(i);
}

int check()
{
	S=0;
	dfss(1);
	return S;
}

void dfs(int t)
{
	if (found) return;
	if (t==N)
	{
		if (check()==M)
		{
			puts("POSSIBLE");
			for (int i=1; i<=N; i++)
			{
				for (int j=1; j<=N; j++) printf("%d",b[i][j]);
				puts("");
			}
			found=1;
		}
		return;
	}
	int m=N-t;
	for (int i=0; i<1<<m; i++)
	{
		for (int j=0; j<m; j++) if ((i>>j)&1) b[t][t+j+1]=1;
		dfs(t+1);
		for (int j=0; j<m; j++) if ((i>>j)&1) b[t][t+j+1]=0;
	}
}

void doit()
{
	found=0;
	memset(b,0,sizeof(b));
	dfs(1);
	if (!found) puts("IMPOSSIBLE");
}

int main()
{
	freopen("B1.in","r",stdin);
	freopen("B2.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++)
	{
		init();
		printf("Case #%d: ",i);
		doit();
	}
	return 0;
}

