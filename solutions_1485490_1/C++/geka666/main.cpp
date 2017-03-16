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

typedef long long ll;
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

ll dp[200][200];
ll usedA[200][200];
ll usedB[200][200];

void solve(){
	int n,m; cin>>n>>m;
	REP(i,0,n)
		cin>>cntA[i]>>typeA[i];
	REP(i,0,m)
		cin>>cntB[i]>>typeB[i];
	_(dp,0);
	_(usedA,0);
	_(usedB,0);
	REP(i,0,n+1){
		REP(j,0,m+1){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			
			ll sa = 0;
			for(int k=0;i+k<n;k++){
				//dp[i+k+1][j+1]=max(dp[i+k+1][j+1],dp[i][j]);

				if (typeA[i+k]==typeB[j])
					sa+=cntA[i+k];

				dp[i+k+1][j+1]=max(dp[i+k+1][j+1],dp[i][j]+min(sa,cntB[j]));
			}
			ll sb = 0;
			for(int k=0;i+k<n;k++){
				//dp[i+1][j+k+1]=max(dp[i+1][j+k+1],dp[i][j]);

				if (typeA[i]==typeB[j+k])
					sb+=cntB[j+k];

				dp[i+1][j+k+1]=max(dp[i+1][j+k+1],dp[i][j]+min(sb,cntA[i]));
			}
		}
	}
	/*REP(i,0,n+1){
		REP(j,0,m+1){
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			dp[i][j+1]=max(dp[i][j+1],dp[i][j]);
			if (typeA[i] == typeB[j]){
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+min(cntA[i],cntB[j]));
			}
		}
	}*/
	cout<<dp[n][m]<<endl;
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