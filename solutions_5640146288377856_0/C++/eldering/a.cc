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

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

int r,c,w;
VVI mem;

int best(int l)
{
	debug("best(%d):\n",l);
	if ( w>l ) return 0;
	if ( w==l ) return w;
	if ( mem[w][l]<infty ) return mem[w][l];

	int res = infty;
	for(int i=0; i<l; i++) {
		int miss = best(i)+best(l-i-1)+1;
		int hit  = (i==0 || i==l-1 ? w : w+1);
		res = min(res,max(hit,miss));
	}

	debug("best(%d) = %d\n",l,res);
	return mem[w][l] = res;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> r >> c >> w;

		assert( r==1 );
		assert( w<=c );

		mem = VVI(w+1,VI(c+1,infty));

		int res = best(c);

		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
