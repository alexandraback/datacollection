#include <cstdio>
#include <cstring>

int main()
{
	freopen("2in.txt", "r", stdin);
	freopen("2out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		int n;
		scanf("%d", &n);
		int a[1010];
		int max0 = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			if (a[i] > max0) max0 = a[i];
		}
		int ans = max0;
		for (int i = 1; i <= max0; ++i)
		{
			int tmp = i;
			for (int j = 0; j < n; ++j)
				tmp += (a[j] + i - 1) / i - 1;
			if (tmp < ans) ans = tmp;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
