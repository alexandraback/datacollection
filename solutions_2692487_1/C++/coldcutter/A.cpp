#include <cstdio>
#include <algorithm>

using namespace std;

int A, n, a[105], test;

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d", &A, &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = n;
		for (int remove = 0; A != 1 && remove <= n && remove <= ans; ++remove)
		{
			int now = A, cnt = 0;
			for (int i = 1; i <= n - remove; ++i)
				if (a[i] < now)
					now += a[i];
				else
				{
					++cnt;
					now += now - 1;
					while (now <= a[i])
					{
						now += now - 1;
						++cnt;
					}
					now += a[i];
				}
			if (remove + cnt < ans)
				ans = remove + cnt;
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	
	return 0;
}
