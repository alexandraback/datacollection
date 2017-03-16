#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

const int N = 1000;

struct Link
{
	int v;
	Link *next;
};
Link *g[N];
int cnt[N], n;
int que[N], hd, tl;
bool vis[N];
void inse(int u, int v)
{
	Link *p = new Link;
	p->v = v;
	p->next = g[u];
	g[u] = p;
	//printf("%d, %d\n", u, v);
}
bool check(int s)
{
	int u;
	Link *p;
	hd = tl = 0;
	que[tl++] = s;
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	cnt[s] = 1;
	vis[s] = true;
	while (hd != tl)
	{
		u = que[hd++];
		for (p = g[u]; p; p = p->next)
		{
			cnt[p->v] += cnt[u];
			if (cnt[p->v] >= 2)
				return true;
			if (!vis[p->v])
			{
				vis[p->v] = true;
				que[tl++] = p->v;
			}
		}
	}
	return false;
}
int main(void)
{
	int i, j, v;
	int T, c;
	int d;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (c = 1; c <= T; c++)
	{
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", &d);
			for (j = 0; j < d; j++)
			{
				scanf("%d", &v);
				inse(i, v - 1);
			}
		}
		for (i = 0; i < n; i++)
			if (check(i))
				break;
		if (i < n)
			printf("Case #%d: Yes\n", c);
		else
			printf("Case #%d: No\n", c);
	}
	return 0;
}
