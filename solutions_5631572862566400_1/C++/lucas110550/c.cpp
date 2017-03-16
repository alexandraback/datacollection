#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

int tot = 1;
int g[100001], nxt[100001], e[100001];

void add(int u, int v)
{
	e[tot] = v; nxt[tot] = g[u]; g[u] = tot ++;
}

int n, p[10001];
bool vis[10001];
int d[10001], q[10001];
int tp = 0;

void Work()
{
	tot = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) g[i] = 0;
	for (int i = 1; i <= n; i ++)
		scanf("%d", &p[i]), add(i, p[i]);
	int ans = 0, cnt = 0;
	for (int i = 1; i <= n; i ++)
	{
		int h = 0, t = 1;
		for (int j = 1; j <= n; j ++) vis[j] = false, d[j] = 0;
		vis[i] = true;
		q[t] = i; d[i] = 0;
		while (h < t)
		{
			int k = q[++ h];
			for (int i = g[k]; i; i = nxt[i])
			{
				if (vis[e[i]]) continue;
				vis[e[i]] = true;
				d[e[i]] = d[k] + 1;
				q[++ t] = e[i];
			}
		}
		for (int j = 1; j <= n; j ++)
		{
			if (!vis[j]) continue;
			if (p[j] == i) ans = max(ans, d[j] + 1);
		}
	}
	tot = 1;
	for (int i = 1; i <= n; i ++) g[i] = 0;
	for (int i = 1; i <= n; i ++) add(p[i], i);
	for (int i = 1; i <= n; i ++)
		if (p[p[i]] == i)
		{
			int cnt1 = 0, cnt2 = 0;
			int h = 0, t = 1;
			for (int j = 1; j <= n; j ++) vis[j] = false, d[j] = 0;
			vis[i] = vis[p[i]] = true;
			q[t] = i; d[i] = 0;
			while (h < t)
			{
				int k = q[++ h];
				for (int i = g[k]; i; i = nxt[i])
				{
					if (vis[e[i]]) continue;
					vis[e[i]] = true;
					d[e[i]] = d[k] + 1;
					q[++ t] = e[i];
				}
			}
			for (int j = 1; j <= n; j ++) cnt1 = max(cnt1, d[j]);
			h = 0, t = 1;
			for (int j = 1; j <= n; j ++) vis[j] = false, d[j] = 0;
			vis[i] = vis[p[i]] = true;
			q[t] = p[i]; d[p[i]] = 0;
			while (h < t)
			{
				int k = q[++ h];
				for (int i = g[k]; i; i = nxt[i])
				{
					if (vis[e[i]]) continue;
					vis[e[i]] = true;
					d[e[i]] = d[k] + 1;
					q[++ t] = e[i];
				}
			}
			for (int j = 1; j <= n; j ++) cnt2 = max(cnt2, d[j]);
			cnt += cnt1 + cnt2 + 2;
	}
	printf("Case #%d: %d\n", tp, max(ans, cnt / 2));
}
int main( )
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		++ tp;
		Work();
	}
	return 0;
}
