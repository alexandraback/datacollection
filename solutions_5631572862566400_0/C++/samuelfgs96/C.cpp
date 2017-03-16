#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ForC(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n-1); i >= 0; i--)

using namespace std;
const double PI = acos(-1.0);

typedef long long ll;
typedef pair<int, int> pii;

int counter, last, ant_last;
vector <int> aux[1010];
int gr[1010];
int parent[1010];
bool vis[1010];
bool parte_exttra[1010];

void dfs (int u) {
	counter++;
	ant_last = last;
	last = u;
	vis[u] = true;
//	printf("u: %d\n", u);
	if (!vis[gr[u]]) {
		parent[gr[u]] = u;
		dfs (gr[u]);
	}
}

int solve (int k) {
	int r = 1;
	if (vis[k]) return 0;
	for (int i = 0; i < aux[k].size(); i++) {
		r = max (r, solve (aux[k][i]) + 1);
	}
	return r;
}

int main (void) {
	int t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++) {
		int n; 
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			gr[i+1] = x;
			aux[x].pb(i+1);
		}
		int r = 0;
		int extra = 0;
		memset (vis, false, sizeof vis);

		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue ;
			parent[i] = -1;
			dfs (i);
			ant_last = parent[last];
			if (ant_last == -1) continue;
			if (parent[ant_last] == -1) extra += 2;
		}

		for (int i = 1; i <= n; i++) {
			memset (vis, false, sizeof vis);
			memset (parent, 0, sizeof parent);
			counter = last = 0;
			parent[i] = -1;
			dfs (i);
			bool flag = false;
			while (true) { 
				ant_last = parent[last];
				if (last == -1 or ant_last == -1) break;
				if (gr[last] == ant_last) {
					int t = 0;
					for (int j = 0; j < aux[i].size(); j++) {
						t = max (t, solve (aux[i][j]));
					}
					for (int j = 0; j < aux[last].size(); j++) {
						t = max (t, solve (aux[last][j]));
					}
					if (parent[ant_last] == -1) {
						counter += (extra - 2);
					} else counter += max (t, extra);
					break;
				}
				if (gr[last] == i) break;
				counter--;
				last = parent[last];
			}
			if (counter > r) r = counter;
		}
		for (int i = 0; i <= n; i++) aux[i].clear();
		printf("Case #%d: %d\n", cases, r);
	}
	return 0;
}
