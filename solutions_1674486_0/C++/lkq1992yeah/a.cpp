#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

#define MAXN 2020
#define MAXM 100010

int pt[MAXM], next[MAXM], head[MAXN], pos;

void AddEdge(int a, int b)
{
	pt[++pos] = b;
	next[pos] = head[a];
	head[a] = pos;
}

int pa[MAXN], n;
int visit[MAXN];
/*
void init()
{
	for (int i = 1; i <= n; i++)
		pa[i] = i;
}

int find(int x)
{
	if (x != pa[x])
		pa[x] = find(pa[x]);
	return pa[x];
}

void Union(int a, int b)
{
	int ra = find(a), rb = find(b);
	pa[ra] = rb;
}
*/
void dfs(int x)
{
	//printf("x = %d\n", x);
	int e;
	for (e = head[x]; e != -1; e = next[e])
	{
		//printf("	pt[e] = %d\n", pt[e]);
		visit[pt[e]]++;
		dfs(pt[e]);
	}
}

void Solve()
{
	int i, j, c, x, flag = 0;
	scanf("%d", &n);
	pos = -1;
	memset (head, -1, sizeof head);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &c);
		while (c--)
		{
			scanf("%d", &x);
			AddEdge(x, i);
		}
	}
	for (i = 1; i <= n; i++)
	{
		memset (visit, 0, sizeof visit);
		visit[i]++;
		dfs(i);
		for (j = 1; j <= n; j++)
			if (visit[j] >= 2)
			{
				flag = 1;
				break;
			}
		if (flag == 1)
			break;
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
}

int main()
{
	int cas;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++)
	{
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
