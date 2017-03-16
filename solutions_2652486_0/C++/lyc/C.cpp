#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T, r, n, m, k;
int p[100][10], mul[100][200], x[10];

int main()
{
	scanf("%d%d%d%d%d", &T, &r, &n, &m, &k);
	for(int i1 = 2, i = 1; i1 <= m; i1++)
		for(int i2 = 2; i2 <= m; i2++)
			for(int i3 = 2; i3 <= m; i3++, i++)
			{
				p[i][1] = i1;
				p[i][2] = i2;
				p[i][3] = i3;
			}
	memset(mul, 0, sizeof(mul));
	for (int i = 1; i <= 64; i++)
	{
		mul[i][1]++;
		mul[i][p[i][1]]++;
		mul[i][p[i][2]]++;
		mul[i][p[i][1] * p[i][2]]++;
		mul[i][p[i][3]]++;
		mul[i][p[i][1] * p[i][3]]++;
		mul[i][p[i][2] * p[i][3]]++;
		mul[i][p[i][1] * p[i][2] * p[i][3]]++;
	}
	puts("Case #1:");
	while (r--)
	{
		for (int i = 1; i <= k; i++)
			scanf("%d", &x[i]);
		int z = 1;
		int ret = 0;
		for (int j = 1; j <= 64; j++)
		{
			int rr = 1;
			for (int i = 1; i <= k; i++)
				rr *= mul[j][x[i]];
			if (rr > ret)
			{
				z = j;
				ret = rr;
			}
		}
		printf("%d%d%d\n", p[z][1], p[z][2], p[z][3]);
	}
	return 0;
}
