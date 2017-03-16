#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>
using namespace std;
///int table1[10000][1000] = {0};
char table[20005][20005] = {0};
int dx = 10004;
int all = 0;
int onlyOne = 0;
int cx,cy;
void rec (int n,int x = 0,int y = 0)
{
	if (n == 0)
	{
		if (table[dx + cx][dx + cy] != 0)
			onlyOne++;
		all++;
		return;
	}
	while(table[dx + x][dx + y] != 0 && x == 0)
		y += 2;

	if (table[dx + x - 1][dx + y - 1] == 0 && y > 0)
	{
		rec (n,x - 1,y - 1);
	}
	if (table[dx + x + 1][dx + y - 1] == 0 && y > 0)
	{
		rec (n,x + 1,y - 1);
	}

	if ((table[dx + x - 1][dx + y - 1] == 1 && table[dx + x + 1][dx + y - 1] == 1 || y == 0) && table[dx + x][dx + y] == 0)
	{
		table[dx + x][dx + y] = 1;
		//printf ("(%d %d) ",x,y);
		rec (n - 1);
		table[dx + x][dx + y] = 0;
		return;
	}
	

}
int main( )
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt3.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n,x,y;
		cin >> n >> x >> y;
		cx = x;
		cy = y;
		rec (n);
		if (onlyOne == 0 || all == 0)
			printf ("Case #%d: %.9lf\n",i + 1,0);
		else
			printf ("Case #%d: %.9lf\n",i + 1,double(onlyOne) / all);
		onlyOne = 0;
		all = 0;
	}

	return 0;
}
