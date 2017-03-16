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

const int N = 120;

int a[N][N];
int n,m;

bool find(int &imin, int& jmin) {
	int minV = N;
	rep(i,n) 
		rep(j,m) 
		if (a[i][j]!=-1 && a[i][j]<minV) {
			minV = a[i][j];
			imin = i;
			jmin = j;
		}
	return minV != N;
}

bool row(int i,int minV) {
	rep(j,m) 
		if (a[i][j]!=-1 && a[i][j]!=minV) return false;

	rep(j,m) 
		a[i][j] = -1;

	return true;
}

bool colume(int j, int minV) {
	rep(i,n)
		if (a[i][j]!=-1 && a[i][j]!=minV) return false;

	rep(i,n) 
		a[i][j] = -1;

	return true;
}

int test(){
	int imin, jmin;
	while ( find(imin,jmin) ) {
		int v = a[imin][jmin];
		if (!row(imin,v) && !colume(jmin,v)) return false;
	}
	return true;
}

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int tnum;
	scanf("%d",&tnum);
	rep(tc,tnum) {
		
		scanf("%d %d",&n,&m);
		rep(i,n) rep(j,m) scanf("%d",&a[i][j]);
		if ( test() ) printf("Case #%d: YES\n",tc+1);
		else printf("Case #%d: NO\n",tc+1);
	}

	return 0;
}

