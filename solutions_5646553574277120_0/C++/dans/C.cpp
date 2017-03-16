#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

int c, d, v, a[1000];

bool read() {
	if (scanf("%d %d %d", &c, &d, &v) != 3)
		return false;
	forn(i, d)
		scanf("%d", &a[i]);
	return true;
}

map <int, int> dist;

int move(int mask, int d) {
	return (mask | (mask << d)) & ((1 << (v + 1)) - 1);
}


void solve() {
	dist.clear();
	int s = 1;
	forn(i, d)
		s = move(s, a[i]);
	int targ = (1 << (v + 1)) - 1;
	queue <int> q;
	dist[s] = 0;
	q.push(s);

	while (!q.empty()) {
		int c = q.front(); q.pop();

		if (c == targ) {
			printf("%d\n", dist[c]);
			return;
		}

		for (int i = 1; i <= v; ++i) {
			int nc = move(c, i);
			if (dist.count(nc) == 0) {
				dist[nc] = dist[c] + 1;
				q.push(nc);
			}
		}
	}

	cerr << s << " " << v << endl;
	assert(false);
}

int main() {
//#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif

#ifdef TASK_NAME
	freopen(TASK_NAME ".in", "r", stdin);
	freopen(TASK_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);

	forn(t, T) {
		cerr << t << endl;
		assert(read());
		printf("Case #%d: ", t + 1);
		solve();
	}
	
	return 0;
}
