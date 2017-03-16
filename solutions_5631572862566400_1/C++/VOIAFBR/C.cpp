#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int maxn = 1024;

struct Edge
{
	int next;
	int to;
}edge[maxn * 2];

int num_case, ans1, ans2, bff[maxn], n, num_edge, head[maxn], cir[maxn], u, v, tmp;
bool visit[maxn], flag;

void add_edge(int from, int to)
{
	edge[++num_edge].next = head[from];
	edge[num_edge].to = to;
	head[from] = num_edge;
}

bool icheck(int now, int key, int dep)
{
	if (now == key) return 1;
	if (dep > n) return 0;
	return icheck(bff[now], key, dep + 1);
}

void DFS1(int now, int key, int dep)
{
	visit[now] = 1;
	cir[dep] = now;
	if (now == key && dep)
	{
		ans1 = max(ans1, dep);
		if (dep == 2)
		{
			flag = 1;
			u = cir[1];
			v = cir[2];
			return;
		}
	}
	for (int i = head[now]; i != 0; i = edge[i].next)
		if (!visit[edge[i].to] || edge[i].to == key)
			DFS1(edge[i].to, key, dep + 1);
	visit[now] = 0;
}

void DFS2(int now, int dep)
{
	visit[now] = 1;
	tmp = max(tmp, dep);
	for (int i = head[now]; i != 0; i = edge[i].next)
		if (!visit[edge[i].to])
			DFS2(edge[i].to, dep + 1);
	visit[now] = 0;
}

void DFS0(int now)
{
	visit[now] = 1;
	for (int i = head[now]; i != 0; i = edge[i].next)
		if (!visit[edge[i].to])
			DFS0(edge[i].to);
}

void calc(int now)
{
	if (!icheck(bff[now], now, 1)) return;
	flag = 0;
	DFS1(now, now, 0);
	if (flag)
	{
		tmp = 0;
		ans2 += 2;
		visit[v] = 1;
		DFS2(u, 0);
		visit[v] = 0;
		ans2 += tmp;
		tmp = 0;
		visit[u] = 1;
		DFS2(v, 0);
		visit[u] = 0;
		ans2 += tmp;
	}
	DFS0(now);
}

int main()
{
	freopen("C2.in", "r", stdin);
	freopen("C2.out", "w", stdout);
	scanf("%d", &num_case);
	for (int icase = 1; icase <= num_case; icase++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &bff[i]);
			add_edge(bff[i], i);
		}
		for (int i = 1; i <= n; i++)
			if (!visit[i])
				calc(i);
		printf("Case #%d: ", icase);
		printf("%d\n", max(ans1, ans2));
		ans1 = ans2 = num_edge = 0;
		for (int i = 1; i <= n; i++) head[i] = visit[i] = 0;
	}
	return 0;
}
