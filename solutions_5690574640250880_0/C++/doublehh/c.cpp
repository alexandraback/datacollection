/*
 *   Copyright (C) 2014 All rights reserved.
 *   
 *   filename: c.cpp
 *   author: doublehh
 *   e-mail: sserdoublehh@foxmail.com
 *   create time: 2014-04-12
 *   last modified: 2014-04-12 07:56:19
 */
#include <cstdio>
#include <assert.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,n) for (int i = 0; i < (n); i++)
#define FOR1(i,n) for (int i = 1; i <= (n); i++)

const int maxn = 55;
char s[maxn][maxn];
int r, c, m;

bool judge()
{
	if (r == 1)
	{
		if (m >= c)
			return 0;
		s[0][0] = 'c';
		FOR (i, c-1-m) s[0][i+1] = '.';
		FOR (i, m) s[0][c-1-i] = '*';
		s[0][c] = 0;
		return 1;
	}
	if (c == 1)
	{
		if (m >= r)
			return 0;
		s[0][0] = 'c';
		FOR (i, r-1-m) s[i+1][0] = '.';
		FOR (i, m) s[r-1-i][0] = '*';
		FOR (i, r)
			s[i][c] = 0;
		return 1;
	}
	if (m >= r*c)
		return 0;

	if (r*c - m == 1)
	{
		FOR (i, r)
		{
			FOR (j, c)
				s[i][j] = '*';
			s[i][c] = 0;
		}
		s[r-1][c-1] = 'c';
		return 1;
	}

	int tot = m, li = 0, lj = -1;
	memset(s, 0, sizeof(s));
	FOR (i, r-2)
	{
		FOR (j, c-2)
		{
			if (tot)
			{
				s[i][j] = '*';
				li = i, lj = j;
				tot--;
			}
			else
				s[i][j] = '.';
		}
		if (tot >= 2 && (i != r-3 || tot != 3))
		{
			s[i][c-2] = s[i][c-1] = '*';
			tot -= 2;
		}
		else
			s[i][c-2] = s[i][c-1] = '.';
		s[i][c] = 0;
	}
	if (tot & 1)
	{
		if (lj == -1 || s[li][lj+1] == '*')
			return 0;
		s[li][lj] = '.';
		tot++;
	}
	FOR (i, c-2)
	{
		if (!tot) break;
		if (r != 2 && s[r-3][i] == '.')
			return 0;
		s[r-2][i] = s[r-1][i] = '*';
		tot -= 2;
	}
	if (tot)
		return 0;
	FOR (i, r) FOR (j, c)
		if (!s[i][j])
			s[i][j] = '.';
	s[r-1][c-1] = 'c';
	return 1;
}

int main()
{
	//freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	FOR1 (Case, T)
	{
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", Case);
		//printf("%d %d %d\n", r, c, m);
		if (!judge())
			puts("Impossible");
		else
		{
			FOR (i, r)
				puts(s[i]);
		}
	}
}
