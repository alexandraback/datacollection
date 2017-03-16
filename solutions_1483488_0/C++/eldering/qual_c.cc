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

int main()
{
	int run, nruns;

	cin >> nruns;

	for(run=1; run<=nruns; run++) {

		LL a,b;

		cin >> a >> b;

		LL res = 0;
		for(LL n=a; n<=b; n++) {
			vector<int> dig;
			LL x = n;
			while ( x!=0 ) { dig.push_back(x%10); x /= 10; }
			int p = dig.size();

			set<LL> have;
			for(int i=0; i<p; i++) {
				LL m = 0;
				for(int j=0; j<p; j++) {
					m *= 10;
					m += dig[(p+i-j)%p];
				}
				if ( a<=n && n<m && m<=b && have.count(m)==0 ) {
					res++;
					have.insert(m);
					debug("found %3lld: %lld <= %lld < %lld <= %lld\n",res,a,n,m,b);
				}
			}
		}

		cout << "Case #" << run << ": ";
		cout << res << endl;
	}

	return 0;
}
