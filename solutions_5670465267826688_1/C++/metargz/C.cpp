#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define VAR(a,b)        __typeof(b) a=(b)
#define REP(i,n)        for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b)      for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b)     for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c)   for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c)          (c).begin(),(c).end()
#define TRACE(x)        cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x)        cerr << #x << " = " << x << endl;
#define eprintf(...)    fprintf(stderr, __VA_ARGS__)

typedef long long               ll;
typedef long double             ld;
typedef unsigned long           ulong;
typedef unsigned long long      ull;
typedef vector<int>             VI;
typedef vector<char>            VC;

const int ONE = 1;
const int I = 2;
const int J = 3;
const int K = 4;

int prod[4][4] =
	{ {ONE, I, J, K}, {I, -ONE, K, -J}, {J, -K, -ONE, I}, {K, J, -I, -ONE} };
int lpow[99];

int id[5] = { -1, 0, 1, 2, 3};

string s;

int sign(int x) {
	if (x > 0)
		return +1;
	else if (x < 0)
		return -1;
	else
		return 0;
}

int mul(int x, int y) {
	int lhs = abs(x);
	int rhs = abs(y);
	//assert(lhs == ONE or lhs == I or lhs == J or lhs == K);
	//assert(rhs == ONE or rhs == I or rhs == J or rhs == K);
	return sign(x) * sign(y) * prod[id[lhs]][id[rhs]];	
}

int get(int i) {
	return s[i]+2-'i';
}

int fst[11234], lst[11234];

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
    int tnum;
	cin >> tnum;
	FOR(ti,1,tnum) {
		ll L, C;
		ll X;
		cin >> L >> X >> s;
		ll lp = ONE;
		//cerr << L << ' ' << X << ' ' << s << endl;
		//assert(L == s.size());
		REP(i,L)
			lp = mul(lp, get(i));
		lpow[0] = ONE;
		for (C = 1; ; ++C){
			lpow[C] = mul(lpow[C-1], lp);			
			if (lpow[C] == ONE)
				break;
		}
		bool res = false;
		//assert(C < 99);
		//assert(lpow[C-1] == lpow[(10*C-1)%C]);
		fst[0] = ONE;
		FOR(i,1,L)
			fst[i] = mul(fst[i-1], get(i-1));
		lst[L] = ONE;
		FORD(i,L-1,0)
			lst[i] = mul(get(i), lst[i+1]);
		FOR(i,0,L) {
			int btwij = ONE;
			FOR(j,i+1,L) {
				btwij = mul(btwij, get(j-1));
				if (i < j && btwij == J)
				FOR(x, 0, min(C,X-1)) {					
					int lhs = mul(lpow[x], fst[i]);
					if (lhs != I)
						continue;
					int rhs = mul(lst[j], lpow[(X-1-x)%C]);
					if (rhs == K) {
						res = true;
						goto lbl;
					}
				}
			}
			if (X >= 2)
			FOR(j,0,L) {
				int btw0i = fst[i];
				int btwiL = lst[i];
				int btw0j = fst[j];
				int btwjL = lst[j];
				FOR(x, 0, min(C,X-2)) {					
					int lhs = mul(lpow[x], btw0i);
					if (lhs != I)
						continue;
					FOR(y, 0, min(C,X-x-2)){
						int mid = mul(mul(btwiL, lpow[y]), btw0j);
						if (mid != J)
							continue;
						int rhs = mul(btwjL, lpow[(X-2-x-y)%C]);
						if (rhs == K) {
							res = true;
							goto lbl;
						}

					}
				}
			}
		}
		lbl: ;
		if (res)
			printf("Case #%d: YES\n", ti);
		else
			printf("Case #%d: NO\n", ti);
		fflush(stdout);
	}
    return 0;
}
