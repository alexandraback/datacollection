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

		LL r, t;

		cin >> r >> t;

		LL y, ymin = 1, ymax = 1000000001;
		while ( ymin<ymax ) {
			y = (ymin+ymax+1)/2;
//			debug("%lld %lld %lld\n",ymin,y,ymax);
			double Td = 2.0*r*y + 2*y*y - y;
			LL     T  = 2  *r*y + 2*y*y - y;
			if ( Td>3E18 || T>t ) {
				ymax = y-1;
			} else {
				ymin = y;
			}
		}

		cout << "Case #" << run << ": ";
		cout << ymin << endl;
	}

	return 0;
}
