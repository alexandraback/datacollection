#include <stdio.h>

int seen[1001];

int dfs(int N, int *fw, int at, int prev, int start, int reverse)
{
	//printf("dfs(%d (%d) [%d], %s) = ...\n", at + 1, prev + 1, start + 1, reverse ? "<-" : "->");
	if(at == start && at != prev)
		return /*printf("cycle\n"),*/ 0;
	if(seen[at])
		return -1;
	seen[at] = 1;
	int max = -1;
	int i;
	if(reverse)
	{
		for(i = 0; i < N; i++)
			if(fw[i] == at)
			{
				int r = dfs(N, fw, i, at, start, 1);
				if(r > max)
					max = r;
			}
			else
			{
				int r = dfs(N, fw, i, at, start, 0);
				if(r > max)
					max = r;
			}
	}
	else
	{
		if(fw[at] == prev)
		{
			for(i = 0; i < N; i++)
				if(fw[i] == at)
				{
					int r = dfs(N, fw, i, at, start, 1);
					if(r > max)
						max = r;
				}
				else
				{
					int r = dfs(N, fw, i, at, start, 0);
					if(r > max)
						max = r;
				}
		}
		else
		{
			int r = dfs(N, fw, fw[at], at, start, 0);
			if(r > max)
				max = r;
		}
	}
	seen[at] = 0;
	//printf("... = %d\n",max == -1 ? -1 : max + 1);
	return max == -1 ? -1 : max + 1;
}

int main()
{
	int T;
	scanf("%d", &T);
	int test;
	for(test = 1; test <= T; test++)
	{
		int N;
		scanf("%d", &N);
		int bff[N];
		int i;
		for(i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			bff[i] = x - 1;
		}
		int max = -1;
		int start;
		for(start = 0; start < N; start++)
		{
			int r = dfs(N, bff, start, start, start, 0);
			if(r > max)
				max = r;
		}
		printf("Case #%d: %d\n", test, max);
	}
}
