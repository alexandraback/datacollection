#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#define double long double
#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define FORE(i, a, n) for (i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define all(n) (n).begin(), (n).end()
#define ll long long
#define pb push_back
#define error(x) cout << #x << " = " << (x) << endl;
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define point complex<double>
//#define X real()
//#define Y imag()
#define X first
#define Y second
#define EPS 1e-12
//#define endl "\n"
#define pdd pair<double, double>
bool gt(double a, double b) { return a > b+EPS; }

const int MAXN = 1024;

int n, deg[MAXN], Q[MAXN], head, tail, dp[MAXN];
vector<int> adj[MAXN];

int main() {
	int t;
	cin >> t;
	FOR(l, 1, t+1) {
		cin >> n;
		fill(adj, adj+MAXN, vector<int> ());
		FOR(i, 0, n) {
			int d;
			cin >> d;
			FOR(j, 0, d) {
				int x;
				cin >> x;
				x--;
				adj[i].pb(x);
				deg[x]++;
			}
		}
		head = tail = 0;
		FOR(i, 0, n) if (deg[i] == 0) Q[tail++] = i;
		while (head < tail) {
			int cur = Q[head++];
			FOREACH(it, adj[cur]) {
				deg[*it]--;
				if (deg[*it] == 0) Q[tail++] = *it;
			}
		}
		bool ok = false;
		FOR(i, 0, n) {
			fill(dp, dp+MAXN, 0);
			dp[i] = 1;
			for (int j = n-1; j >= 0 && !ok; j--) {
				int cur = Q[j];
				FOREACH(it, adj[cur]) dp[cur] += dp[*it];
				if (dp[cur] > 1) ok = true;
			}
			if (ok) break;
		}
		cout << "Case #" << l << ": " << (ok?"Yes":"No") << endl;
	}
	return 0;
}

