#include <cstdio>
#include <cstring>

const int maxn = 1005;

int test, n, a[maxn], b[maxn], now, ans, cnt, max;
bool mark[maxn][2];

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d %d", &a[i], &b[i]);
		
		now = ans = cnt = 0;
		memset(mark, 0, sizeof(mark));
		while (cnt < n)
		{
			bool flag = 0;
			for (int i = 1; i <= n; ++i)
				if (!mark[i][0] && !mark[i][1] && now >= b[i])
				{
					mark[i][1] = 1;
					now += 2;
					flag = 1;
					++cnt;
					++ans;
				}
			if (!flag)
			{
				for (int i = 1; i <= n; ++i)
					if (mark[i][0] && !mark[i][1] && now >= b[i])
					{
						mark[i][1] = 1;
						now += 1;
						flag = 1;
						++cnt;
						++ans;
					}
			}
			if (!flag)
			{
				int k;
				max = -1;
				for (int i = 1; i <= n; ++i)
					if (!mark[i][0] && !mark[i][1] && now >= a[i] && b[i] > max)
						max = b[i], k = i;
				if (max == -1)
					break;
				now += 1;
				flag = 1;
				++ans;
				mark[k][0] = 1;
			}
			if (!flag)
				break;
		}
		if (cnt < n)
			printf("Case #%d: Too Bad\n", kase);
		else
			printf("Case #%d: %d\n", kase, ans);
	}
	
	return 0;
}
