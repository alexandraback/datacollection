#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define ms(a, x) memset(a, x, sizeof a)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> pt;

const int N = 1<<20;
const int inf = 1<<30;
const int lim = 1e6;

int d[N];
vector<int> e[N], q;

ll rev(ll x) {
	ll y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	for (int i = 1; i <= lim; i++) {
		e[i].pb(i+1);
		e[i].pb(rev(i));
	}

	q.pb(1);
	d[1] = 1;
	for (int i = 0; i < sz(q); i++) {
		int v = q[i];
		for (int j = 0; j < sz(e[v]); j++) {
			int u = e[v][j];
			if (!d[u]) {
				d[u] = d[v] + 1;
				q.pb(u);
			}
		}
	}

	int T;
	scanf("%d\n", &T);
	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		printf("Case #%d: %d\n", t, d[n]);
	}

	return 0;
}