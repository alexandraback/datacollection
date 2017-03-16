#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 1010;
int p[N];
int cycle[N];
int maxLen[N];
int n;
bool used[N];

int getCycle(int v)
{
	for (int i = 0; i < n; i++)
		used[i] = false;
	int u = v;
	int len = 0;
	while(!used[u])
	{
		len++;
		used[u] = 1;
		u = p[u];
	}
	if (u == v) return len;
	return -1;
}

void setLenToCycle(int v)
{
	int len = 0;
	while(cycle[v] == -1)
	{
		len++;
		v = p[v];
	}
	maxLen[v] = max(maxLen[v], len);
	return;
}

int solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; i++)
	{
		cycle[i] = -1;
		maxLen[i] = 0;
	}
	for (int v = 0; v < n; v++)
		cycle[v] = getCycle(v);
	for (int v = 0; v < n; v++)
		setLenToCycle(v);
	int ans = 0;
	int c = 0;
	for (int v = 0; v < n; v++)
	{
		if (cycle[v] == -1) continue;
		if (cycle[v] < 2) throw;
		if (cycle[v] > 2)
			ans = max(ans, cycle[v]);
		else
		{
			int u = p[v];
			if (p[u] != v) throw;
			if (u < v) continue;
			c += 2 + maxLen[v] + maxLen[u];
		}
	}
	return max(ans, c);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
		printf("Case #%d: %d\n", i, solve());

	return 0;
}