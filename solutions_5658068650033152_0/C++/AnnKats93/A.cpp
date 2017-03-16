#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m, k;

bool brd[1005][1005];

bool seti(int x, int y)
{
	if (x >= 0 && y >= 0 && x < n && y < m)
	{
		brd[x][y] = 1;
		return 1;
	}
	return 0;
}

int main()
{
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d" ,&t);

	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d%d%d", &n, &m, &k);
		memset(brd, 0, sizeof(brd));

		if (n > m)
			swap(n, m);
		int x = n / 2, y = (m - 1) / 2;
		int cnt = seti(x, y);
		for (int r = 1; r <= 1000; r++)
		{
			if (cnt == k)
				break;
			for (int i = 1; i <= r && cnt < k; i++)
				cnt += seti(x - (r - i), y + i);
			if (cnt == k)
				break;
			for (int i = 1; i <= r && cnt < k; i++)
				cnt += seti(x + i, y + (r - i));
			if (cnt == k)
				break;
			for (int i = 1; i <= r && cnt < k; i++)
				cnt += seti(x + (r-i), y - i);
			if (cnt == k)
				break;
			for (int i = 1; i <= r && cnt < k; i++)
				cnt += seti(x - i, y - (r - i));
			if (cnt == k)
				break;
		}

		int ans = k;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (brd[i][j] && brd[i - 1][j] && brd[i + 1][j] && brd[i][j - 1] && brd[i][j + 1])
					ans--;
			}
		}
		printf("Case #%d: %d\n", tt + 1, ans);
	}
	

	return 0;
}