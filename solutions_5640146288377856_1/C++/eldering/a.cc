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

int maxc = 20;

int r,c,w;
VVI memfind(maxc+1,VI(maxc+1,infty)),
    memnofd(maxc+1,VI(maxc+1,infty));

int bestfind(int l)
{
	debug("bestfind(%d):\n",l);
	if ( w>l ) return 0;
	if ( w==l ) return w;
	if ( memfind[w][l]<infty ) return memfind[w][l];

	int res = infty;
	for(int i=0; i<l; i++) {
		int miss = bestfind(i)+bestfind(l-i-1)+1;
		int hit  = (i==0 || i==l-1 ? w : w+1);
		res = min(res,max(hit,miss));
	}

	debug("bestfind(%d) = %d\n",l,res);
	return memfind[w][l] = res;
}

int bestnofd(int l)
{
	debug("bestnofd(%d):\n",l);
	if ( w>l ) return 0;
	if ( memnofd[w][l]<infty ) return memnofd[w][l];

	int res = infty;
	for(int i=0; i<l; i++) {
		int miss = bestnofd(i)+bestnofd(l-i-1)+1;
		res = min(res,miss);
	}

	debug("bestnofd(%d) = %d\n",l,res);
	return memnofd[w][l] = res;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		cin >> r >> c >> w;

//		assert( r==1 );
		assert( w<=c );

		int findrow = bestfind(c);
		int nofdrow = bestnofd(c);

		int res = findrow + (r-1)*nofdrow;

		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
