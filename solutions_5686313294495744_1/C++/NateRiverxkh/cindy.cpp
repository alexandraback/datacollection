
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
#define maxn 2010
#define maxe 201010

struct node{
	int u, v, next;
}edge[maxe];
int head[maxn], add, n, m;
void adj(int u, int v)
{
	edge[add].v = v; edge[add].next = head[u]; head[u] = add++;
}

int match1[maxn], match2[maxn], vis[maxn];
int makepair(int t)
{
	for (int i = head[t]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		if (!vis[v])
		{
			vis[v] = 1;
			if (match2[v] == -1 || makepair(match2[v]))
			{
				match1[t] = v;
				match2[v] = t;
				return 1;
			}
		}
	}
	return 0;
}

int solve(int n1, int n2)
{
	int i, j, tot = 0;
	memset(match1, -1, sizeof(match1));
	memset(match2, -1, sizeof(match2));
	for (i = 1; i <= n1; i++)
	{
		if (match1[i])
		{
			memset(vis, 0, sizeof(vis));
			if (makepair(i))
				tot++;
		}
	}
	return tot;
}

char s1[1000];
char s2[1000];
int main()
{
	int i, j, ncase, tt = 0;
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d", &m);
		int a = 0, b = 0;
		map<string, int>m1;
		m1.clear();
		map<string, int>m2;
		m2.clear();
		memset(head, -1, sizeof(head));
		add = 0;
		for (int i = 0; i<m; i++)
		{
			scanf("%s", s1);
			scanf("%s", s2);

			string ss1 = s1;
			string ss2 = s2;
			if (m1.find(ss1) == m1.end())
				m1[ss1] = ++a;
			if (m2.find(ss2) == m2.end())
				m2[ss2] = ++b;
			adj(m1[ss1], m2[ss2]);
		}

		int ans = m - a - b + solve(a, b);
		printf("Case #%d: %d\n", ++tt, ans);
	}
	return 0;
}
