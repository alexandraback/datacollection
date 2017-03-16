#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define INF (1<<30)

using namespace std;

const int N = 111;

int a[N][N];
int r, c, m;

int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, 1, 1, 1, 0, -1, -1, -1};

bool valid(int x, int y)
{
	return (x >= 0 && y >= 0 && x < r && y < c);
}

bool canFree(int x, int y)
{
	return valid(x, y);
}

int toFree(int x, int y)
{
	int cnt = 0;
	for(int i = 0; i<9; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && a[nx][ny] == 0)
			cnt++;
	}

	return cnt;
}

int freeCell(int x, int y)
{
	int cnt = 0;
	for(int i = 0; i<9; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (valid(nx, ny) && a[nx][ny] == 0)
		{
			cnt++;
			a[nx][ny] = 1;
		}
	}

	return cnt;	
}

bool buildField()
{
	memset(a, 0, sizeof(a));

	if (m == 1)
	{
		return true;
	}

	int curFree = 0;
	int curR = 1;
	int curC = 1;

	curFree += freeCell(0, 0);

	while (1)
	{
		int t = curFree;
		if (canFree(curR, 0) && toFree(curR, 0) + curFree <= m)
			curFree += freeCell(curR++, 0);
		if (canFree(0, curC) && toFree(0, curC) + curFree <= m)
			curFree += freeCell(0, curC++);
		if (curFree == t)
			break;
	}

	curR--;
	curC--;

	for(int i = 1; i<=curR; i++)
	{
		for(int j = 1; j<=curC; j++)
		{
			if (canFree(i, j) && toFree(i, j) + curFree <= m)
				curFree += freeCell(i, j);
		}
	}

	return curFree == m;
}

int main()
{
	#define DEBUG

	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int t;

	scanf("%d", &t);

	for(int test = 1; test <= t; test++)
	{
		printf("Case #%d:\n", test);
		
		scanf("%d%d%d", &r, &c, &m);

		m = r*c - m;

		if (!buildField())
		{
			printf("Impossible\n");
		}
		else
		{
			for(int i = 0; i<r; i++)
			{
				for(int j = 0; j<c; j++)
				{
					if (i == 0 && j == 0)
					{
						printf("c");
					}
					else if (a[i][j] == 1)
					{
						printf(".");
					}
					else
					{
						printf("*");
					}
				}
				printf("\n");
			}
		}
	}

	return 0;
}