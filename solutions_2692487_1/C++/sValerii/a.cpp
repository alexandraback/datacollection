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

const int N = 200;
int a[N];

int solve(int s, int n) {
	int ans = n;
	int c = 0;
	rep(i,n) {		
		while (a[i] >= s && c<ans) {
			s+=s-1;
			c++;
		}
		s+=a[i];
		int q = c+(n-i-1);
		if (q < ans) ans = q;
	}
	return ans;
}

int main()
{
	//int qwe = 1000000000;
	//printf("%d\n",qwe);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int tnum;
	scanf("%d",&tnum);
	rep(tc,tnum) {
		int s,n;
		scanf("%d %d",&s,&n);
		rep(i,n) scanf("%d",&a[i]);
		sort(a,a+n);
		printf("Case #%d: %d\n",tc+1,solve(s,n));
	}
	return 0;
}

