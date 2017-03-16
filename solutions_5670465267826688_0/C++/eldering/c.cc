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

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...)
#endif

// Encode quaternion as base 1,i,j,k counted from one with +/-
// coefficient prefixed.

// Base vector multiplication table, zero-based indexing.
const int mult[4][4] = {{  1, 2, 3, 4 },
						{  2,-1, 4,-3 },
						{  3,-4,-1, 2 },
						{  4, 3,-2,-1 }};

int qmul(int a, int b)
{
//	debug("qmul %d * %d = ",a,b);
	int sign = (a > 0 ? 1 : -1)*(b > 0 ? 1 : -1);
	if ( a < 0 ) a = -a;
	if ( b < 0 ) b = -b;
	int res = mult[a-1][b-1];
//	debug("%d %d\n",sign,res);
	return sign*res;
}

int qinv(int a)
{
	if ( a==-1 || a==1 ) return a;
	return -a;
}

int c2q(char c)
{
	switch ( c ) {
	case 'i': return 2;
	case 'j': return 3;
	case 'k': return 4;
	}
	return 0;
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {
		string ls, s;
		int x, l;
		cin >> l >> x >> ls;
		REP(i,x) s += ls;
		int n = s.length();

		VI left(n), right(n);
		left[0] = c2q(s[0]);
		right[0] = c2q(s[n-1]);
		for(int i=1; i<n; i++) {
			left[i]  = qmul(left[i-1],c2q(s[i]));
			right[i] = qmul(c2q(s[n-1-i]),right[i-1]);
			debug("i=%d: left = %d right = %d\n",i,left[i],right[i]);
		}

		bool possible = false;
		int qs = left[n-1];
		debug("qs = %d\n",qs);
		REP(i,n) {
			if ( left[i]!=c2q('i') ) continue;
			debug("i=%d ok\n",i);
			REP(j,n-2-i) {
			    if ( right[j]!=c2q('k') ) continue;
				debug("j=%d ok\n",j);
				int mid = qmul(qinv(left[i]),qmul(qs,qinv(right[j])));
				debug("mid = %d = %d * %d * %d = l * %d = %d * r\n",
				      mid,qinv(left[i]),qs,qinv(right[j]),
				      qmul(qs,qinv(right[j])),qmul(qinv(left[i]),qs));
				if ( mid==c2q('j') ) {
					possible = true;
					break;
				}
			}
		}

		cout << "Case #" << run << ": ";
		cout << ( possible ? "YES" : "NO" ) << endl;
	}

	return 0;
}
