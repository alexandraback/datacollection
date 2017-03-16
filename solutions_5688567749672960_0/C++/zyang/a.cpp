#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 10000000
int f[MAXN][2];
bool vis[MAXN];

int main()
{
	FILE *fin = fopen("a.in", "r");
	FILE *fout = fopen("a.txt", "w");

	int T;
	fscanf(fin, "%d", &T);

	for (int testCase = 1; testCase <= T; testCase++)
	{
		int n;
		fscanf(fin, "%d", &n);

		if (n == 1)
		{
			fprintf(fout, "Case #%d: %d\n", testCase, 1);
			continue;
		}

		memset(vis, 0, sizeof(vis));

		int x = -1, y = 0;
		f[0][0] = 1;
		f[0][1] = 1;
		vis[1] = true;

		while (x < y)
		{
			x++;

			y++;
			int val = f[x][0] + 1;
			if (vis[val])
				y--;
			else
			{
				vis[val] = true;
				f[y][0] = val;
				f[y][1] = f[x][1] + 1;
				if (val == n)
					break;
			}

			y++;
			val = 0;
			while (f[x][0] > 0)
			{
				val = val * 10 + (f[x][0] % 10);
				f[x][0] /= 10;
			}

			if (vis[val])
				y--;
			else
			{
				vis[val] = true;
				f[y][0] = val;
				f[y][1] = f[x][1] + 1;
				if (val == n)
					break;
			}
		}

		fprintf(fout, "Case #%d: %d\n", testCase, f[y][1]);
	}

	return 0;
}
