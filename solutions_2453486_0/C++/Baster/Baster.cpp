#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<iomanip>
#include<ctime>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

char c[4][4];

void solve(int test)
{
	printf("Case #%d: ", test);
	int cnt = 0;
	forn (i, 4)
	{
		int x = 0, o = 0;
		forn (j, 4)
		{
			if(c[i][j] == 'X' || c[i][j] == 'T')
				x++;
			if(c[i][j] == 'O' || c[i][j] == 'T')
				o++;
			if(c[i][j] == '.')
				cnt++;
		}
		if(x == 4)
		{
			printf("X won\n");
			return;
		}
		if(o == 4)
		{
			printf("O won\n");
			return;
		}
	}
	forn (i, 4)
	{
		int x = 0, o = 0;
		forn (j, 4)
		{
			if(c[j][i] == 'X' || c[j][i] == 'T')
				x++;
			if(c[j][i] == 'O' || c[j][i] == 'T')
				o++;
		}
		if(x == 4)
		{
			printf("X won\n");
			return;
		}
		if(o == 4)
		{
			printf("O won\n");
			return;
		}
	}
	int x = 0, o = 0;
	for (int i = 0; i < 4; ++i)
	{
			if(c[i][i] == 'X' || c[i][i] == 'T')
				x++;
			if(c[i][i] == 'O' || c[i][i] == 'T')
				o++;
	}
	if(x == 4)
		{
			printf("X won\n");
			return;
		}
		if(o == 4)
		{
			printf("O won\n");
			return;
		}
	x = o = 0;
	for (int i = 0; i < 4; ++i)
	{
			if(c[3 - i][i] == 'X' || c[3 - i][i] == 'T')
				x++;
			if(c[3 - i][i] == 'O' || c[3 - i][i] == 'T')
				o++;
	}
	if(x == 4)
		{
			printf("X won\n");
			return;
		}
		if(o == 4)
		{
			printf("O won\n");
			return;
		}
	
	if(cnt == 0)
		printf("Draw\n");
	else
		printf("Game has not completed\n");
}

bool read()
{
	int n;
	scanf("%d\n", &n);
	forn (test, n)
	{
		forn (i, 4)
		{
			forn (j, 4)
				scanf("%c", &c[i][j]);
			scanf("\n");
		}
		solve(test + 1);
		scanf("\n");
	}
	return true;
}

int main()
{
	freopen ("A-small-attempt0.in", "r", stdin);
	freopen ("output.txt", "w", stdout);
	read();
	return 0;
}