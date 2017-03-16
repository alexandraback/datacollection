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

char L[10001];
string symb="-1ijk";
int X;
int l;

int _i=2, _j=3, _k=4;
int mat[][5] = {
	{0,0 ,0  ,0  ,0  },
	{0,1 ,_i ,_j ,_k },
	{0,_i,-1 ,_k ,-_j},
	{0,_j,-_k,-1 ,_i },
	{0,_k,_j ,-_i,-1 },
};

int mult(int p, char c) {
	int i = symb.find(c);
	if (p < 0) {
		return -mat[-p][i];
	}
	return mat[p][i];
}
int mult2(int c, int p) {
	int i = symb.find(c);
	if (p < 0) {
		return -mat[i][-p];
	}
	return mat[i][p];
}

int beg (int v) {
	for(int i = 0, p = 1; i < X*l; i++) {
		p = mult(p, L[i%l]);
//		printf("p=%d vs v=%d\n", p, v);
		if (p == v) return i;
	}
	return -1;
}
int last (int v) {
	for(int i = X*l-1, p = 1; i >= 0; i--) {
		p = mult2(L[i%l], p);
//		printf("p=%d for v=%d\n", p, v);
		if (p == v) return i;
	}
	return -1;
}

bool solve() {
	int n = beg(_i), m = last(_k);
//	printf("n=%d, m=%d\n", n, m);
	if (n == -1 || m == -1 || n >= m) return false;
	int p = 1;
	for(int i = n+1; i < m; i++) p = mult(p, L[i%l]);//, printf("p=%d\n", p);
	return p == _j;
}

int getX(LL x) {
	if (x <= 12) return x;
	LL v = (x - 12)/4;
	return x - v*4;
}

int main()
{
//	REP(i, 100) printf("%d = %d\n",i,  getX(i));
	TI(t);
	REP(i, t) {
		l = rint();
		X = getX(rLL());
//		printf("X = %d\n", X);
		scanf("%s", L);
		printf("Case #%d: %s\n", i+1, solve() ? "YES" : "NO");
	}
	return 0;
}
