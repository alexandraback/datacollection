#include <cstdio>

const int N = 1000 + 10;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d", &n);
		int sum = 0;
		for(int i = 0; i <= n; i++)
		{
			scanf("%1d", &a[i]);
			sum += a[i];
		}
		int now = a[0];
		for(int i = 1; i <= n; i++) if(a[i])
		{
			if(now >= i) now += a[i];
			else now = i + a[i];
		}
		printf("Case #%d: %d\n", cas, now - sum);
	}
	return 0;
}
