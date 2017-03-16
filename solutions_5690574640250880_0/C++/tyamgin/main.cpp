#pragma comment(linker, "/STACK:500000000") 
#include <functional>
#include <algorithm> 
#include <iostream> 
#include <string.h> 
#include <stdlib.h> 
#include <sstream> 
#include <ctype.h> 
#include <stdio.h> 
#include <bitset>
#include <vector> 
#include <string> 
#include <math.h> 
#include <time.h> 
#include <queue> 
#include <stack> 
#include <list>
#include <map> 
#include <set> 
#define Int long long 
#define INF 0x3F3F3F3F 
#define eps 1e-9
using namespace std;

const int _i[] = { 0, 0, 1, -1, 1, 1, -1, -1 },
		  _j[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

int a[7][7];
int n, m;
bool used[7][7];
int cI, cJ;

int Count(int i, int j)
{
	return a[i + 1][j + 1] + a[i - 1][j + 1] + a[i + 1][j - 1] + a[i - 1][j - 1] +
		a[i][j + 1] + a[i][j - 1] + a[i + 1][j] + a[i - 1][j];
}

void dfs(int i, int j)
{
	used[i][j] = 1;
	if (Count(i, j) == 0)
	{
		for (int k = 0; k < 8; k++)
		{
			int ni = _i[k] + i,
				nj = _j[k] + j;
			if (ni > 0 && nj > 0 && ni <= n && nj <= m && !used[ni][nj])
				dfs(ni, nj);
		}
	}
}

void brute(int pos, int s)
{
	if (pos == -1)
	{
		int i, j;
		memset(used, 0, sizeof(used));
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j] != 1)
				{
					if (Count(i, j) == 0)
					{
						dfs(i, j);
						cI = i, cJ = j;
						break;
					}
				}
			}
			if (j <= m)
				break;
		}
		if (i > n)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= m; j++)
				{
					if (a[i][j] == 0)
					{
						dfs(i, j);
						cI = i, cJ = j;
						break;
					}
				}
				if (j <= m)
					break;
			}
		}
		int cnt = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				if (a[i][j] == 0 && !used[i][j])
					return;
		throw 1;
	}
	if (pos + 1 > s)
	{
		a[pos / m + 1][pos % m + 1] = 0;
		brute(pos - 1, s);
	}
	if (s > 0)
	{
		a[pos / m + 1][pos % m + 1] = 1;
		brute(pos - 1, s - 1);
	}
}

bool solve(int s)
{
	try
	{
		brute(n*m - 1, s);
		return false;
	}
	catch (int)
	{
		return true;
	}
}

int main()
{
	//n = 5, m = 1;
	//if (solve(4))
	//{
	//	for (int i = 1; i <= n; i++)
	//	{
	//		for (int j = 1; j <= m; j++)
	//			putchar(a[i][j] == 1 ? '*' : i == cI && j == cJ ? 'c' : '.');
	//		puts("");
	//	}
	//}
	//else
	//{
	//	puts("NO");
	//}
	//return 0;


	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; test++)
	{
		int s;
		scanf("%d %d %d", &n, &m, &s);
		if (n > 5 || m > 5)
			continue;
		memset(a, 0, sizeof(a));
		printf("Case #%d:\n", test);
		if (solve(s))
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
					putchar(a[i][j] == 1 ? '*' : i == cI && j == cJ ? 'c' : '.');
				puts("");
			}
		}
		else
		{
			puts("Impossible");
		}
	}

	//for (n = 1; n <= 5; n++)
	//{
	//	for (m = 1; m <= 5; m++)
	//	{
	//		for (int s = 0; s < n*m; s++)
	//		{
	//			memset(a, 0, sizeof(a));
	//			if (solve(s))
	//			{
	//				printf("%d %d %d\n", n, m, s);
	//				for (int i = 1; i <= n; i++)
	//				{
	//					for (int j = 1; j <= m; j++)
	//						putchar(a[i][j] == 1 ? '*' : i == cI && j == cJ ? 'c' : '.');
	//					puts("");
	//				}
	//			}
	//		}
	//	}
	//}
}