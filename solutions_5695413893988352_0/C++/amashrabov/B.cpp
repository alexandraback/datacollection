#include <bits/stdc++.h>


#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vi64> vvi64;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

mt19937 generator;

const int N = 19;
i64 deg10[N];

struct solution {
	vi a, b; int test;
    void read() {
		string c, j;
		cin >> c >> j;
		reverse(all(c));
		reverse(all(j));
		for (char w: c)
			if (w == '?') a.pb(-1);
			else a.pb(w - '0');
		
		for (char w: j)
			if (w == '?') b.pb(-1);
			else b.pb(w - '0');
    }
    void pr(i64 val, int len) {
		vi x;
		forn (i, len) {
			x.pb(val % 10);
			val /= 10;
		}
		reverse(all(x)); for (int y: x) cout << y;
	}
	
    void print() {
		cout << "Case #" << test << ": ";
		pr(ba, la);
		cout << " ";
		pr(bb, lb);
		cout << "\n";
    }

	i64 mnDiff;
	i64 ba, bb;
	
	int n;
	int la, lb;
	i64 va, vb;
	
	void gen(int x) {
		if (x == -1)
		{
			i64 diff = va - vb; if (diff < 0) diff *= -1;
			if (mp(diff, mp(va, vb)) < mp(mnDiff, mp(ba, bb))) {
				mnDiff = diff;
				ba = va;
				bb = vb;
				//cerr << va << " " << vb << endl;
			}
			
			return;
		}
		i64 oa = va, ob = vb;
		if (a[x] == -1 && b[x] == -1) {
			if (oa < ob) {
				va = oa + 9 * deg10[x];
				vb = ob + 0 * deg10[x];
				gen(x - 1);
			}		
			if (oa == ob) {
				va = oa + 0 * deg10[x];
				vb = ob + 0 * deg10[x];
				gen(x - 1);
				va = oa + 1 * deg10[x];
				vb = ob + 0 * deg10[x];
				gen(x - 1);
				va = oa + 0 * deg10[x];
				vb = ob + 1 * deg10[x];
				gen(x - 1);
			}
			if (oa > ob) {
				va = oa + 0 * deg10[x];
				vb = ob + 9 * deg10[x];
				gen(x - 1);
			}
			
			return;
		}
		if (a[x] == -1) {
			if (oa < ob) {
				va = oa + 9 * deg10[x];
				vb = ob + b[x] * deg10[x];
				gen(x - 1);
			}
			if (oa == ob) {
				va = oa + b[x] * deg10[x];
				vb = ob + b[x] * deg10[x];
				gen(x - 1);
				va = oa + ((b[x] - 1 + 10)%10) * deg10[x];
				vb = ob + b[x] * deg10[x];
				gen(x - 1);
				va = oa + ((b[x]+1)%10) * deg10[x];
				vb = ob + b[x] * deg10[x];
				gen(x - 1);
			}
			if (oa > ob) {
				va = oa + 0 * deg10[x];
				vb = ob + b[x] * deg10[x];
				gen(x - 1);
			}
			return;
		}
		if (b[x] == -1) {
			if (oa < ob) {
				va = oa + a[x] * deg10[x];
				vb = ob + 0 * deg10[x];
				gen(x - 1);
			}
			if (oa == ob) {
				va = oa + a[x] * deg10[x];
				vb = ob + a[x] * deg10[x];
				gen(x - 1);
				va = oa + a[x] * deg10[x];
				vb = ob + ((a[x] - 1 + 10)%10) * deg10[x];
				gen(x - 1);
				va = oa + a[x] * deg10[x];
				vb = ob + ((a[x]+1)%10) * deg10[x];
				gen(x - 1);
			}
			if (oa > ob) {
				va = oa + a[x] * deg10[x];
				vb = ob + 9 * deg10[x];
				gen(x - 1);
			}
			return;
		}
		va = oa + deg10[x] * a[x];
		vb = ob + deg10[x] * b[x];
		gen(x - 1);
	}
    void solve() {
		mnDiff = 8e18;
		n = max(a.size(), b.size());
		la = a.size(); lb = b.size();
		while ((int)a.size() < n) a.pb(0);
		while ((int)b.size() < n) b.pb(0);
		va = vb = 0;
		gen(n-1);
    }
} * solutions;


void solve(int test) {
    solutions[test].solve();
}




int main() {
#ifdef HOME
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	deg10[0] = 1; for1 (i, N - 1) deg10[i] = deg10[i - 1] * 10;
	int tests; cin >> tests;

    solutions = new solution[tests];

    for (int i = 0; i < tests; ++i) {
        solutions[i].test = i + 1;
        solutions[i].read();
    }

    thread threads[tests];

    for (int i = 0; i < tests; ++i) {
        threads[i] = thread(solve, i);
    }

    for (int i = 0; i < tests; ++i) {
        threads[i].join();
        solutions[i].print();
    }


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
} 
