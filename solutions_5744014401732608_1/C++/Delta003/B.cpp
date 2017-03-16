#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

#define eps 0.0000001
#define pi  3.14159265359
#define inf 2000000000

typedef long long lld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int maxn = 50 + 5;

vector<int> adj[maxn];
lld cnt[maxn];
int path[maxn][maxn];

bool build_line(int n, lld limit) {
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		cnt[i] = 0;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			path[i][j] = 0;
	cnt[0] = 1;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 0; j < i; j++) {
			adj[j].push_back(i);
			cnt[i] += cnt[j];
		}
	}
	for (int i = n - 2; i >= 0; i--)
		if (cnt[i] <= limit) {
			limit -= cnt[i];
			adj[i].push_back(n - 1);
		}
	if (limit > 0) return false;
	return true;
}

int main() {
	int tt, b;
	lld m;
	scanf("%d", &tt);
	for (int t = 1; t <= tt; t++) {
		scanf("%d %lld", &b, &m);
		bool ok = build_line(b, m);
		if (!ok) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << t << ": POSSIBLE" << endl;
			for (int i = 0; i < b; i++)
				for (int j = 0; j < adj[i].size(); j++)
					path[i][adj[i][j]] = 1;
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++) cout << path[i][j];
				cout << endl;
			}
		}
	}    
    return 0;
}
