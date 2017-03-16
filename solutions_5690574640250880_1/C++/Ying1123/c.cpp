#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int T;
int R, C, M;

void work()
{
	scanf("%d%d%d", &R, &C, &M);
	if (R * C - M == 1)
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
				if (i == 0 && j == 0) printf("c"); else printf("*");
			printf("\n");
		}
		return;
	}

	if (R == 1 || C == 1)
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
				if (i * C + j < M) printf("*"); else
				if (i == R - 1 && j == C - 1) printf("c"); else
					printf(".");
			printf("\n");
		}
		return;
	}

	if (R * C - M < 4)
	{
		printf("Impossible\n");
		return;
	}

	int rest = R * C - M - 4;
	int x = 2, y = 2, x_new = 0, y_new = 0;
	while (1)
	{
		if (x < R && rest >= y)
		{
			rest -= y;
			++x;
		}
		if (y < C && rest >= x)
		{
			rest -= x;
			++y;
		}
		if ((x == R || rest < y) && (y == C || rest < x))
		{
			if (x < R)
			{
				if (rest == 1)
				{
					x_new = 2;
					--y;
					y_new = x - 1;
				} else
					x_new = rest;
				break;
			} else
			{
				if (rest == 1)
				{
					y_new = 2;
					--x;
					x_new = y - 1;
				} else
					y_new = rest;
				break;
			}
		}
	}
	if (x_new == 1 || y_new == 1 || x == 1 || y == 1) printf("Impossible\n"); else
	{
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				if (i == 0 && j == 0) printf("c"); else
				if (i < x && j < y) printf("."); else
				if ((i == x && j < x_new) || (j == y && i < y_new)) printf("."); else
					printf("*");
			}
			printf("\n");
		}
	}
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		printf("Case #%d:\n", i + 1);
		work();
	}
	return 0;
}
