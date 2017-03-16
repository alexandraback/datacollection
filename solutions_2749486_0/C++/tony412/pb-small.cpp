#include <stdio.h>
#include <string.h>

int vst[50][205][205];
int from[50][205][205];
int fx, fy, ans, dpt;

int dfs(int n, int x, int y)
{
	if (x == fx && y == fy)
	{
		ans = n;
		return 1;
	}

	if (n >= dpt) return 0;

	if (x + n <= 200 && !vst[n][x+n][y])
	{
		vst[n+1][x+n][y] = 1;
		from[n+1][x+n][y] = 0;
		if (dfs(n+1, x+n, y)) return 1;
	}
	
	if (x - n >= 0 && !vst[n][x-n][y])
	{
		vst[n+1][x-n][y] = 1;
		from[n+1][x-n][y] = 1;
		if (dfs(n+1, x-n, y)) return 1;
	}

	if (y + n <= 200 && !vst[n][x][y+n])
	{
		vst[n+1][x][y+n] = 1;
		from[n+1][x][y+n] = 2;
		if (dfs(n+1, x, y+n)) return 1;
	}

	if (y - n >= 0 && !vst[n][x][y-n])
	{
		vst[n+1][x][y-n] = 1;
		from[n+1][x][y-n] = 3;
		if (dfs(n+1, x, y-n)) return 1;
	}
	return 0;
}

int main()
{
	int t, c = 1;
	int x, y, i;
	char out[51];

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &fx, &fy);

		fx += 100;
		fy += 100;
		
		for (dpt = 1; dpt < 50; dpt++)
		{
			memset(vst, 0, sizeof(vst));
			vst[1][100][100] = 1;
			if (dfs(1, 100, 100)) break;
		}
		i = ans;
		x = fx;
		y = fy;
		out[i-1] = 0;
		while (i > 1)
		{
//			printf("%d %d\n", x, y);
			switch(from[i][x][y])
			{
				case 0:
					out[i-2] = 'E';
//					putchar('E');
					x -= (i - 1);
					break;
				case 1:
					out[i-2] = 'W';
//					putchar('W');
					x += (i - 1);
					break;
				case 2:
					out[i-2] = 'N';
//					putchar('N');
					y -= (i - 1);
					break;
				case 3:
					out[i-2] = 'S';
//					putchar('S');
					y += (i - 1);
					break;
			}
			i--;
		}
		printf("Case #%d: %s\n", c++, out);
	}
	return 0;
}
