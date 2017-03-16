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

const int MAXN = 1e7;
bool ok[ MAXN ];
vector< LL > v;
int n;

bool ispal( LL x) {
	if(!x)return 0;
	static int d[20],dlen;
	dlen=0;
	while(x) d[dlen++]=x%10,x/=10;
	rep(i,dlen) if(d[i]!= d[dlen-i-1]) return 0;
	return 1;
}

void init(){
	rep(i,MAXN) ok[i]=ispal(i);
	rep(i,MAXN) if(ok[i]) {
		LL j=i;
		if(ispal(j*j)) v.pb(j*j);
	}
	sort(v.begin(), v.end());
	n=unique(v.begin(), v.end())-v.begin();
	while(v.size() > n) v.pop_back();
}

int cnt( LL x) {
	return upper_bound(v.begin(), v.end(), x) - v.begin();
}

int main(int argc, const char * argv[]){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);
	init();
	int T; cin >> T;
	while(T --) {
		static int cas = 0; ++ cas;
		LL L , R; cin >> L >> R ;
		printf("Case #%d: %d\n", cas, cnt(R) - cnt(L-1));
	}
	return 0;
}

