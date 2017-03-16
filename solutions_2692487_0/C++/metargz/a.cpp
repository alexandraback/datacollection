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
typedef vector<vector<int> >    VVI;
typedef vector<char>            VC;

vector<int> m;

int main() {
    //freopen("input",  "r", stdin);
    //freopen("output", "w", stdout);
	int TNUM;
	cin >> TNUM;
	FOR(TI,1,TNUM) {
		ll A;
		int N;
		cin >> A >> N;
		m.resize(N);
		REP(i,N) cin >> m[i];
		if (A == 1) {
			printf("Case #%d: %d\n", TI, N);
			continue;
		}
		sort(m.begin(), m.end());
		int cnt = 0, rem = 0;
		REP(i,N) {
			if (m[i] >= A) {
				if (rem == 0 || cnt+N-i < rem)
					rem = cnt+N-i;
				for (; A <= m[i]; A += A-1)
					++cnt;

			}
			A += m[i];
		}
		printf("Case #%d: %d\n", TI, min(cnt, rem));
	}
    return 0;
}
