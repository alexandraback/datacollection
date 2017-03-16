// directives 
	#include <stdio.h>
	#include <vector>
	#include <map>
	#include <set>
	#include <deque>
	#include <queue>
	#include <algorithm>
	#include <iostream>
	#include <cmath>
	#include <cstring>
	#include <typeinfo>
	#include <sstream>
// 
using namespace std;
// macros 
	#define FOR(i,a,b)      for(int i(a);i<b;++i)
	#define REP(i,n)        FOR(i,0,n)
	#define FORD(i,a,b)      for(int i(a-1);i>=b;--i)
	#define CL(a,x)         memset(a,x,sizeof(a))
	#define FL(a,x)			fill_n(a,sizeof(a)/sizeof(a[0]),x)
	#define asort(a,n)		sort(a,a+n)
	#define vsort(v,n)		sort(v.begin(), v.begin()+n)
	#define sz(x)			x.size()
	#define all(x)			x.begin(), x.end()
	#define SSTR( x )		dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()
	#define TI(x)		int x = rint()
	#define TII(x,y)		int x = rint(),y = rint()
	#define TIII(x,y,z)		int x = rint(),y = rint(),z = rint()
// 

typedef long long LL;
typedef vector<int> vi;
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
LL rLL() { LL x; if(scanf("%I64d",&x)!=1) return -1; return x; }

bool solve_1(int r, int c) {
	return true;
}

bool solve_2(int r, int c) {
	return (r*c)%2 == 0;
}

bool solve_3(int r, int c) {
	if (r == 2)
		return c == 3;
	if (r == 3) 
		return c >= 3;
	return false;
}

// return true if Gabrial is guarenteed to win, no matter what Richard picks
bool solve_4(int r, int c) {
	return (r >= 3 && c == 4);
}

bool solve(int X, int r, int c) {
	switch(X) {
		case 1: return solve_1(r,c);
		case 2: return solve_2(r,c);
		case 3: return solve_3(r,c);
		case 4: return solve_4(r,c);
	}
	return false;
}

int main()
{
	TI(t);
	REP(i, t) {
		TIII(X,r,c);
		if (r > c) swap(r,c);
		printf("Case #%d: %s\n", i+1, solve(X,r,c) ? "GABRIEL" : "RICHARD");
	}
	return 0;
}
