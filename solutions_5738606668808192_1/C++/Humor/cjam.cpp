#include <cstdio>

const int D = 11, N = 110;
int n, x, s[N], o[D][N];

int ost(int b)
{
	int r = 0;
	for (int j = 0; j < n; j++) r = (r + s[j] * o[b][j]) % D;
	return r;
}

void solve()
{
	scanf("%d %d", &n, &x);
	s[0] = s[n - 1] = 1;
	printf("Case #1:\n");
	int z = 0;
	for (int i = 0; i < 1 << n - 2; i++)
	{
		bool f = true;
		for (int j = 1; j < n - 1; j++) s[j] = i >> j - 1 & 1;
		for (int j = 2; j <= 10; j++) if (ost(j))
		{
			f = false;
			break;
		} 
		if (!f) continue;
		for (int j = n - 1; j >= 0; j--) printf("%d", s[j]);
		for (int j = 0; j < 9; j++) printf(" %d", D);
		printf("\n");
		z++;
		if (z == x) break;
	}
}

void pre()
{
	for (int i = 2; i <= 10; i++)
	{
		o[i][0] = 1;
		for (int j = 1; j < N; j++) o[i][j] = o[i][j - 1] * i % D;
	}
}

int main()
{
	pre();
	int t;
	scanf("%d", &t);
	solve();
	return 0;
}