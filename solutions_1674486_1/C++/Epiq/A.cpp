#include <cstdio>
#include <iostream>
#include <cstring>
#define Max 1000
using namespace std;

int T;
int N, M;
int Next[Max][Max], next[Max];
int V[Max];

bool Go (int v)
{
	V[v]++;
	if (V[v] > 1)
	{
		return true;
	}
	for (int i = 0; i < next[v]; i++)
	{
		if (Go(Next[v][i])) return true;
	}
	return false;
}

int main()
{
	//freopen("A.in", "r", stdin);
	scanf("%d", &T);
	for (int test = 0; test < T; test++)
	{
		memset(next, 0, sizeof(next));
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int m, t;
			scanf("%d", &m);
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &t);
				Next[i][next[i]++] = t - 1;
			}
		}
		bool ok = false;
		for (int i = 0; i < N; i++)
		{
			memset(V, 0, sizeof(V));
			if (Go(i))
			{
				ok = true;
				break;
			}
		}
		printf("Case #%d: ", test + 1);
		if (ok)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
