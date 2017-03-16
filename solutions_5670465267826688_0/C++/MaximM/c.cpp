#include <cstdio>

typedef long long ll;

const int N = 10010;

const int A[4][4] = 
{
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};
const int SIGN[4][4] = 
{
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

ll x, len;
int a[N], tn, n, i, c, g;
char s[N];

void mult(int c1, int c2)
{
	c = A[c1][c2];
	g = g ^ SIGN[c1][c2];
}

int main()
{
	scanf("%d", &tn);

	for (int tc = 1; tc <= tn; tc++)
	{
		scanf("%d%lld%s", &n, &x, s);
		for (i = 0; i < n; i++)
			a[i] = (s[i] == 'i' ? 1 : s[i] == 'j' ? 2 : 3);
		len = x * n;
		c = 0;
		g = 0;
		bool f = false, f1 = false, f2 = false;
		for (i = 0; i < len; i++)
		{
			mult(c, a[i % n]);
			if (c == 1 && g == 0)
				f1 = true;
			if (f1 && c == 3 && g == 0)
				f2 = true;
		}
		if (f2 && c == 0 && g == 1)
			f = true;
		printf("Case #%d: %s\n", tc, f ? "YES" : "NO");
	}

	return 0;
}