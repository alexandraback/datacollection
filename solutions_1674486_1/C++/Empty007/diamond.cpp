#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define pb push_back
#define mp make_pair

#define ALL(x) (x).begin(),(x).end()
#define CLR(a,b) memset(a,b,sizeof(a))
#define REPN(x,a,b) for (int x=a; x<b;++x)
#define REP(x,b) REPN(x, 0, b)

#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "  " << #y << " = " << y << endl;
#define dbg3(x, y, z) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << endl;
#define dbg4(x, y, z, w) cout << #x << " = " << x << "  " << #y << " = " << y << "  " << #z << " = " << z << "  " << #w << " = " << w <<  endl;

#define MAX 1005

vector < int > G[MAX];
vector < int > order;
int vis[MAX], vis2[MAX];
bool ac;

void dfs(int u) {
	vis[u] = 1;
	REP(i, G[u].size()) {
		int v = G[u][i];
		if (!vis[v]) dfs(v);
	}
	order.pb(u);
}

void check(int u) {
	vis2[u] = 1;
	vis[u] = 1;
	REP(i, G[u].size()) {
		int v = G[u][i];
		if (vis2[v]) {
			ac = 1;
			break;
		}
		else check(v);
	}
}

int main() {
	int T, N, M, v;
	cin >> T;
	REP(tc, T) {
		cin >> N;
		REP(u, N) G[u].clear();
		order.clear();
		REP(u, N) {
			cin >> M;
			REP(i, M) {
				cin >> v;
				v--;
				G[u].pb(v);
			}
		}

		CLR(vis, 0);
		REP(u, N) if (!vis[u]) {
			dfs(u);
		}
		reverse(ALL(order));
		
		CLR(vis, 0);
		ac = 0;
		REP(u, N) if (!vis[order[u]] && !ac) {
			CLR(vis2, 0);
			check(order[u]);
		}
		
		if (ac) printf("Case #%d: Yes\n", tc+1);
		else printf("Case #%d: No\n", tc+1);
		
	}	
}
