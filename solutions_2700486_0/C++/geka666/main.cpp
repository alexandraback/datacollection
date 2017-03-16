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
//const int INF = INT_MAX/2-1;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
#define y1 idfgoseincdjkg
typedef vector<int> vint;
typedef pair<int,int> pii;

#ifdef NDEBUG
#undef assert
#define assert(expr){if (!(expr)) { ++*(char*)0; } }
//#define assert(expr){if (!(expr)) { char *a=0; *a=10; } }
#endif

double ans = 0.0;
int _x,_y;

int f[200][200];

int get(int i,int j){
	return f[100+i][100+j];
}
void set1(int i,int j,int val){
	//for(int dx=-1;dx<=1;dx++) for(int dy=-1;dy<=1;dy++)
	//f[50+i+dx][50+j+dy]=val;
	f[100+i][100+j]=val;
}

void fill(int left,double prob,int px=0,int py=30){
	if (left == 0){
		ans+=get(_x,_y)*prob;
		return;
	}
	while(py>0 && get(px,py-2) == 0 && get(px-1,py-1) == 0 && get(px+1,py-1) == 0) py--;

	if (py==0){
		set1(px,py,1);
		fill(left-1,prob);
		set1(px,py,0);
		return;
	}else if(get(px,py-2) == 1){
		if (get(px+1,py-1) == 0 && get(px-1,py-1) == 0){
			fill(left,prob*0.5,px+1,py-1);
			fill(left,prob*0.5,px-1,py-1);
		}else if (get(px+1,py-1) == 0)
			fill(left,prob,px+1,py-1);
		else if (get(px-1,py-1) == 0)
			fill(left,prob,px-1,py-1);
		else{
			set1(px,py,1);
			fill(left-1,prob);
			set1(px,py,0);
		}
	}else if (get(px-1,py-1) == 1 && get(px+1,py-1) == 1){
		set1(px,py,1);
		fill(left-1,prob);
		set1(px,py,0);
	}else if (get(px-1,py-1) == 1){
		fill(left,prob,px+1,py-1);
	}else if (get(px+1,py-1) == 1){
		fill(left,prob,px-1,py-1);
	}
}

void solve(){
	int n; cin>>n>>_x>>_y;

	ans = 0.0;
	_(f,0);
	

	if (abs(_x)<=20 && abs(_y)<=20)
		fill(n,1.0);
	printf("%.10f\n",ans);
}


//#define TASK "equality"
int main(){
#ifdef acm
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	//freopen("error.txt", "wt", stderr);
#else
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	//freopen(TASK".in", "rt", stdin);
	//freopen(TASK".out", "wt", stdout);
#endif
	srand(0xA1B2C3D4);
	int tc; scanf("%d\n",&tc);
	REP(i,0,tc){
		printf("Case #%d: ",i+1);
		solve();
	}
	//solve();


#ifdef acm
	//printf("\n\n\n\n\n%.3lf\n", clock()*1e-3);
#endif
	return 0;
}