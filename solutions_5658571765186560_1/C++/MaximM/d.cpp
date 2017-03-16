#include <cstdio>

bool b[22][22][22];
char fi[32] = "RICHARD", se[32] = "GABRIEL";
int tn;

int main()
{
	b[4][2][4] = true;
	b[4][2][6] = true;
	b[4][2][8] = true;
	b[4][2][10] = true;
	b[4][2][12] = true;
	b[4][2][14] = true;
	b[4][2][16] = true;
	b[4][2][18] = true;
	b[4][2][20] = true;
	b[5][3][5] = true;
	b[6][3][6] = true;
	b[6][3][8] = true;
	b[6][3][10] = true;
	b[6][3][12] = true;
	b[6][3][14] = true;
	b[6][3][16] = true;
	b[6][3][18] = true;
	b[6][3][20] = true;
	b[4][4][2] = true;
	b[5][5][3] = true;
	b[4][6][2] = true;
	b[6][6][3] = true;
	b[4][8][2] = true;
	b[6][8][3] = true;
	b[4][10][2] = true;
	b[6][10][3] = true;
	b[4][12][2] = true;
	b[6][12][3] = true;
	b[4][14][2] = true;
	b[6][14][3] = true;
	b[4][16][2] = true;
	b[6][16][3] = true;
	b[4][18][2] = true;
	b[6][18][3] = true;
	b[4][20][2] = true;
	b[6][20][3] = true;

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
		if (b[x][n][m])
			f = true;
		printf("Case #%d: %s\n", tc, f ? fi : se);
	}

	return 0;
}