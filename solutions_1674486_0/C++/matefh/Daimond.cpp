#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define FOR(i,n) for(int i = 0 ; i < n ; i++)
#define FORL(i,i0,n) for(int i = i0 ; i < n ; i++)
#define FORIT(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(), x.end()
#define SZ(x) int(x.size())
#define LEN(x) int(x.length())
#define PB push_back
#define MP make_pair
#define FST(x) (x).first
#define SEC(x) (x).second
#define LL long long
#define mem(x, n) memset(x, n, sizeof(x))
#define ni() ({int t;scanf("%d",&t);t;})
#define SRAND() srand(time(NULL))
#define RAND(from, to) ((rand() % (to-from+1)) + (from))
#if 1
#define DBG(z) cerr << #z << ": " << (z) << endl
#else
#define DBG(z)
#endif
#define LOCAL 0
using namespace std;

bool FOUND;
vector<int> adj[1111];
bool seen[1111];

void DFS(int u) {
	if (FOUND)
		return;
	if (seen[u]) {
		FOUND = true;
		return;
	}
	seen[u] = true;
	FOR(i, SZ(adj[u])) {
		int v = adj[u][i];
		DFS(v);
		if (FOUND)
			return;
	}
}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	int t = ni();
	FORL(kase, 1, t + 1) {
		int N = ni();
		FOR(i, N) {
			int e = ni();
			adj[i].clear();
			FOR(j, e) {
				int x = ni();
				adj[i].PB(x-1);
			}
		}
		FOUND = false;
		FOR(i, N) {
			if (!FOUND) {
				mem(seen, 0);
				DFS(i);
			}
		}
		if (FOUND) {
			printf("Case #%d: Yes\n", kase);
		} else {
			printf("Case #%d: No\n", kase);
		}
	}
	return 0;
}

