#include <bits/stdc++.h>

using namespace std;

int vis[1001000];

int rev(int x)
{
	int res = 0;
	while (x)
	{
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++)
	{
		memset(vis, 0, sizeof(vis));

		int n;
		scanf("%d", &n);
		queue<int> q;
		q.push(0);
		int cnt = 0;
		vis[0] = true;
		bool flag = false;
		while (!flag)
		{
			cnt++;
			int m = q.size();
			for (int i = 0; i < m; i++)
			{
				int x = q.front();
				q.pop();
				if (x + 1 == n)
				{
					flag = true;
					break;
				} else
					if (x + 1 <= 1000000 && !vis[x + 1])
					{
						q.push(x + 1);
						vis[x + 1] = true;
					}
				int y = rev(x);
				if (y == n)
				{
					flag = true;
					 break;
				} else
					if (y <= 1000000 && !vis[y])
					{
						q.push(y);
						vis[y] = true;
					}
			}
		}
		printf("Case #%d: %d\n", ca, cnt);
	}

	return 0;
}