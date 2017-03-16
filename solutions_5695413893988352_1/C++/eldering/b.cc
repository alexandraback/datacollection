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

string c,j;
LL bestd, bestc, bestj;

vector<pair<int,int>> opt = { {0,0}, {0,1}, {1,0} };

void dfs(int i, LL cpre, LL jpre)
{
	debug("i = %d, cpre = %lld, jpre = %lld,   bestd = %lld\n",i,cpre,jpre,bestd);
	if ( i == c.length() ) {
		LL d = abs(cpre-jpre);
		debug("done: d = %lld\n",d);
		if ( d<bestd ||
		     (d==bestd && cpre<bestc) ||
		     (d==bestd && cpre==bestc && jpre<bestj) ) {
			bestd = d;
			bestc = cpre;
			bestj = jpre;
		}
		return;
	}

	if ( c[i]=='?' ) {
		if ( j[i]=='?' ) {
			if ( cpre<jpre ) {
				dfs(i+1,10*cpre+9,10*jpre+0);
			} else if ( cpre>jpre ) {
				dfs(i+1,10*cpre+0,10*jpre+9);
			} else {
				REP(k,3) dfs(i+1,10*cpre+opt[k].first,10*jpre+opt[k].second);
			}
		} else {
			if ( cpre<jpre ) {
				dfs(i+1,10*cpre+9,10*jpre+j[i]-'0');
			} else if ( cpre>jpre ) {
				dfs(i+1,10*cpre+0,10*jpre+j[i]-'0');
			} else {
				for(int k=max(0,j[i]-'0'-1); k<=min(9,j[i]-'0'+1); k++)
					dfs(i+1,10*cpre+k,10*jpre+j[i]-'0');
			}
		}
	} else {
		if ( j[i]=='?' ) {
			if ( cpre<jpre ) {
				dfs(i+1,10*cpre+c[i]-'0',10*jpre+0);
			} else if ( cpre>jpre ) {
				dfs(i+1,10*cpre+c[i]-'0',10*jpre+9);
			} else {
				for(int k=max(0,c[i]-'0'-1); k<=min(9,c[i]-'0'+1); k++)
					dfs(i+1,10*cpre+c[i]-'0',10*jpre+k);
			}
		} else {
			dfs(i+1,10*cpre+c[i]-'0',10*jpre+j[i]-'0');
		}
	}
}

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {
		cin >> c >> j;

		bestd = (1LL<<63) - 1;

		dfs(0,0,0);

		int n = c.length();

		printf("Case #%d: %0*lld %0*lld\n",run,n,bestc,n,bestj);
	}

	return 0;
}
