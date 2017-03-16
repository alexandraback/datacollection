#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
//const ld PI = acosl(ld(-1));

const int N = 1000 * 1000 + 13;

li n;

inline bool read() {
	assert(cin >> n);
    return true;
}

int d[N];

li flip(li x) {
	li res = 0;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

li toInt(string s) {
	li res = 0;
	forn(i, sz(s)) {
		res = res * 10 + s[i] - '0';
	}
	return res;
}

li calc(li n) {

	if (n < 100)
		return d[n];

	if (n % 10 == 0) {
		return calc(n - 1) + 1;
	}
		
	string res = "";
	while (n) {
		res += char(n % 10 + '0');
		n /= 10;
	}
	reverse(all(res));

	bool ok = true;
	fore(i, 1, sz(res) - 2) {
		ok &= (res[i] == '0');
	}
	if (ok && res[0] == '1' && res[ sz(res) - 1 ] <= '1') {
		int add = res[ sz(res) - 1] - '0';

		return add + 1 + calc(toInt(res) - add - 1);
	}

	li cur = 0;
	reverse(all(res));
	ford(i, (sz(res) + 1) / 2) {
		cur = cur * 10 + res[i] - '0';
		res[i] = '0';
	}
	res[0] = '1';
	
	reverse(all(res));
	ok = true;
	fore(i, 1, sz(res) - 2) {
		ok &= (res[i] == '0');
	}
	if (ok && res[0] == '1' && res[ sz(res) - 1 ] <= '1') {
		int add = res[ sz(res) - 1] - '0';
		cur--;
		return cur + add + 1 + calc(toInt(res) - add - 1);
	}
	reverse(all(res));

	return cur + calc(toInt(res));
}

li naive() {
	return calc(n);	
}

inline void solve(int test) {
	li nans = naive();
	printf("Case #%d: ", test);
	cout << nans << endl;	
}

int q[N];
int head, tail;
int p[N];

void prepare() {
	memset(d, -1, sizeof d);
	d[0] = 0;
	head = tail = 0;
	q[tail++] = 0;
	while (tail != head) {
		int v = q[head++];
		int to = flip(v);
		if (to < N && d[to] == -1) {
			d[to] = d[v] + 1;
			q[tail++] = to;
			p[to] = v;
		}
		to = v + 1;
		if (to < N && d[to] == -1) {
			p[to] = v;
			d[to] = d[v] + 1;
			q[tail++] = to;
		}

	}
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif

    cout << setprecision(25) << fixed;
    cerr << setprecision(10) << fixed;

    srand(int(time(NULL)));
	prepare();

    int n;
    assert(scanf("%d", &n) == 1);
    forn(i, n) {
	    assert(read());
   		solve(i + 1);
    }
  

#ifdef SU2_PROJ
    cerr << "TIME: " << clock() << endl;
#endif

    return 0;
}