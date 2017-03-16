#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

struct SegmTree {
	const static int maxn = (1 << 21);
	int a[2 * maxn][2];
	int n;

	void build(int _n) {
		for (n = 1; n < _n; n <<= 1) ;
		assert(n <= maxn);
		for (int i = 1; i < 2 * n; i++)
			a[i][0] = 0, a[i][1] = 0;
	}

	void push(int v) {
		if (!a[v][1])
			return;
		a[2 * v][1] = max(a[2 * v][1], a[v][1]);
		a[2 * v][0] = max(a[2 * v][0], a[v][1]);
		a[2 * v + 1][1] = max(a[2 * v + 1][1], a[v][1]);
		a[2 * v + 1][0] = max(a[2 * v + 1][0], a[v][1]);
		a[v][1] = 0;
	}

	void update(int v, int l, int r, int l0, int r0, int val) {
		if (l0 >= r || l >= r0)
			return;
		if (l0 <= l && r <= r0) {
			a[v][0] = max(a[v][0], val);
			a[v][1] = max(a[v][1], val);
			return;
		}

		push(v);
		int m = (l + r) / 2;
		update(2 * v, l, m, l0, r0, val);
		update(2 * v + 1, m, r, l0, r0, val);
		
		a[v][0] = min(a[2 * v][0], a[2 * v + 1][0]);
	}

	void update(int l, int r, int val) {
		update(1, 0, n, l, r, val);
	}

	int get(int v, int l, int r, int l0, int r0) {
		if (l0 >= r || l >= r0)
			return INF;
		if (l0 <= l && r <= r0)
			return a[v][0];

		push(v);
		int m = (l + r) / 2;
		int res = min(get(2 * v, l, m, l0, r0), get(2 * v + 1, m, r, l0, r0));
		
		a[v][0] = min(a[2 * v][0], a[2 * v + 1][0]);
		return res;
	}

	int get(int l, int r) {
		return get(1, 0, n, l, r);
	}
} tree;


struct Segment {
	int d, l, r, s;

	Segment() {}
	Segment(int _d, int _l, int _r, int _s) : d(_d), l(_l), r(_r), s(_s) {
		//eprintf("%d %d %d %d\n", d, l, r, s);
	}

	inline bool operator < (const Segment &s) const {
		return d < s.d;
	}
};
const int maxn = (int)1e6;
Segment ss[maxn];
const int maxm = 2 * maxn;
int xs[maxm];

void solve(int &testCase) {
	int trN;
	scanf("%d", &trN);
	int n = 0;
	for (int i = 0; i < trN; i++) {
		int di, ni, wi, ei, si, delta_di, delta_pi, delta_s;	
		scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &delta_di, &delta_pi, &delta_s);
		for (int iter = 0; iter < ni; iter++) {
			ss[n++] = Segment(di, wi, ei, si);
			di += delta_di, wi += delta_pi, ei += delta_pi, si += delta_s;	
		}
	}
	assert(n <= maxn);
	int m = 0;
	for (int i = 0; i < n; i++)
		xs[m++] = ss[i].l, xs[m++] = ss[i].r;
	sort(xs, xs + m);
	m = unique(xs, xs + m) - xs;
	for (int i = 0; i < n; i++) {
		ss[i].l = lower_bound(xs, xs + m, ss[i].l) - xs;
		ss[i].r = lower_bound(xs, xs + m, ss[i].r) - xs;
		//eprintf("newl = %d, newr = %d\n", ss[i].l, ss[i].r);
	}
	sort(ss, ss + n);

	tree.build(m - 1);
	int ans = 0;
	for (int i = 0; i < n;) {
		int i0 = i;
		while (i < n && !(ss[i0] < ss[i])) {
			ans += (tree.get(ss[i].l, ss[i].r) < ss[i].s);
			//eprintf("i = %d, ans = %d\n", i, ans);
			i++;
		}

		for (int j = i0; j < i; j++)
			tree.update(ss[j].l, ss[j].r, ss[j].s);
	}

	printf("Case #%d: %d\n", ++testCase, ans);
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int testCase = 0;
	int maxt;
	while (scanf("%d", &maxt) >= 1) {
		for (int iter = 0; iter < maxt; iter++)
			solve(testCase);
		//break;
	}
	return 0;
}
