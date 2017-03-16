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

vector<string> order;
const vector<string> names = {"ZERO", "SIX", "TWO", "EIGHT", "SEVEN", "THREE", "FOUR", "ONE", "FIVE", "NINE"};
const vector<string> help = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
const string keys = "ZXWGSTROFI";
struct solution {
    int test;
    vi q;
	vi ans;
	
    void read() {
		string s;
		cin >> s;
		q.assign(26, 0);
		for (char c: s) q[c - 'A']++;
    }
    void print() {
		assert(accumulate(all(q), 0) == 0);
		cout << "Case #" << test << ": ";
		sort(all(ans));
		for (int x: ans) cout << x;
		cout << "\n";
    }

    void solve() {
		forn (i, names.size()) {
			int t = keys[i] - 'A';
			int req = q[t];
			int num = find(all(help), names[i]) - help.begin();
			forn(i,req)ans.pb(num);
			for (char c: names[i])
			{
				q[c - 'A'] -= req;
			}
		}
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
