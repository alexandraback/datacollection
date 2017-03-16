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

int field[110][110];
int currentField[110][110];

bool check(int n, int m)
{
	rept(i,n)
		rept(j,m)
		if (currentField[i][j]!=field[i][j])
			return false;
	return true;
}

void justDoIt(int n, int m, int startX, int startY, int deltaX, int deltaY)
{
	int mx=-1;
	int startXC=startX;
	int startYC=startY;
	while (startX<n && startY<m)
	{
		mx=max(mx,field[startX][startY]);
		startX+=deltaX;
		startY+=deltaY;
	}
	startX=startXC;
	startY=startYC;
	while (startX<n && startY<m)
	{
		currentField[startX][startY]=min(currentField[startX][startY],mx);
		startX+=deltaX;
		startY+=deltaY;
	}
}

void doRows(int n, int m)
{
	rept(i,n)
		justDoIt(n,m,i,0,0,1);
}

void doColumns(int n, int m)
{
	rept(i,m)
		justDoIt(n,m,0,i,1,0);
}

void test(int t)
{
	printf("Case #%d: ",t);
	int n,m;
	scanf("%d%d",&n,&m);
	rept(i,n)
		rept(j,m)
			currentField[i][j]=100;
	rept(i,n)
		rept(j,m)
			scanf("%d",&field[i][j]);
	doRows(n,m);
	doColumns(n,m);
	if (check(n,m))
		puts("YES");
	else
		puts("NO");
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
	scanf("%d",&n);
	rept(i,n)
		test(i+1);
	return 0;
}