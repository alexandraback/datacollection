#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxN 1000

int f[maxN], v[maxN], ec, cyc[maxN];
vi rev[maxN];
bool cur[maxN];

int findCyc(int n, int d) {
	if (cur[n]) {
		ec = n;
		return d - v[n];
	}
	v[n] = d;
	cur[n] = true;
	int ret = findCyc(f[n], d + 1);
	if (~ec) cyc[n] = ret;
	else cyc[n] = 0;
	if (ec == n) ec = -1;
	cur[n] = false;
	return ret;
}

int getV(int n, int p) {
	int ret = 0;
	FOR(i, 0, rev[n].size()) {
		if (rev[n][i] == p) continue;
		ret = max(ret, getV(rev[n][i], p));
	}
	return ret + 1;
}

int main() {
	int T, caso=1, N;
	cin >> T;
	while (T--) {
		cin >> N;
		memset(v, -1, sizeof(v));
		memset(cyc, -1, sizeof(cyc));
		memset(cur, false, sizeof(cur));
		memset(f, -1, sizeof(f));
		FOR(i, 0, maxN) rev[i].clear();
		ec = -1;
		FOR(i, 0, N) {
			cin >> f[i];
			f[i]--;
			rev[f[i]].push_back(i);
		}
		int ans = 0;
		FOR(i, 0, N) {
			if (!~v[i]) ans = max(ans, findCyc(i, 0));
		}
		int ta = 0;
		FOR(i, 0, N) {
			if (cyc[i] == 2) {
				ta += getV(i, f[i]) + getV(f[i], i);
				cyc[f[i]] = 0;
				ans = max(ans, ta);
			}
		}
		cout << "Case #" << caso++ << ": " << ans;
		cout << endl;
	}
	return 0;
}