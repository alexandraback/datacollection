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


int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {

		vector<pair<string,string>> topics;
		string w1,w2;

		int n;
		cin >> n;
		REP(i,n) {
			cin >> w1 >> w2;
			topics.push_back(make_pair(w1,w2));
		}

		int best = 0;
		for(int b=0; b<(1<<n); b++) {
			debug("b = %d\n",b);
			int nf = 0;
			bool ok = true;
			REP(f,n) {
				if ( b&(1<<f) ) {
					debug("fake = %d: %s_%s\n",f,topics[f].first.c_str(),topics[f].second.c_str());
					nf++;
					bool find1 = false, find2 = false;
					REP(i,n) {
						if ( (b&(1<<i))==0 ) {
							if ( topics[f].first ==topics[i].first ) find1 = true;
						}
					}
					REP(i,n) {
						if ( (b&(1<<i))==0 ) {
							if ( topics[f].second==topics[i].second ) find2 = true;
						}
					}
					debug("find: %d %d\n",(int)find1,(int)find2);
					if ( !(find1 && find2) ) ok = false;
				}
			}
			if ( ok && nf>best ) best = nf;
		}


		cout << "Case #" << run << ": ";
		cout << best << endl;

	}

	return 0;
}
