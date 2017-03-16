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
#include <iomanip>

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

const int infty = 999999999;

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

int main()
{
	int run, nruns;

	cin >> nruns;
	cout << setprecision(10);

	for(run=1; run<=nruns; run++) {

		int n, na;
		double d, a;
		cin >> d >> n >> na;
//		printf("d = %.2lf, n = %d, na = %d\n",d,n,na);

		vector<pair<double,double> > tx;
//		tx.push_back(make_pair(0.0,0.0));
		int skip = 0;
		REP(i,n) {
			double x,t;
			cin >> t >> x;
			if ( !skip ) tx.push_back(make_pair(t,x));
			if ( x >= d ) skip = 1;
		}
		if ( tx.size()>1 ) {
			int m = tx.size();
//			printf("try last\n");
			double td = ( tx[m-1].first*(d-tx[m-2].second)+
			              tx[m-2].first*(tx[m-1].second-d))/
			    (tx[m-1].second-tx[m-2].second);
			tx[m-1] = make_pair(td,d);
//			printf("last: %.2lE %.2lE\n",td,d);
		}

		cout << "Case #" << run << ":" << endl;
		REP(k,na) {
			double a, ts = 0;
			cin >> a;

			REP(i,tx.size()) {
				double dt = sqrt(2*tx[i].second/a);
				ts = max(ts,tx[i].first-dt);
			}
			ts += sqrt(2*d/a);
			cout << ts << endl;
		}
	}

	return 0;
}
