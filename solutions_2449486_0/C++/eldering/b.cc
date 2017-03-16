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

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

int X,Y;
VVI height;

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> Y >> X;
		height = VVI(X,VI(Y,100));
		VI maxrow(Y,0), maxcol(X,0);

		REP(y,Y) REP(x,X) {
			cin >> height[x][y];
			maximize(maxrow[y],height[x][y]);
			maximize(maxcol[x],height[x][y]);
		}

		bool possible = true;
		REP(y,Y) REP(x,X)
		    if ( height[x][y]!=min(maxrow[y],maxcol[x]) ) possible = false;

		cout << "Case #" << run << ": "
			 << (possible ? "YES" : "NO") << endl;
	}

	return 0;
}
