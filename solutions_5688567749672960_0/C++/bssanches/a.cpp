#include <bits/stdc++.h>

using namespace std;
#define MAX 1000100

long long n;
int t;
int vis[MAX];

long long reverse(long long x)
{
	long long num = 0;
	while (x)
	{
		num *= 10;
		num += x%10;
		x /= 10;
	}

	return num;
}

int bfs(int curr)
{
	queue<int> q;
	q.push(curr);
	vis[curr] = 1;
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		if (v >= MAX)
			continue;
		if (v == n)
			break;
		int u = reverse(v);
		if (u < MAX && !vis[u])
		{
			vis[u] = vis[v] + 1;
			q.push(u);
		}
		u = v + 1;
		if (u < MAX && !vis[u])
		{
			vis[u] = vis[v] + 1;
			q.push(u);
		}
	}

	return vis[n];
}
int main(void)
{
	cin >> t;
	for (int cases = 1; cases <= t; ++cases)
	{
		cin >> n;
		memset(vis, 0, sizeof vis);
		int oper = bfs(1);

		// cout << curr << "\n";
		cout << "Case #" << cases <<": " << oper << "\n";
	}
	return 0;
}