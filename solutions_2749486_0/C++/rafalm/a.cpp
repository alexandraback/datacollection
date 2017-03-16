#include <cstdio>
#include <cstring>

int X, Y;
bool end, b[500][500][100];
char path[500 + 1], rpath[500+1];

void dfs(int y, int x, int step)
{
	if (end) return;

	if (x == X && y == Y)
	{
		memcpy(rpath, &path[1], step);
		rpath[step-1] = '\0';
		end = true;
		return;
	}

	if (step < 30)
	{
		//N
		if (y + step < 500 && !b[y+step][x][step])
		{
			path[step] = 'N';
			b[y+step][x][step] = true;
			dfs(y+step, x, step+1);
		}
		//S
		if (y - step >= 0 && !b[y-step][x][step])
		{
			path[step] = 'S';
			b[y-step][x][step] = true;
			dfs(y-step, x, step+1);
		}
		//E
		if (x + step < 500 && !b[y][x+step][step])
		{
			path[step] = 'E';
			b[y][x+step][step] = true;
			dfs(y, x+step, step+1);
		}
		//W
		if (x - step >= 0 && !b[y][x-step][step])
		{
			path[step] = 'W';
			b[y][x-step][step] = true;
			dfs(y, x-step, step+1);
		}
	}
}

int main()
{
	int T, test;

	scanf("%d", &T);

	for (test = 1; test <= T; test++)
	{
		scanf("%d", &X);
		scanf("%d", &Y);

		X += 250;
		Y += 250;

		memset(b, false, sizeof(b));
		memset(path, 0, sizeof(path));
		memset(rpath, 0, sizeof(rpath));
		end = false;
		dfs(250, 250, 1);

		printf("Case #%d: %s\n", test, rpath);
	}

	return 0;
}
