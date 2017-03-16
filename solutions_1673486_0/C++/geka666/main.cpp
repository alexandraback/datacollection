#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:256000000")

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
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
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
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#else
#define dbg(...) ;
#endif

double pp[100500];
double ans[100500];

void solve(){
	int a,b; cin>>a>>b;
	REP(i,0,a) cin>>pp[i];
	pp[a]=0.0;
	double p0 = 1.0;
	double x = 1e18;
	REP(i,0,a){
		p0*=pp[i];
		ans[i]=b-a+(a-i-1)*2+1+(1-p0)*(b+1);
		x=min(x,ans[i]);
	}
	x = min(x,b+2.0);
	printf("%.10f\n",x);
}

int main(){
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t; scanf("%d\n",&t);
	for(int i=0;i<t;i++){
		printf("Case #%d: ",i+1);
		solve();
	}
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);

	return 0;
}