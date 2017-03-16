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
#define FOR(i,c) for(typeof(c.begin()) i=c.begin(); i!=c.end(); ++i)
#define REP(i,n) for(typeof(n) i=0; i<(n); ++i)

template<class T> void minimize(T &a, T b) { a = min(a,b); }
template<class T> void maximize(T &a, T b) { a = max(a,b); }

const int infty = 999999999;

//#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

multiset<int> keys;
VI chesttype;
vector<multiset<int> > chestkeys;

int main()
{
	int nruns;
	cin >> nruns;

	for(int run=1; run<=nruns; run++) {
		int K,N,key;

		cin >> K >> N;
		keys.clear();
		REP(i,K) { cin >> key; keys.insert(key); }

		chesttype = VI(N);
		chestkeys = vector<multiset<int> >(N);

		REP(i,N) {
			cin >> chesttype[i] >> K;
			REP(j,K) { cin >> key; chestkeys[i].insert(key); }
		}

		VI reach(1<<N,0), prev(1<<N,-1);
		queue<pair<int,int> > visit;
		visit.push(make_pair(0,-1));
		while ( !visit.empty() ) {
			int done = visit.front().first;
			int from = visit.front().second;
			visit.pop();

			if ( reach[done] ) continue;

  			debug("done = %d, from = %d\n",done,from);
			reach[done] = 1;
			prev[done] = from;

			multiset<int> k = keys;
			for(int i=0; i<N; i++) if ( done & (1<<i) ) k.insert(ALL(chestkeys[i]));
			for(int i=0; i<N; i++) if ( done & (1<<i) ) k.erase(k.find(chesttype[i]));

			debug("keys available:");
			FOR(it,k) debug(" %d",*it); debug("\n");

			for(int i=0; i<N; i++) {
				if ( !(done & (1<<i)) && k.find(chesttype[i])!=k.end() ) {
					visit.push(make_pair(done | (1<<i), i));
				}
			}
		}

		cout << "Case #" << run << ":";
		if ( !reach[(1<<N)-1] ) {
			cout << " IMPOSSIBLE\n";
		} else {
			int curr = (1<<N)-1;
			VI order;
			while ( curr!=0 ) {
				int i = prev[curr];
				order.push_back(i);
				curr = curr - (1<<i);
			}
			for(int i=order.size()-1; i>=0; i--) cout << ' ' << order[i]+1;
			cout << endl;
		}

	}

	return 0;
}
