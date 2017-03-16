#include <cstdio>

int g[1001][1001];
int M[1000];
bool w[1000], b;

void dfs(int v)
{
	int i;

	if (!w[v])
	{
		w[v] = true;
		for (i = 0; i < M[v]; i++)
		{
			dfs(g[v][i]);
		}
	}
	else
	{
		b = true;
	}
}

int main()
{
	int T, test, N, i, j;

	scanf("%d", &T);
	for(test = 1; test <= T; test++)
	{
		scanf("%d", &N);
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &M[i]);
			for (j = 0; j < M[i]; j++)
			{
				scanf("%d", &g[i][j]);
			}
		}

		b = false;
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j <= N; j++)
			{
				w[j] = false;
			}

			dfs(i);
			if (b)
			{
				break;
			}
		}

		printf("Case #%d: %s\n", test, b ? "Yes" : "No");
	}

	return 0;
}
