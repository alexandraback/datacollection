#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

using namespace std;

int sup(int v)
{
	if (v <= 2)
		return -1;
	int a = v / 3,
		b = v % 3;

	if (b == 2)
		return a + 2;
	if (b == 0)
		return a + 1;
	if (b == 1)
		return a + 1;
	assert(0);
}

int nsup(int v)
{
	int a = v / 3,
		b = v % 3;
	int c[3] = {a, a + 1, a + 1};
	return c[b];
}

void solve(int id)
{
	if (id == 4)
		int asdf = 0;
	int n, s, p, sc[101] = {0}, f[101][101];
	memset(f, 0, sizeof(f));
	scanf("%d%d%d", &n, &s, &p);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &sc[i]);
	f[1][1] = (sup(sc[1]) >= p);
	f[1][0] = (nsup(sc[1]) >= p);
	for (int i = 2; i <= n; i ++)
		for (int j = 0; j <= min(i, s); j ++)
		{
			f[i][j] = f[i - 1][j] + (nsup(sc[i]) >= p);
			if (j)
				f[i][j] = max(f[i][j], f[i - 1][j - 1] + (sup(sc[i]) >= p));
		}
	printf("%d\n", f[n][s]);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i ++)
	{
		printf("Case #%d: ", i);
		solve(i);
	}
	return 0;
}

