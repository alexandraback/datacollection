#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <utility>
#include <functional>
#include <bitset>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int, int> PII;


#define FOR(i, x, y) for(ll i=x; i<=y; i++)
#define FORD(i, x, y) for (ll i = x; i >= y; --i)
#define REP(i, n) for(ll i=0; i<n; i++)
#define REPD(i, n) for(ll i = n - 1; i >= 0; --i) 

#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define UNIQ(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define SZ(c) (int)(c).size()

#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)

#define pb push_back
#define mp make_pair
#define X first
#define Y second



const double eps = 1.0e-11;
const double pi = acos(-1.0);

const int N = 700000;
const int SHIFT = 220;

struct attack {
	int w, e, s;
	attack() {}
	attack(int _w, int _e, int _s) : w(_w), e(_e), s(_s) {}
};

typedef vector<attack> day;


day timeline[N];

int wall[2 * SHIFT];
int cwall[2 * SHIFT];

int getw(int idx) {
	return wall[idx + SHIFT];
}

int getc(int idx) {
	return cwall[idx + SHIFT];
}

void setc(int idx, int val) {
	cwall[idx + SHIFT] = val;
}



void solve() {
	// clear data structure
	REP(i, N)
		timeline[i].clear();
	REP(i, 2 * SHIFT)
		wall[i] = 0;

	int n;
	cin >> n;

	REP(i, n) {
		int di, ni, wi, ei, si;
		cin >> di >> ni >> wi >> ei >> si;

		int delta_di, delta_pi, delta_si;
		cin >> delta_di >> delta_pi >> delta_si;

		REP(dd, ni) {
			timeline[di].push_back(attack(wi, ei, si));

			wi += delta_pi;
			ei += delta_pi;

			si += delta_si;
			di += delta_di;
		}
	}

	int res = 0;

	REP(i, N) {
		REP(j, 2 * SHIFT)
			cwall[j] = wall[j];

		REP(j, timeline[i].size()) {
			int w = timeline[i][j].w;
			int e = timeline[i][j].e;
			int s = timeline[i][j].s;

			bool ok = true;
			FOR(x, w, e - 1) {
				if (getw(x) < s) {
					ok = false;
					if (getc(x) < s)
						setc(x, s);
				}
			}

			res += !ok;
		}

		REP(j, 2 * SHIFT)
			wall[j] = cwall[j];
	}

	cout << res << endl;
}


int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("outputC", "w", stdout);

	int T;
	cin >> T;
	REP(test, T) {
		printf("Case #%lld: ", test + 1);
		solve();
	}
	return 0;
}