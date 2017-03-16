#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

char t[22];

map<string, int> P, Q;
vector<int> g[2002];
int v[2002];

int f(int x) {
	if (x == 2001) return 1;
	if (v[x]) return 0;
	int i;
	v[x] = 1;
	for (i = 0; i < g[x].size(); i++) if (f(g[x][i])) {
		g[g[x][i]].push_back(x);
		g[x][i] = g[x][g[x].size() - 1];
		g[x].pop_back();
		return 1;
	}
	return 0;
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc, tcn;
	scanf("%d", &tcn);
	for (tc = 1; tc <= tcn; tc++) {
		string r, s;
		int i, n;
		scanf("%d", &n);
		P.clear();
		Q.clear();
		for (i = 0; i < 2002; i++) {
			g[i].clear();
			v[i] = 0;
		}
		for (i = 0; i < n; i++) {
			scanf("%s", t);
			r = t;
			scanf("%s", t);
			s = t;
			if (P.find(r) == P.end()) {
				P[r] = P.size() + 1;
				g[0].push_back(P.size());
			}
			if (Q.find(s) == Q.end()) {
				Q[s] = Q.size() + 1;
				g[Q.size() + 1000].push_back(2001);
			}
			g[P[r]].push_back(Q[s] + 1000);
		}
		while (f(0)) {
			n++;
			for (i = 0; i < 2002; i++) v[i] = 0;
		}
		printf("Case #%d: %d\n", tc, n - P.size() - Q.size());
	}
}