#include <bits/stdc++.h>
using namespace std;

int mat[10][10], ret, dp[10];
int B, M;

int count(int v)
{
	if (v == B-1) return 1;
	if (dp[v] == -1)
	{
		dp[v] = 0;
		for (int i = v+1; i < B; i++)
			if (mat[v][i]) dp[v] += count(i);
	}
	return dp[v];
}

void solve(int pos, int sz)
{
	if (ret) return;
	if (sz < 0)
	{
		memset(dp,-1,sizeof(dp));
		if (count(0) == M)
			ret = 1;
	}
	else
	{
		for (int i = 0; i < 1<<sz && !ret; i++)
		{
			for (int j = pos+1; j < B; j++)
				if (i & (1<<(j-(pos+1))))
					mat[pos][j] = 1;
				else
					mat[pos][j] = 0;
			solve(pos+1,sz-1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		
		scanf("%d %d", &B, &M);
		memset(mat,0,sizeof(mat));
		ret = 0;
		solve(0,B-1);
		printf("Case #%d: %sPOSSIBLE\n", t, ret?"":"IM");
		if (ret)
		{
			for (int i = 0; i < B; i++)
			{
				for (int j = 0; j < B; j++)
					printf("%d", mat[i][j]);
				printf("\n");
			}
		}
	}
}
