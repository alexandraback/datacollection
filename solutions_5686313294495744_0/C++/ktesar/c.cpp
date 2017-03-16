#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

struct Edge {
	int v[2];
	bool b;
};

int N;
map<string, int> lef; int lc = 0;
map<string, int> rig; int rc = 0;

vector<int> graf[2][11111];
int matched[2][11111]; int seen[2][11111];
vector<Edge> E;
int n[2], m;

bool match(int u, int par) {
	if (par && matched[par][u]==0) {
		matched[par][u] = 1;
		return true;
	}
	seen[par][u] = 1;
	REP(i, graf[par][u].size()) {
		Edge &e = E[graf[par][u][i]];
		if (e.b==par && seen[!par][e.v[!par]]==0) {
			if (match(e.v[!par], !par)) {
				e.b = !par;
				matched[par][u] = 1;
				return true;
			}
		}
	}
	return false;
}
void matching() {
	REP(i, n[0]) {
		REP(k, 2) REP(j, n[k]) seen[k][j] = 0;
			match(i, 0);
	}
}

void solve() {
	cin >> N;
	lef.clear(); lc = 0;
	rig.clear(); rc = 0;
	E.clear();
	REP(p, 2) REP(i, 2*N) {
		graf[p][i].clear();
		matched[p][i] = 0;
		seen[p][i] = 0;
	}
	REP(i, N) {
		string lw; string rw;
		cin >> lw >> rw;
		if (lef.find(lw) == lef.end()) {
			lef[lw] = lc++;
		}
		if (rig.find(rw) == rig.end()) {
			rig[rw] = rc++;
		}
		Edge e;
		e.v[0] = lef[lw];
		e.v[1] = rig[rw];
		e.b = false;
		E.push_back(e);
	}
	n[0] = lc;
	n[1] = rc;
	REP(i, E.size()) {
		graf[0][E[i].v[0]].push_back(i);
		graf[1][E[i].v[1]].push_back(i);
	}
	matching();
	int ans = 0;
	REP(i, E.size()) {
		ans += E[i].b;
	}
	REP(p, 2) REP(i, n[p]) ans += !matched[p][i];
	//cout << lc << " " << rc << endl;
	cout << (N-ans) << endl;
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
