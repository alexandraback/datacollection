// b.cpp : Defines the entry point for the console application.
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

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int tnum;
	scanf("%d",&tnum);
	rep(tc,tnum) {
		int x,y;
		scanf("%d %d",&x,&y);
		printf("Case #%d: ",tc+1);	
		string s = "";
		if (x > 0) s = "WE";
		else s = "EW";
		rep(i,abs(x)) printf("%s",s.c_str());

		if (y>0) s = "SN";
		else s = "NS";

		rep(i,abs(y))
			printf("%s",s.c_str());
		printf("\n");
	}
	return 0;
}

