#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int ntest = 0, test = 0;
inline void init();
inline void run();
inline void stop() {
	ntest = test - 1;
}

int main() {
#ifdef LOCAL
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
#endif
	init();
	while (++test <= ntest) {
		run();
	}
	return 0;
}

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, a) for (int i = 0; i < (a); i++)
#define FIT(it, v) for (typeof((v).begin())it = (v).begin(); it != (v).end(); it++)

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SORT(v) sort(ALL(v))
#define GSORT(v) sort(ALL(v), greater<typeof(*(v).begin())>())
#define UNIQUE(v) SORT(v); (v).resize(unique(ALL(v)) - (v).begin())

#define PB push_back
#define MP make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = (int) 1E9 + 5;
const double EPS = 1E-11;
const ll MOD = (ll) 1E9 + 7;

const int dx[] = { -1, 0, 0, 1 };
const int dy[] = { 0, -1, 1, 0 };

const int MAXN = 35;

int n;
string a, b;
map <char, char> trans, rev;

inline void init() {
	ntest = 1;

	trans[' '] = ' ';
	trans['a'] = 'y';
	trans['b'] = 'h';
	trans['c'] = 'e';
	trans['d'] = 's';
	trans['e'] = 'o';
	trans['f'] = 'c';
	trans['g'] = 'v';
	trans['h'] = 'x';
	trans['i'] = 'd';
	trans['j'] = 'u';
	trans['k'] = 'i';
	trans['l'] = 'g';
	trans['m'] = 'l';
	trans['n'] = 'b';
	trans['o'] = 'k';
	trans['p'] = 'r';
	trans['q'] = 'z';
	trans['r'] = 't';
	trans['s'] = 'n';
	trans['t'] = 'w';
	trans['u'] = 'j';
	trans['v'] = 'p';
	trans['w'] = 'f';
	trans['x'] = 'm';
	trans['y'] = 'a';
	trans['z'] = 'q';
}

inline void run() {
	scanf("%d\n", &n);
	REP(i, n) {
		getline(cin, a);
		FIT(it, a) {
			*it = trans[*it];
		}
		cout << "Case #" << i + 1 << ": ";
		cout << a << endl;
	}
}
