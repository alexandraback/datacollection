#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

int n, m, k;

int tb[6][30];

int main()
{
	int t, cas;
	scanf("%d", &t);
	int i;
	for (i = 5; i <= 9; i++) tb[0][i] = i - 1;
	
	for (i = 5; i <= 7; i++) tb[1][i] = i - 1;
	for (i = 8; i <= 12; i++) tb[1][i] = i - 2;
	
	for (i = 5; i <= 7; i++) tb[2][i] = i - 1;
	for (i = 8; i <= 10; i++) tb[2][i] = i - 2;
	for (i = 11; i <= 15; i++) tb[2][i] = i - 3;
	
	for (i = 5; i <= 7; i++) tb[3][i] = i - 1;
	for (i = 8; i <= 10; i++) tb[3][i] = i - 2;
	for (i = 11; i <= 13; i++) tb[3][i] = i - 3;
	for (i = 14; i <= 18; i++) tb[3][i] = i - 4;
	
	for (i = 5; i <= 9; i++) tb[4][i] = tb[3][i];
	tb[4][10] = 7; tb[4][11] = 8;
	for (i = 12; i <= 16; i++) tb[4][i] = i - 4;
	
	for (i = 5; i <= 14; i++) tb[5][i] = tb[4][i];
	tb[5][14] = 9;	tb[5][15] = 10;
	for (i = 16; i <= 20; i++) tb[5][i] = i - 6;
	
	// for (i = 0; i <= 5; i++)
	// {
		// for (int j = 5; j <= 20; j++) printf("%d ", tb[i][j]); printf("\n");
	// }
	
	for (cas = 1; cas <= t; cas++)
	{
		int ans = 0, tmp = 0;
		scanf("%d%d%d", &n, &m, &k);
		if (n > m) { tmp = n; n = m; m = tmp; }
		if (k <= 4 || n <= 2)
			ans = k;
		else
		{
			if (n == 3 && m == 3) ans = tb[0][k];
			if (n == 3 && m == 4) ans = tb[1][k];
			if (n == 3 && m == 5) ans = tb[2][k];
			if (n == 3 && m == 6) ans = tb[3][k];
			if (n == 4 && m == 4) ans = tb[4][k];
			if (n == 4 && m == 5) ans = tb[5][k];
		}
		// else
		// {
			// ans = k;
			// int un = n - 2, um = m - 2;
			// int i, j;
			// for (i = 1; i <= un; i++)
			// {
				// for (j = 1; j <= um; j++)
				// {
					// int baseArea = i * j + 2 * (i + j);
					// if (baseArea >= k) tmp = 2 * (i + j);
					// else
						// tmp = 2 * (i + j) + k - baseArea;
					// // printf("i = %d, j = %d, baseArea = %d, k = %d, tmp = %d\n", i, j, baseArea, k, tmp);
					// ans = min(ans, tmp);
				// }
			// }
		// }
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
