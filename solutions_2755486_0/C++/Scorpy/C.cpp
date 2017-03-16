#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <utility>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vi vector<int>
#define rep(i,n) for( int i = 0; i < (n); i++ )
#define forn(i,a,b) for( int i = (a); i < (b); i++ )
#define fi first
#define se second

const int MXN = 4000100;
const int MXV = 500; // max absolute value of coordinate
const int MXM = 500;
const int MXA = 1000; // max number of attacks
const int MXC = 1000; // max coordinate


struct attack{
	int w,e,s,d;
};

attack ats [MXA];
int atc = 0;

bool cmp( attack a, attack b ){
	return a.d < b.d;
}

int wall [MXC];

bool succes ( int ind ){
	for( int i = ats[ind].w + MXV; i < ats[ind].e + MXV; i++ ){
		if( wall[i] < ats[ind].s ) return true;
	}

	return false;
}
void raise ( int ind ){
	for( int i = ats[ind].w + MXV; i < ats[ind].e + MXV; i++ ){
		wall[i] = max(wall[i], ats[ind].s);
	}

}


int solve(){
	rep(i,MXC) wall[i] = 0;

	atc = 0;
	int n;
	scanf("%d", &n);

	int dd,ni,dp,ds;

	rep(i,n){
		scanf("%d%d%d%d%d%d%d%d", &ats[atc].d, &ni, &ats[atc].w, &ats[atc].e, &ats[atc].s, &dd, &dp, &ds);
		atc++;
		rep(j,ni-1){
			ats[atc].d = ats[atc-1].d + dd;
			ats[atc].w = ats[atc-1].w + dp;
			ats[atc].e = ats[atc-1].e + dp;
			ats[atc].s = ats[atc-1].s + ds;
			atc++;
		}
	}
	sort( ats, ats+atc, cmp );

	int i = 0;
	int res = 0;
	for(;i < atc;){
		int j = i;
		for( ; j < atc && ats[j].d == ats[i].d; j++ )
			res += succes(j);
		j = i;
		for( ; j < atc && ats[j].d == ats[i].d; j++ )
			raise(j);
		i = j;
	}

	return res;
}

int main(){
	freopen("C.in", "r", stdin);	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);

	rep(i,T){
		printf("Case #%d: %d\n", i+1, solve());
	}
}	