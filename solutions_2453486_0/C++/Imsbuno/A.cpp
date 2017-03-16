#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)
#define random(x) ((((rand()%32767)*(rand()%32767)*(rand()%32767)%(x))+(x))%(x))

using namespace std;

typedef	long long	int64;


int	c[999];
char	a[5][5];


int	main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		int	empty = 0;
		for (int i = 1; i <= 4; ++ i)
		{
			scanf("%s", a[i] + 1);
			for (int j = 1; j <= 4; ++ j) empty |= (a[i][j] == '.');
		}
		
		int	winO = 0, winX = 0;
		for (int i = 1; i <= 4; ++ i)
		{
			c['O'] = c['T'] = c['X'] = 0;
			for (int j = 1; j <= 4; ++ j) ++ c[a[i][j]];
			if (c['O'] + c['T'] == 4) winO = 1;
			if (c['X'] + c['T'] == 4) winX = 1;
		}
		
		for (int j = 1; j <= 4; ++ j)
		{
			c['O'] = c['T'] = c['X'] = 0;
			for (int i = 1; i <= 4; ++ i) ++ c[a[i][j]];
			if (c['O'] + c['T'] == 4) winO = 1;
			if (c['X'] + c['T'] == 4) winX = 1;
		}
		
		{
			c['O'] = c['T'] = c['X'] = 0;
			for (int i = 1; i <= 4; ++ i) ++ c[a[i][i]];
			if (c['O'] + c['T'] == 4) winO = 1;
			if (c['X'] + c['T'] == 4) winX = 1;
		}
		
		{
			c['O'] = c['T'] = c['X'] = 0;
			for (int i = 1; i <= 4; ++ i) ++ c[a[i][5 - i]];
			if (c['O'] + c['T'] == 4) winO = 1;
			if (c['X'] + c['T'] == 4) winX = 1;
		}
		
		printf("Case #%d: ", test);
		if (winO)
			puts("O won");
		else
		if (winX)
			puts("X won");
		else
		if (empty)
			puts("Game has not completed");
		else
			puts("Draw");
	}
	
	return 0;
}
