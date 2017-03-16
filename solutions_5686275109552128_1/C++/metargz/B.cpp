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

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
	int tnum;
	int P[1123];
	cin >> tnum;
	FOR(ti,1,tnum) {
		int D;
		scanf("%d", &D);
		REP(i,D)
			scanf("%d", &P[i]);
		sort(P,P+D,greater<int>());
		int res = P[0];
		FORD(K,res-1,1) {
			int cur = K;
			REP(i,D) {
				if (P[i] < K)
					break;
				int inc = (P[i]/K);
				if (P[i]%K == 0 && inc > 0)
					--inc;
				cur += inc;
			}
			res = min(res, cur);
		}
		printf("Case #%d: %d\n", ti, res);
	}
    return 0;
}
