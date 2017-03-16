#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int T, N, M, ans, n = 0, a[10], b[10], m = 0;

inline bool	check(int x)
{
	for (int i = 1; i <= m; ++ i)
		if (b[i] == x) return 0;
	return 1;
}

inline int	work(int B)
{
	n = 0; m = 0;
	for (int x = B; x; x /= 10) a[++ n] = x % 10;
	for (int i = 1; i <= n / 2; ++ i)
	{
		int tmp = a[i]; a[i] = a[n - i + 1]; a[n - i + 1] = tmp;
	}
	for (int i = 2; i <= n; ++ i)
		if (a[i])
		{
			int x = 0;
			for (int j = i; j <= n; ++ j) x = x * 10 + a[j];
			for (int j = 1; j < i; ++ j) x = x * 10 + a[j];
			if (x >= N && x <= M && x < B && check(x)) b[++ m] = x;
		}
	return m;
}	

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d", &T);
	for (int t = 1; t <= T; ++ t)
	{
		printf("Case #%d: ", t);
		scanf("%d%d", &N, &M);
		ans = 0;
		for (int i = N; i <= M; ++ i)
			ans += work(i);
		printf("%d\n", ans);
	}
	return 0;
}
