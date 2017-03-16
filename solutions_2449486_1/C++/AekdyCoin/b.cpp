//
//  main.cpp
//  intern
//
//  Created by AekdyCoin on 13-1-15.
//  Copyright (c) 2013年 AekdyCoin. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long LL ;
typedef double db;
#define rep(i,n) for(int i=0;i<n;++i)
#define mp make_pair
#define pb push_back

vector< pair< int, pair<int,int> > > v;
const int MAXN = 111;
int a[ MAXN ][ MAXN ];
int n, m;

bool ok(int v, int x, int y) {
	bool flg=1;
	rep(i,m) if(a[x][i] > v) {flg=0; break;}
	if(flg)return 1;flg=1;
	rep(i,n) if(a[i][y] > v) {flg=0;break;}
	return flg;
}

int main(int argc, const char * argv[]){
	freopen("B-small-attempt0.in","r", stdin);
	freopen("B-small-attempt0.out","w" , stdout);
	int T; cin >> T;
	while(T --) {
		static int cas = 0; ++ cas;
		cin>>n>>m; v.clear();
		rep(i,n) rep(j,m) cin>>a[i][j],v.pb(mp(a[i][j], mp(i,j)));
		sort(v.begin(), v.end());
		int ans = 1;
		rep(i, v.size()) {
			if(!ok(v[i].first, v[i].second.first, v[i].second.second)) {
				ans = 0;
			}
		}
		printf("Case #%d: %s\n", cas , ans? "YES" : "NO");
	}
	return 0;
}

