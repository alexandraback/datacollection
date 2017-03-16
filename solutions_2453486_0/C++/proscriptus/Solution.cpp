#define _CRT_SECURE_NO_DEPRECATE

#pragma comment(linker,"/STACK:267386880")

#include <iostream>
#include <functional>
#include <ctime>
#include <cstdio>
#include <memory>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>
#include <iterator>
#include <bitset>
#include <sstream>
#include <numeric>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(i,a,b) for (int i(a); i<=(b); ++i)
#define rep(i,a) FOR(i,1,a)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 1000000000
#define PI 3.141592653589
#define eps 0.00000000000000001
#define MOD 1000000007
#define PRIME 1000003

using namespace std;

char field[4][4];

bool check(int startX, int startY, int deltaX, int deltaY, char sym)
{
	rept(i,4)
	{
		char cur=field[startX][startY];
		if (cur==sym || cur=='T');
		else return false;
		startX+=deltaX;
		startY+=deltaY;
	}
	return true;
}

bool checkRows(char sym)
{
	rept(i,4)
		if (check(i,0,0,1,sym))
			return true;
	return false;
}

bool checkColumns(char sym)
{
	rept(i,4)
		if (check(0,i,1,0,sym))
			return true;
	return false;
}

bool checkDiagonal(char sym)
{
	return (check(0,0,1,1,sym) || check(0,3,1,-1,sym));
}

bool check(char sym)
{
	return checkRows(sym) || checkColumns(sym) || checkDiagonal(sym);
}

void test(int t)
{
	printf("Case #%d: ",t);
	rept(i,4)
		gets(field[i]);
	if (check('X'))
		puts("X won");
	else if (check('O'))
		puts("O won");
	else {
		bool draw=true;
		rept(i,4) rept(j,4)
			if (field[i][j]=='.')
				draw=false;
		if (draw)
			puts("Draw");
		else
			puts("Game has not completed");
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	{
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	}
#endif
	int n;
	scanf("%d\n",&n);
	rept(i,n)
	{
		test(i+1);
		gets(field[0]);
	}
	return 0;
}