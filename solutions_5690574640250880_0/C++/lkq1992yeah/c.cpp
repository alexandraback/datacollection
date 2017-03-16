#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int r, c, m;
int dp[60][60][3000];	//i-th row, j blanks in r_i, used k blanks
int track[60][60][3000];

int combine(int a, int b, int c)
{
	return a * 60 * 3000 + b * 3000 + c;
}

void decomp(int x, int &a, int &b, int &c)
{
	a = x / (60 * 3000);
	x %= (60 * 3000);
	b = x / 3000;
	x %= 3000;
	c = x;
}

void output(int r, int c, int ri, int rj, int rk)
{
	int last, ti, tj, tk, j;
	last = track[ri][rj][rk];
	if (last != -1)
	{
		decomp(last, ti, tj, tk);
		output(r, c, ti, tj, tk);
		for (j = 0; j < rj; j++)
			printf(".");
		for (j = rj; j < c; j++)
			printf("*");
		printf("\n");
	}
	else
	{
		printf("c");
		for (j = 1; j < rj; j++)
			printf(".");
		for (j = rj; j < c; j++)
			printf("*");
		printf("\n");
		for (j = 0; j < rj; j++)
			printf(".");
		for (j = rj; j < c; j++)
			printf("*");
		printf("\n");
	}
}

void work(int r, int c, int m)
{
	int rem = r * c - m;
	// printf("r: %d  c: %d  rem: %d\n", r, c, rem);
	int i, j, k, l;
	int ri, rj, rk, flag = 0;
	memset(track, -1, sizeof track);
	memset(dp, 0, sizeof dp);
	for (i = 2; i <= c; i++)
		if (2 * i <= rem)
		{
			dp[2][i][2 * i] = 1;
			track[2][i][2 * i] = -1;
			// printf("\tAvailable: %d %d %d\n", 2, i, 2 * i);
		}
	for (i = 2; i < r && !flag; i++)
		for (j = 2; j <= c && !flag; j++)
			for (k = 0; k <= rem && !flag; k++)
			{
				if (dp[i][j][k] == 0) continue;
				// printf("Here at: %d %d %d\n", i, j, k);
				if (k == rem)
				{
					flag = 1; ri = i; rj = j; rk = k;
					break;
				}
				for (l = 2; l <= j; l++)
					if (k + l <= rem && dp[i + 1][l][k + l] == 0)
					{
						dp[i + 1][l][k + l] = 1;
						// printf("\tAvailable: %d %d %d\n", i + 1, l, k + l);
						track[i + 1][l][k + l] = combine(i, j, k);
					}
			}
	if (flag == 0)
	{
		for (j = 2; j <= c; j++)
			if (dp[r][j][rem] == 1)
			{
				flag = 1;
				ri = r; rj = j; rk = rem;
				break;
			}
	}
	if (flag == 1)
	{
		output(r, c, ri, rj, rk);
		for (i = ri + 1; i <= r; i++)
		{
			for (j = 0; j < c; j++)
				printf("*");
			printf("\n");
		}
	}
	else
		printf("Impossible\n");
}

void fill(int r, int c, char ch)
{
	int i, j;
	printf("c");
	for (j = 1; j < c; j++) printf("%c", ch);
	printf("\n");
	for (i = 1; i < r; i++)
	{
		for (j = 0; j < c; j++)
			printf("%c", ch);
		printf("\n");
	}
}

int main()
{
	int t, cas;
	int i, j;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		printf("Case #%d:\n", cas);
		scanf("%d%d%d", &r, &c, &m);
		if (m == 0)
		{
			fill(r, c, '.');
			continue;
		}
		else if (m == r * c - 1)
		{
			fill(r, c, '*');
			continue;
		}
		if (r == 1)
		{
			for (i = 0; i < m; i++) printf("*");
			for (i = m; i < r * c - 1; i++) printf(".");
			printf("c\n");
		}
		else if (c == 1)
		{
			for (i = 0; i < m; i++) printf("*\n");
			for (i = m; i < r * c - 1; i++) printf(".\n");
			printf("c\n");
		}
		else
			work(r, c, m);
	}
	return 0;
}

