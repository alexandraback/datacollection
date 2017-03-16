#include <iostream>
#include <iomanip>
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
#include <cassert>

using namespace std;

typedef long long LL;
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

const int dx[8] = {  1, 0,-1, 0, 1,-1,-1, 1 };
const int dy[8] = {  0, 1, 0,-1, 1, 1,-1,-1 };

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int c,d,v;

int possible(VI den)
{
	VI reach(v+1);

	reach[0] = 1;
	REP(i,den.size())
	    for(int j=v-den[i]; j>=0; j--)
			if ( reach[j] ) reach[j+den[i]] = 1;

	REP(i,v+1) if ( !reach[i] ) return 0;
	return 1;
}

int dfs(int last, int rem, VI den)
{
	if ( possible(den) ) return 0;
	if ( rem==0 ) return infty;

// 	debug("dfs(%d,%d, (",last,rem);
// 	REP(i,den.size()) debug("%d,",den[i]);
// 	debug(") )\n");

	int best = infty;
	for(int i=last+1; i<=v; i++) {
		int j;
		for(j=0; j<den.size(); j++) if ( den[j]==i ) break;
		if ( j<den.size() ) continue;
		den.push_back(i);
		best = min(best,dfs(i,rem-1,den)+1);
		den.pop_back();
	}

	return best;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> c >> d >> v;
		VI den(d);
		REP(i,d) cin >> den[i];

		assert( c==1 );

		cout << "Case #" << run << ": ";
		cout << dfs(0,5,den) << endl;
	}

	return 0;
}
