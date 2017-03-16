// gc_3s.cpp : Defines the entry point for the console application.
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

pair<int,i64> a[2][100],b[2][100];
int n,m;
i64 ans = 0;


void process(VI s){
	i64 res = 0;
	rep(i,n)
		rep(j,m) b[i][j]=a[i][j];
	rep(i,n){
		int code = s[i];
		rep(j,m)
			if (code&(1<<j)){
				if (b[0][i].first == b[1][j].first) {
					i64 t = min(b[0][i].second,b[1][j].second);
					res+=t;
					b[0][i].second-=t;
					b[1][j].second-=t;
				}
			}
	}
	if (res>ans) {
		ans = res;
		cout << ans;
		printf(" -> ");
		rep(i,3) printf("%d ",s[i]);
		printf("\n");
	}

}

void hid(i64 sum, int ind, int p){
	if (ind>=m || p==n) {
		if (sum>ans) ans = sum;
		return;
	}
	
	if (a[0][p].second == 0) hid(sum,ind,p+1);
	if (a[1][ind].second == 0) hid(sum,ind+1,p);

	if (a[0][p].first == a[1][ind].first){
		i64 t = min(a[0][p].Y,a[1][ind].second) ;
		a[0][p].second-=t;
		a[1][ind].second -= t;
		hid(sum+t,ind+1,p);
		hid(sum+t,ind,p+1);
		a[0][p].second += t;
		a[1][ind].second += t;
	} else 
	{
		hid(sum,ind+1,p);
		hid(sum,ind,p+1);
	}

}

int main()
{
	//printf("%d\n",);
	freopen("g3.in","r",stdin);
	freopen("g3.out","w",stdout);
	int testCase;
	scanf("%d",&testCase);
	for(int testNum=0; testNum<testCase; testNum++){
		scanf("%d %d",&n,&m);
		ans=0;
		i64 k;
		int u;
		rep(i,n){
			cin >> k >> u;
			a[0][i] = make_pair(u,k);
		}

		rep(i,m){
			cin >> k >> u;
			a[1][i] = make_pair(u,k);
		}
		int code=7;
		rep(s1,code)
			rep(s2,code)
				rep(s3,code){
					VI s;
					s.clear();
					s.pb(s1);
					s.pb(s2);
					s.pb(s3);
					//process(s);
		}
		hid(0,0,0);
		printf("Case #%d: ",testNum+1);
		cout << ans;
		printf("\n");
					

	}

	return 0;
}

