#define _CRT_SECURE_NO_DEPRECATE
//#pragma comment(linker, "/STACK:200000000")

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

const int INF = (int)1E9;
const ll INF64 = (ll)1E18;
//const int INF = INT_MAX/2-1;
const long double EPS = 1E-8;
const long double PI = 3.1415926535897932384626433832795;
#define y1 idfgoseincdjkg
typedef vector<int> vint;
typedef pair<int,int> pii;

#undef assert
int assert(bool expr){if (!(expr)) { ++*(char*)0; }; return 0; }


double c,f,x;


void solve(){
	cin>>c>>f>>x;

	double ans = x/2.0;

	double t = 0.0;

	for(int k = 0;k < x;k++){
		double r1 = 2.0 + k * f;
		double dt = c / r1;
		t+=dt;
		double r2 = 2.0 + (k+1) * f;
		ans = min(ans, t + x / r2);
	}

	printf("%.10f\n",ans);
}



int main(){
#ifdef acm
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	freopen("error.txt", "wt", stderr);
#else
	//freopen("snakes2.in", "rt", stdin);
	//freopen("snakes2.out", "wt", stdout);
#endif
	srand(0xA1B2C3D4);
	//pre();
	//int tc; cin>>tc; while(tc--) solve();
	//solve();
	int tc; scanf("%d\n",&tc);
	REP(i,0,tc){
		printf("Case #%d: ",i+1);
		solve();
	}

#ifdef acm
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);
#endif
	return 0;
}
