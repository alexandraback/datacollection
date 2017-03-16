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

int reverse(int n)
{
	if ( n%10==0 ) return n;
	int res = 0;
	for(; n!=0; n/=10) {
		res *= 10;
		res += n%10;
	}
	return res;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		int n, y = 1;
		cin >> n;
		int N = n;
		VI best(n+1,infty);
		best[1] = 1;
		for(int i=2; i<=n; i++) {
			best[i] = best[i-1]+1;
			if ( reverse(i)<i ) best[i] = min(best[i],best[reverse(i)]+1);
		}
		/*
		while ( n!=1 ) {
			if ( reverse(n)<n ) {
				debug("reverse: %d -> %d\n",n,reverse(n));
				n = reverse(n);
			} else {
				n--;
			}
			y++;
		}
		*/

		cout << "Case #" << run << ": ";
		cout << best[n] << endl;

//		debug("n = %d: res = %d
	}

	return 0;
}
