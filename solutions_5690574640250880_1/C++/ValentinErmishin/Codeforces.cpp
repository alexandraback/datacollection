#include "stdafx.h" 
#include "wchar.h"
#include "conio.h"
#include "iostream"
#include "string.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "limits.h"
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <queue>
#define PI 3.14159265358979323846
#define ull unsigned long long int
#define ll long long int
#define EPS 1e-11
#define pb push_back
#define EOS(c) (c != EOF && c != '\0' && c != '\n' && c != ' ')
#define oo 1000000005
#define ALL(v) v.begin(), v.end()
#define mp make_pair
#define win return 0 

//#define FILE "brackets"

using namespace std;

template<class telem>telem MAX(telem a, telem b)
{
	return (a > b) ? a : b;
}

template<class telem>telem MIN(telem a, telem b)
{
	return (a < b) ? a : b;
}

template<class telem>telem GCD(telem a, telem b)
{
	return b ? GCD(b, a % b) : a;
}

template<class telem>telem LCM(telem a, telem b)
{
	return a / GCD(a, b) * b;
}

template<class telem>telem UNSIGNED(telem a)
{
	return (a > 0) ? a : a * (-1);
}

template<class telem>void bez_swop(telem &a, telem &b)
{
	telem c = a;
	a = b;
	b = c;
}

int Case;
int T;

char mine[60][60];
char used[60][60];
int r, c, m;
int dx[] = {-1, -1,  0,  1, 1, 1, 0, -1};
int dy[] = { 0, -1, -1, -1, 0, 1, 1,  1};
queue<pair<int, int> > q;

void ans_c()
{
	r -= m;

	r--;
	putchar('c');
	putchar('\n');

	while(r --> 0)
	{
		putchar('.');
		putchar('\n');
	}

	while(m --> 0)
	{
		putchar('*');
		putchar('\n');
	}
}

void ans_r()
{
	c -= m;

	c--;
	putchar('c');

	while(c --> 0)
	{
		putchar('.');
	}

	while(m --> 0)
	{
		putchar('*');
	}

	putchar('\n');
}

void take_mine()
{
	int a = r;
	int b = c;

	mine[1][1] = 'c';

	while(m >= min(a, b))
	{
		if(a < b)
		{
			for(int i = 1; i <= a; i++)
			{
				mine[i][b] = '*';
				m--;
			}
			b--;
		}
		else
		{
			for(int i = 1; i <= b; i++)
			{
				mine[a][i] = '*';
				m--;
			}
			a--;
		}
	}

	if(a < b)
	{
		for(int i = a; i > 2 && m; i--, m--)
		{
			mine[i][b] = '*';
		}
		b--;
	}
	else
	{
		for(int i = b; i > 2 && m; i--, m--)
		{
			mine[a][i] = '*';
		}
		a--;
	}
	
	if(m)
		mine[a][b] = '*';
}

void counting()
{
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			if(mine[i][j] == '*')
				continue;

			for(int k = 0; k < 8; k++)
			{
				if(mine[i + dy[k]][j + dx[k]] == '*')
					used[i][j] = 2;
			}
			if(!used[i][j])
				used[i][j] = 1;
		}
	}
}

bool get_ans()
{
	if(used[1][1] == 1)
	{
		q.push(mp(1, 1));
	}

	used[1][1] = 0;

	while(!q.empty())
	{
		pair<int, int> tmp = q.front();
		q.pop();

		int x = tmp.second;
		int y = tmp.first;

		for(int i = 0; i < 8; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];

			if(used[yy][xx] == 1)
			{
				q.push(mp(yy, xx));
			}

			used[yy][xx] = 0;
		}
	}

	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			if(used[i][j])
				return false;
		}
	}

	return true;
}

void print()
{
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			putchar(mine[i][j]);
		}
		putchar('\n');
	}
}

int main()
{  
	//freopen(FILE".in", "r", stdin);
	//freopen(FILE".out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//time_t start = clock();

	scanf("%d", &T);
	Case = T;

	while(T --> 0)
	{
		printf("Case #%d:\n", Case - T);

		scanf("%d %d %d", &r, &c, &m);

		memset(mine, '.', sizeof(mine));

		if(r == 1)
		{
			ans_r();
			continue;
		}

		if(c == 1)
		{
			ans_c();
			continue;
		}

		take_mine();
		memset(used, 0, sizeof(used));
		counting();

		if(get_ans())
		{
			print();
		}
		else
		{
			printf("Impossible\n");
		}
	}

	//printf("\n%0.3lf", (clock() - start) * 1.0 / CLOCKS_PER_SEC);

	win;
}