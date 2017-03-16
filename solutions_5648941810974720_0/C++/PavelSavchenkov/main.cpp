#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"


const int MAXN = 1e5 + 10;
const int A = 26;

int cnt[A];
char s[MAXN];

bool read() {
	memset (cnt, 0, sizeof cnt);
	gets(s);
	for (int i = 0; s[i]; ++i) {
		++cnt[s[i] - 'A'];
	}
	return true;
}

int erase(const string& s, char c) {
	int it = cnt[c - 'A'];
	for (char cc : s) {
		assert(cnt[cc - 'A'] >= it);
		cnt[cc - 'A'] -= it;
	}
	return it;
}

void solve() {
	vi ans(10, 0);
	ans[0] = erase("ZERO", 'Z');
	ans[2] = erase("TWO", 'W');
	ans[4] = erase("FOUR", 'U');
	ans[6] = erase("SIX", 'X');
	ans[8] = erase("EIGHT", 'G');
	ans[5] = erase("FIVE", 'F');
	ans[7] = erase("SEVEN", 'V');
	ans[1] = erase("ONE", 'O');
	ans[9] = erase("NINE", 'I');
	ans[3] = erase("THREE", 'H');
	forn(c, 10) forn(it, ans[c]) {
		printf("%d", c);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int T;
	scanf("%d\n", &T);
	forn(tt, T) {
		assert(read());
		printf("Case #%d: ", tt + 1);
		solve();
	}

	return 0;
}
