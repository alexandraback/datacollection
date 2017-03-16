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

int k,l,s;
string target, keys;
int maxw, sumw, ns;

void count(string str)
{
	ns++;
	int n = 0;
	REP(i,s-l+1) if ( str.substr(i,l)==target ) n++;
	sumw += n;
	maxw = max(maxw,n);
}

void gen(string str)
{
	if ( str.length()==s ) {
		count(str);
		return;
	}

	REP(i,keys.size()) gen(str+keys[i]);
}

int main()
{
	int nruns;
	cin >> nruns;

	cout << setprecision(10);

	for(int run=1; run<=nruns; run++) {

		cin >> k >> l >> s;
		cin >> keys >> target;

		double res = 0;

		bool pos = true;
		REP(i,target.length()) {
			if ( keys.find(target[i])==string::npos ) pos = false;
		}
		if ( !pos ) {
			debug("no solution\n");
			goto done;
		}

		ns = sumw = maxw = 0;

		gen(string());

		res = maxw - (double)sumw/ns;

		debug("ns = %d, maxw = %d, sumw = %d\n",ns,maxw,sumw);

	  done:
		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
