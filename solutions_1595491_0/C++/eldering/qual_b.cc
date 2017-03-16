using namespace std;
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
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef istringstream ISS;

#define maximize(a,b) a = max((a),(b))

#define PB push_back
#define ALL(x) ((x).begin()),((x).end())
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)

const int infty = 999999999;

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

int maxscore(int tot, int surprise)
{
	int res = tot/3;
	if ( tot%3!=0 ) res++;

	if ( surprise ) {
		int better = res+1;
		if ( tot >= better + 2*(max(better-2,0)) ) res = better;
		better = res+1;
		if ( tot >= better + 2*(max(better-2,0)) ) res = better;
	}

	return res;
}

int main()
{
	int run, nruns;

	cin >> nruns;

	for(run=1; run<=nruns; run++) {

		int N, S, p;
		cin >> N >> S >> p;

		VI total(N);
		REP(i,N) cin >> total[i];

		VVI best(N+1,VI(S+2));

		REP(n,N) REP(s,S+1) {
			debug("best[%d][%d] = %d\n",n,s,best[n][s]);
			maximize(best[n+1][s],best[n][s]);
			if ( maxscore(total[n],0)>=p ) maximize(best[n+1][s],  best[n][s] + 1);
			if ( maxscore(total[n],1)>=p ) maximize(best[n+1][s+1],best[n][s] + 1);
		}

		int res = 0;
		REP(s,S+1) maximize(res,best[N][s]);

		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
