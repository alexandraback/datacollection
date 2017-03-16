#include <stdio.h>
#include <algorithm>

using namespace std;

int T;
int n, x, y;

int used[1 << 8][1 << 4];

const int add = 1 << 7;

int right(int x, int y)
{
	int res = 0;
	x += add;
	while (y > 0 && !used[x + 1][y - 1])
	{
		x++;
		y--;
		++res;
	}
	used[x][y] = 1;
	return res;
}

int left(int x, int y)
{
	int res = 0;
	x += add;
	while (y > 0 && !used[x - 1][y - 1])
	{
		x--;
		y--;
		++res;
	}
	used[x][y] = 1;
	return res;
}

double go(int n)
{
	if (n == 0)
	{
		if (abs(x) > 8 || abs(y) > 6)
			return 0;
		return used[add + x][y];
	}
	int yy = 8;
	while (yy > 0 && !used[add][yy - 2])
		yy -= 2;
	if (yy == 0)
	{
		used[add][yy] = 1;
		double res = go(n - 1);
		used[add][yy] = 0;
		return res;
	}
	if (used[add - 1][yy - 1] && used[add + 1][yy - 1])
	{
		used[add][yy] = 1;
		double res = go(n - 1);
		used[add][yy] = 0;
		return res;
	}
	if (used[add - 1][yy - 1])
	{
		int t = right(0, yy);
		used[add + t][yy - t] = 1;
		double res = go(n - 1);
		used[add + t][yy - t] = 0;
		return res;
	}
	if (used[add + 1][yy - 1])
	{
		int t = left(0, yy);
		used[add - t][yy - t] = 1;
		double res = go(n - 1);
		used[add - t][yy - t] = 0;
		return res;
	}
	int L = left(0, yy);
	used[add - L][yy - L] = 1;
	double res = 0.5 * go(n - 1);
	used[add - L][yy - L] = 0;
	int R = right(0, yy);
	used[add + R][yy - R] = 1;
	res += 0.5 * go(n - 1);
	used[add + R][yy - R] = 0;
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int I = 1; I <= T; ++I)
	{
		scanf("%d%d%d", &n, &x, &y);
		memset(used, 0, sizeof(used));
		printf("Case #%d: ", I);
		printf("%.7lf\n", go(n));
	}
	return 0;
}