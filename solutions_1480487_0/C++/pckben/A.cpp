#include <sstream>
#include <iostream>
#include <iomanip>

#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
 
using namespace std;
 
#define REP(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=b;--i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define SIZE(a)  (int(a.size()))
#define SET(a,x) memset((a),(x),sizeof(a)) 
 
#define DEBUG 1
#if DEBUG
#define debug(msg) cerr << msg << endl;
#define debugx(x) cerr<< #x << " = " << (x) << endl;
#define debugai(a,i) cerr<< #a << "["<<(i)<<"] = " << (a)[(i)] << endl
#define debugv(v) cerr << #v << " = "; FOREACH(it,v) cerr << *it <<","; cerr << endl;
#define debuga(a,N) cerr << #a << " = "; REP(i,N) cerr << a[i] << " "; cerr << endl;
#define debugm(m,N,M) \
	cerr << #m << " = " << endl; \
	REP(i,N) { \
		REP(j,M) cerr << m[i][j] << " "; \
		cerr << endl; \
	}
#else
#define debug(msg)
#define debugx(x)
#define debugai(a,i) 
#define debugv(v)
#define debuga(a,N)
#define debugm(m,N,M)
#endif

#define INF 1000000000
#define EPS 1e-100f
#define MAX 200

ifstream fin("A-small-attempt4.in");
ofstream fout("try.out");
int s[MAX];

int main() {
	int T;
	fin >> T;
	for (int test=1;test<=T;test++) {
		int N;
		int X=0;
		fin >> N;
		REP(i, N) {
			fin >> s[i];
			X += s[i];
		}

		fout << "Case #" << test << ":";

		int N0=0, X0=0;
		REP(i,N) {
			double y = double(100*(2*X-N*s[i]))/double(N*X);
			if(y  <0 ) {
				N0++;
				X0 += s[i];
			}
		}

		debugx(N0);

	    REP(i,N) {
			double y = double(100*(2*X-N*s[i]))/double(N*X);
			if (y>=0) {
				y = double(100*(2*X-X0-(N-N0)*s[i]))/double((N-N0)*X);
			} else {
				y = 0;
			}

			fout << " " << fixed << setprecision(6) << y; 
		}
		fout << endl;
	}
}

