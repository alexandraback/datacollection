#include <cstdio>

const int N = 99;

int a[N], b[N];
int te;

bool possible(int n)
{
	if (n == 0)
		return true;
	for (int i = 1; i <= n; i++)
		if (b[i] == 0 && a[i] == 1)
		{
			b[i] = 1;
			bool f = possible(n - i);
			b[i] = 0;
			if (f)
				return true;
		}
	return false;
}

int main()
{
	scanf("%d", &te);
	for (int tn = 1; tn <= te; tn++)
	{
		int n, m;
		int x = 0;
		scanf("%*d%d%d", &n, &m);
		for (int i = 0; i < N; i++)
			a[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x] = 1;
		}
		for (int i = 1; i <= m; i++)
			if (a[i] == 0 && !possible(i))
			{
				a[i] = 1;
				++x;
			}
		printf("Case #%d: %d\n", tn, x);
	}

	return 0;
}