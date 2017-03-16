#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int T, tcase, n, s, p, a[maxn], f[maxn][maxn];

bool calc(int num, int type)
{
	if (type == 0)  return (num + 2) / 3 >= p;
	if (num == 0)  return false;
	if (num % 3 == 0)  return num / 3 + 1 >= p;
	return (num / 3 + num % 3 >= p);
}
int main()
{
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	for (scanf("%d", &T), tcase = 1; tcase <= T; tcase ++)
	{
		scanf("%d%d%d", &n, &s, &p);
		for (int i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i ++)
		{
			bool v0 = calc(a[i], 0);
			bool v1 = calc(a[i], 1);
			for (int j = 0; j <= s; j ++)
			{
				if (v0)  f[i][j] = f[i - 1][j] + 1;
					else  f[i][j] = f[i - 1][j];
				if (j > 0 && v1)
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
			}
		}
		printf("Case #%d: %d\n", tcase, f[n][s]);
	}
	return 0;
}
