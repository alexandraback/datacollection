#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <set>
#include <algorithm>
#include <utility>
#include <functional>
#include <numeric>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef unsigned long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define ALL(x) ((x).begin()),((x).end())
#if __cplusplus >= 201103L
#define FOR(i,c) for(auto i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(decltype(n) i=0; i<(n); ++i)
#else
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)
#endif

const int infty = 999999999;

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		int E,R,n;
		cin >> E >> R >> n;
		VI v(n);
		REP(i,n) cin >> v[i];

		LL gain = 0;
		int Enow = E;
		REP(i,n) {
			int j;
			LL spend;
			for(j=i+1; j<n; j++) if ( v[j]>v[i] ) break;
			if ( j<n ) {
				spend = max(Enow+(j-i)*R-E,0);
			} else {
				spend = Enow;
			}
			if ( spend>Enow ) spend = Enow;
			gain += spend*v[i];
			Enow += R - spend;
		}

		cout << "Case #" << run << ": ";
		cout << gain << endl;

	}

	return 0;
}
