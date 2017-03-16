#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <cassert>
#include <ctime>
#include <list>
#include <bitset>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;

typedef unsigned long long ll;
typedef unsigned long long ull;
 
template<typename T> inline T Abs(T a){ return a>0 ? a : -a; }
template<typename T> inline T sqr(T a){ return a*a; }
template<typename T> inline void relaxMin(T &a,T b){ if (b<a) a=b; }
template<typename T> inline void relaxMax(T &a,T b){ if (b>a) a=b; }

#define _(a,val) memset(a,val,sizeof a);
#define REP(i, a, b) for(int i(a),_bb(b); i < _bb; ++i)
//#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define REPD(i, a, b) for(int i = (b) - 1; i >= a; --i)
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
 
//const int INF = (int)1E9;
const int INF = INT_MAX/2-1;
const long double EPS = 1E-12;
const long double PI = 3.1415926535897932384626433832795;
//#define y1 usfogiudsogndiogbdouigfbsdlifgsdbg
typedef vector<int> vint;
typedef pair<int,int> pii;

#undef assert
#define assert(expr){if (!(expr)) {char *a = 0; *a = 10;} }

#ifdef acm
#include "deb.h"
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) ;
#define deb(...) ;
#endif

int typeA[200];
ll cntA[200];
int typeB[200];
ll cntB[200];

ll ans = 0;

int n,m;

void solve1(){
	ll c2 = 0;
	REP(i,0,m){
		if (typeB[i] == typeA[0])
			c2+=cntB[i];
	}
	ans = min(c2,cntA[0]);
}
void solve2(){
	REP(k,0,m+1){
		ll c1=0,c2=0;
		REP(j,0,k) if (typeB[j]==typeA[0])
			c1+=cntB[j];
		REP(j,k,m) if (typeB[j]==typeA[1])
			c2+=cntB[j];
		c1=min(c1,cntA[0]);
		c2=min(c2,cntA[1]);
		ans = max(ans,c1+c2);
	}
}
void solve3(){
	for(int i=0;i<=m;i++){
		for(int j=i;j<=m;j++){
			ll c1 = 0;
			for(int q=0;q<i;q++)
				if (typeA[0]==typeB[q])
					c1+=cntB[q];
			c1=min(c1,cntA[0]);
			ll c2 = 0;
			for(int q=i;q<j;q++)
				if (typeA[1]==typeB[q])
					c2+=cntB[q];
			c2=min(c2,cntA[1]);
			ll c3 = 0;
			for(int q=j;q<m;q++)
				if (typeA[2]==typeB[q])
					c3+=cntB[q];
			c3=min(c3,cntA[2]);
			ans = max(ans,c1+c2+c3);
		}
	}
}

void solve20(){
		if (typeA[0] == typeA[1]){
			cntA[0]+=cntA[1];
			solve1();
		}else{
			solve2();
		}
}

void solve(){
	cin>>n>>m;
	REP(i,0,n)
		cin>>cntA[i]>>typeA[i];
	REP(i,0,m)
		cin>>cntB[i]>>typeB[i];

	ans = 0;

	if (n==1){
		solve1();
	}else if (n==2){
		solve20();
	}else if (n==3){
		if (typeA[0] == typeA[1]){
			cntA[0]+=cntA[1];
			typeA[1]=typeA[2];
			cntA[1]=cntA[2];
			solve20();
		}else if (typeA[1]==typeA[2]){
			cntA[1]+=cntA[2];
			solve20();
		}else if (typeA[0]==typeA[2]){
			solve3();
			for(int i=0;i<m;i++){
				ll c1 = 0;
				for(int q=0;q<i;q++)
					if (typeA[0]==typeB[q])
						c1+=cntB[q];
				ll c2 = 0;
				for(int q=i+1;q<m;q++)
					if (typeA[2]==typeB[q])
						c2+=cntB[q];
				//
				if (typeB[i]==typeA[0]){
					ll v = cntB[i];
					ll need0 = max(0ULL,cntA[0]-c1);
					ll k = min(v,need0);
					c1+=k;
					c2+=v-k;
				}
				c1=min(c1,cntA[0]);
				c2=min(c2,cntA[2]);
				ans=max(ans,c1+c2);
			}
		}else{
			solve3();
		}
	}
	cout<<ans<<endl;
}


int main(){
#ifdef acm
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	freopen("error.txt", "wt", stderr);
#endif
	//solve();
	int t; scanf("%d\n",&t);
	REP(i,0,t){
		printf("Case #%d: ",i+1);
		solve();
	}

#ifdef acm
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);
#endif
	return 0;
}