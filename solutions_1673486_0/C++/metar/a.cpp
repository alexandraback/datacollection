#include <algorithm>
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
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long ulong;
typedef unsigned long long ull;

int main() {
	//freopen("problem.in", "r", stdin);
	//freopen("problem.out", "w", stdout);
	int tnum;
	cin >> tnum;
	REP(ti,tnum) {
		int a, b;
		cin >> a >> b;
		ld e = b+2, ok = 1, p;		
		REP(i,a) {
			cin >> p;
			ok *= p;
			e = min(e, (a-i-1)*2+b-a+1+(1-ok)*(b+1));
			//printf("%d -- %.6Lf\n", i+1, (a-i-1)*2+b-a+1+(1-ok)*(b+1));			
		}
		printf("Case #%d: %.6Lf\n", 1+ti, e);
		
	}
	return 0;
}