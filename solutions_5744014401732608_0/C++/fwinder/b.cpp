#include <cstdio>
#include <cstring>

int n;
long long m;
long long a[100];

int main() {
	int T;
	scanf("%d\n", &T);
	a[1] = a[2] = 1;
	for (int i = 3; i < 50; ++i)
	{
		a[i] = 0;
		for (int j = i - 1; j > 0; --j)
			a[i] += a[j];
		// fprintf(stderr, "%lld ", a[i]);
	}

	for (int ttt = 1; ttt <= T; ++ttt)
	{
		printf("Case #%d: ", ttt);

		scanf("%d %lld\n", &n, &m);
		if (a[n] < m)
		{
			printf("IMPOSSIBLE\n");
			continue;
		}

		printf("POSSIBLE\n");

		int b[100];
		for (int i = 1; i <= n; ++i)
			b[i] = 0;
		for (int i = n - 1; i; --i)
			if (m >= a[i])
			{
				m -= a[i];
				b[i] = 1;
			}

		for (int i = 1; i < n; ++i)
		{
			for (int j = 1; j <= i; ++j)
				printf("0");
			for (int j = i + 1; j < n; ++j)
				printf("1");
			printf("%d\n", b[i]);
		}
		for (int j = 1; j <= n; ++j)
			printf("0");
		printf("\n");
	}

	return 0;
}