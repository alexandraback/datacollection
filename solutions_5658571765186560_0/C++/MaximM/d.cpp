#include <cstdio>

char fi[32] = "RICHARD", se[32] = "GABRIEL";
int tn;

int main()
{
	scanf("%d", &tn);

	for (int tc = 1; tc <= tn; tc++)
	{
		int x, n, m;
		scanf("%d%d%d", &x, &n, &m);
		if (m > n)
		{
			int z;
			z = n, n = m, m = z;
		}
		int side1 = x / 2 + 1, side2 = (x + 1) / 2;
		bool f = false;
		if (x >= 7 || side1 > n || side2 > m || (x > n && x > m) || ((n * m) % x != 0))
			f = true;
		if (x == 4 && n == 4 && m == 2)
			f = true;
		printf("Case #%d: %s\n", tc, f ? fi : se);
	}

	return 0;
}