// gc_1.cpp : Defines the entry point for the console application.
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

const int N=100; 
VI r[N];
bool f[N][N];
bool pr[N];
int n;

bool done(int v){
	rep(num,sz(r[v])){
		int u=r[v][num];
		if (f[v][u]) return true;
		f[v][u]=1;
		if (!pr[u]) {
			if ( done(u) ) return true;
		}

		rep(i,n)
		{
			if (f[v][i] && f[u][i]) return true;
			f[v][i]|=f[u][i];
		}
		
	}
	pr[v]=true;
	return false;
}

bool solve(){
	rep(i,n)
		if (!pr[i]) {
			if (done(i)) return true;
		}
	return false;

}

int main()
{
	freopen("g1.in","r",stdin);
	freopen("g1.out","w",stdout);
	int testCase;
	scanf("%d",&testCase);
	rep(testNum,testCase){
		scanf("%d",&n);
		rep(i,n){
			r[i].clear();
			rep(j,n) f[i][j]=0;
			pr[i]=0;
		}
		rep(i,n){
			int m;
			scanf("%d",&m);
			int u;
			rep(j,m){
				scanf("%d",&u);
				r[i].push_back(u-1);
			}
		}

		printf("Case #%d: ",testNum+1);
		if ( solve() ) printf("Yes\n");
		else printf("No\n");

		

	}
	return 0;
}

