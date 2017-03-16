/*
 	C++ Template
	Pradeep George Mathias
 */


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
using namespace std;

#define s(T) scanf("%d", &T)
#define sl(T) scanf("%lld", &T)
#define fill(a, val) memset(a, val, sizeof(a))
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define DREP(x) sort(all(x)); x.erase(unique(all(x)), x.end())
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())

int totalCases, testNum;
string board[4];

void preprocess()
{
	
}

bool input()
{
	for(int i = 0; i < 4; i++)
		cin >> board[i];
	return true;
}

void solve()
{
	bool dots = false;
	for(int i = 0; i < 4; i++)
	{
		bool xwin = true, owin = true;
		for(int j = 0; j < 4; j++)
		{	
			xwin = xwin && !(board[i][j] == 'O' || board[i][j] == '.');
			owin = owin && !(board[i][j] == 'X' || board[i][j] == '.');
			dots = dots || (board[i][j] == '.');
		}
		if(xwin)
		{
			printf("Case #%d: X won\n", testNum);
			return;
		}
		if(owin)
		{
			printf("Case #%d: O won\n", testNum);
			return;
		}
	}
	for(int i = 0; i < 4; i++)
	{
		bool xwin = true, owin = true;
		for(int j = 0; j < 4; j++)
		{	
			xwin = xwin && !(board[j][i] == 'O' || board[j][i] == '.');
			owin = owin && !(board[j][i] == 'X' || board[j][i] == '.');
		}
		if(xwin)
		{
			printf("Case #%d: X won\n", testNum);
			return;
		}
		if(owin)
		{
			printf("Case #%d: O won\n", testNum);
			return;
		}
	}
	
	bool xwin = true, owin = true;
	for(int j = 0; j < 4; j++)
	{	
		xwin = xwin && !(board[j][j] == 'O' || board[j][j] == '.');
		owin = owin && !(board[j][j] == 'X' || board[j][j] == '.');
	}
	if(xwin)
	{
		printf("Case #%d: X won\n", testNum);
		return;
	}
	if(owin)
	{
		printf("Case #%d: O won\n", testNum);
		return;
	}
	
	xwin = owin = true;
	for(int j = 0; j < 4; j++)
	{	
		xwin = xwin && !(board[j][3-j] == 'O' || board[j][3-j] == '.');
		owin = owin && !(board[j][3-j] == 'X' || board[j][3-j] == '.');
	}
	if(xwin)
	{
		printf("Case #%d: X won\n", testNum);
		return;
	}
	if(owin)
	{
		printf("Case #%d: O won\n", testNum);
		return;
	}
	
	if(dots)
		printf("Case #%d: Game has not completed\n", testNum);
	else 
		printf("Case #%d: Draw\n", testNum);

}

int main()
{
	preprocess();
	s(totalCases);
	for(testNum = 1; testNum <= totalCases; testNum++)
	{
		if( !input())
			break;
		solve();
	}
}
