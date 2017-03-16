#pragma comment(linker, "/STACK:66777216")
#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>
#include <assert.h>
#include <memory.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(a) (int)a.size()
#define fill(a, x) memset (a, x, sizeof(a))

#ifdef _DEBUG
	#define Eo(x) {cout << "# " << #x << " = " << (x) << endl;}
	#define E(x) {cout << "# " << #x << " = " << (x) << " ";}
	#define Ou(x) {cout << "# " << (x) << endl;}
#else
	#define Eo(x)
	#define E(x)
	#define Ou(x)
#endif

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void sIO();
void iIO();
void fIO(string fn);
void TM();

int __;

typedef pair<pii, pair<ll, ll> > item;

ll n, m, ans, a[111][2], b[111][2], kk, cc, qq, w[111];
map<item, ll> res;
vector<int> d[5];

ll go(int x, int y) {
	if (a[x][0] == 0) ++x;
	if (b[y][0] == 0) ++y;
	if (x >= n || y >= m) return 0;
	ll mx, kk;
	mx = max(mx, go(x + 1, y));
	for (int i = y; i < m; ++i)
		if (a[x][1] == b[i][1]) {
			kk = min(a[x][0], b[i][0]);
			a[x][0] -= kk;
			b[i][0] -= kk;
			mx = max(mx, kk + go(x, i + 1));
			mx = max(mx, kk + go(x + 1, i));
			a[x][0] += kk;
			b[i][0] += kk;
			break;
		}
	return mx;
}

int main() {
	sIO();
	scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		scanf("%d %d", &n, &m);
		ans = 0;
		res.clear();
		fill(w, 0);
		qq = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%I64d %I64d", &a[i][0], &a[i][1]);
			w[a[i][1]] = true;
		}
		cc = 0;
		for (int i = 1; i < n; ++i)
			if (a[i][1] == a[cc][1]) a[cc][0] += a[i][0]; else {
				a[++cc][0] = a[i][0];
				a[cc][1] = a[i][1];
			}
		n = cc + 1;
		cc = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%I64d %I64d", &b[cc][0], &b[cc][1]);
			cc += w[b[cc][1]];
		}
		m = cc;
		cc = 0;
		for (int i = 1; i < m; ++i)
			if (b[i][1] == b[cc][1]) b[cc][0] += b[i][0]; else {
				b[++cc][0] = b[i][0];
				b[cc][1] = b[i][1];
			}
		m = cc + 1;
		for (int i = 0; i < m; ++i)
			d[w[b[i][1]]].pb(i);
		printf("%I64d\n", go(0, 0));
	}
    return 0;
}

inline void sIO() {
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
}

inline void iIO() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
}

inline void fIO(string fn) {
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	freopen ((fn + ".in").c_str(), "r", stdin);
	freopen ((fn + ".out").c_str(), "w", stdout);
#endif
}

inline void TM() {
#ifdef _DEBUG
	cout << endl << "# Time: " << clock() / 1000. << endl;
#endif
}