#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define int long long
#define double long double

#define ff first
#define ss second
#define mp make_pair
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

const int maxN = 1000 + 10;
const int maxA = 2000 * 1000 + 100;
const int maxS = 4 * maxA;

int All[maxA];
int N, d[maxN], n[maxN], w[maxN], e[maxN], s[maxN], dd[maxN], dp[maxN], ds[maxN];
map <int, int> m;

int seg[maxS], flag[maxS], S;

struct attack {
	int s, l, r, d;
	attack(){}
	attack(int S, int L, int R, int D) { s = S, l = L, r = R, d = D; }
};
vector <attack> a;

bool operator < (attack a, attack b) {
	if (a.d != b.d) return a.d < b.d;
	if (a.s != b.s) return a.s < b.s;
	if (a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}

void shift (int x) {
	if (seg[x] != min (seg[2 * x], seg[2 * x + 1])) 
		seg[2 * x] = max (seg[x], seg[2 * x]),
		seg[2 * x + 1] = max (seg[x], seg[2 * x + 1]);
}

int find (int lo, int hi, int x, int l, int r) {
	if (lo == l && hi == r) return seg[x];
	shift (x);
	int m = (lo + hi) / 2;
	int ans = -1, anz = -1;
	if (l < m) ans = find (lo, m, 2 * x, l, min (r, m));
	if (r > m) anz = find (m, hi, 2 * x + 1, max (l, m), r);
	if (anz != -1) if (ans == -1 || ans > anz) ans = anz;
	return ans;
}

bool check (int x) {
	int l = m[a[x].l], r = m[a[x].r];
	int ans = find (0, S, 1, l, r);
	return ans < a[x].s;
}

void modify (int lo, int hi, int x, int l, int r, int val) {
	if (lo == l && hi == r) { seg[x] = max (val, seg[x]); return; }
	shift (x);
	int m = (lo + hi) / 2;
	if (l < m) modify (lo, m, 2 * x, l, min (r, m), val);
	if (r > m) modify (m, hi, 2 * x + 1, max (l, m), r, val);
	seg[x] = min (seg[2 * x], seg[2 * x + 1]);
}

void update (int x) {
	int l = m[a[x].l], r = m[a[x].r], v = a[x].s;
	modify (0, S, 1, l, r, v);
}

int solve() {
	memset (All, 0, sizeof All);
	memset (seg, 0, sizeof seg);
	memset (flag, -1, sizeof flag);
	a.clear();

	cin >> N;
	vector <int> pos;
	for (int i = 0; i < N; i++) {
		cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
		for (int j = 0, S = s[i], l = w[i], r = e[i], day = d[i]; j < n[i]; j++) {
			a.push_back (attack (S, l, r, day));
			pos.push_back (l);
			pos.push_back (r);
			S += ds[i], l += dp[i], r += dp[i], day += dd[i];
		}
	}
	sort (pos.begin(), pos.end());
	pos.resize (unique (pos.begin(), pos.end()) - pos.begin());
	for (int i = 0; i < pos.size(); i++) m[pos[i]] = i;
	S = pos.size() + 1;

	int res = 0;
	sort (a.begin(), a.end());
	for (int i = 0; i < a.size(); ) {
		int k = i; while (k < a.size() && a[k].d == a[i].d) k++;
		for (int l = i; l < k; l++) {
			bool valid = 0;
			valid = check (l);
			//for (int j = m[a[l].l]; j < m[a[l].r]; j++)
			//	if (All[j] < a[l].s) valid = 1;
			res += valid;
		}
		for (int l = i; l < k; l++)
			update (l);
			//for (int j = m[a[l].l]; j < m[a[l].r]; j++)
			//	if (All[j] < a[l].s) All[j] = a[l].s;
		i = k;
	}
	return res;
}

main() {
	ios::sync_with_stdio (false);
	
	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		int ans = solve();
		cout << "Case #" << o << ": " << ans << endl;
	}

	return 0;
}
