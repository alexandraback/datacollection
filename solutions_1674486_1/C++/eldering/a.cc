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

#define DEBUGGING 1

#if defined(DEBUGGING)
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

int n, diamond;
VVI adj;
VI visited;

void dfs(int i)
{
	if ( visited[i] ) {
		diamond = 1;
		return;
	}
	visited[i] = 1;
	REP(j,adj[i].size()) dfs(adj[i][j]);
}

int main()
{
	int run, nruns;

	cin >> nruns;

	for(run=1; run<=nruns; run++) {

		cin >> n;
		adj = VVI(n,VI());

		REP(i,n) {
			int m;
			cin >> m;
			adj[i] = VI(m);
			REP(j,m) { cin >> adj[i][j]; adj[i][j]--; }
		}

		diamond = 0;
		REP(i,n) {
			visited = VI(n,0);
			dfs(i);
			if ( diamond ) break;
		}

		cout << "Case #" << run << ": ";
		if ( diamond ) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
