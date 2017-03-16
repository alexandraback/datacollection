#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef unsigned long ulong;
typedef unsigned long long ull;

vector<vector<int> > g;
vector<int> was;

bool dfs(int u, int col, int p = -1) {
	//printf("enter %d\n", u);
	was[u] = col;
	REP(i,g[u].size()) {
		int v = g[u][i];
		if (v != p)
			if (was[v] == col)
				return true;
			else if (dfs(v, col))
				return true;
	}
	//printf("leave %d\n", u);
	return false;
}

int main() {
	//freopen("problem.in", "r", stdin);
	//freopen("problem.out", "w", stdout);
	int tnum;
	g.resize(1234);
	was.resize(1234);
	cin >> tnum;
	FOR(ti,1,tnum) {
		bool res = false;
		int N;
		cin >> N;
		was.assign(1234, 0);
		REP(i,N) {
			int M;
			cin >> M;
			g[i].resize(M);
			REP(j,M) {
				cin >> g[i][j];
				--g[i][j];
			}
		}
		REP(u,N) {
			if (dfs(u, u+1)) {
				res = true;
				break;
			}
			//puts("");
		}
		printf("Case #%d: ", ti);
		if (res)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}