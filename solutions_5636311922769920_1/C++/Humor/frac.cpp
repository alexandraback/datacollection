#include <cstdio>

const int N = 1010;
int n, k, c, s;
long long sol[N], f[N];

void solve(int test)
{
	scanf("%d %d %d", &k, &c, &s);
	n = 0;
	for (int i = 1; i <= k; i++) f[i] = false;
	for (int p = 1; p <= k; p++) if (!f[p])
	{
		long long y = p, x;
		f[p] = true;
		for (int i = 1; i < c; i++)
		{
			x = 1;
			for (int j = 1; j <= k; j++) if (!f[j]) x = j;
			f[x] = true;
			y = (y - 1) * k + x;				
		}
		sol[++n] = y;
	}
	printf("Case #%d: ", test);
	if (n > s) printf("IMPOSSIBLE"); else
	for (int i = 1; i <= n; i++) printf("%lld ", sol[i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}