// a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define forr(i,a,b) for (int i=a; i<=b; i++)
#define ford(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define sqr(q) q*q
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

int a[5][5];
char s[10];


bool check(int ist,int jst, int im,int jm, int mask) {
	rep(i,4) {
		if ((a[ist][jst]&mask) == 0) return false;
		ist+=im;
		jst+=jm;
	}
	return true;
}


int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tnum;
	scanf("%d\n",&tnum);
	rep(tc,tnum) {
		rep(i,4) rep(j,4) a[i][j] = 0;
		bool isDot = false;

		rep(i,4) {
			gets(s);
			rep(j,4) {
				if ('X' == s[j]) a[i][j] = 1;
				if ('O' == s[j]) a[i][j] = 2;
				if ('T' == s[j]) a[i][j] = 3;
				if ('.' == s[j]) isDot = true;
			}
		}
		gets(s);

		int winer = 0;
		rep(i,4) {
			if ( check(i,0,0,1,1) ) { winer = 1; break; }
			if ( check(i,0,0,1,2) ) { winer = 2; break; }
			if ( check(0,i,1,0,1) ) { winer = 1; break; }
			if ( check(0,i,1,0,2) ) { winer = 2; break; }
		}

		if (0==winer && check(0,0,1,1,1)) winer = 1;
		if (0==winer && check(0,0,1,1,2)) winer = 2;
		if (0==winer && check(0,3,1,-1,1)) winer = 1;
		if (0==winer && check(0,3,1,-1,2)) winer = 2;

		printf("Case #%d: ",tc+1);
		if (winer) {
			if (1 == winer) printf("X won\n");
			if (2 == winer) printf("O won\n");
		} else {
			if (isDot) printf("Game has not completed\n");
			else printf("Draw\n");
		}

	}
	return 0;
}

