//Template
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <ios>
#include <iomanip>
#include <ctime>
#include <numeric>
#include <functional>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
#include <cstdarg>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
#define pair(x, y) make_pair(x, y)
#define runtime() ((double)clock() / CLOCKS_PER_SEC)

inline int read() {
	static int r, sign;
	static char c;
	r = 0, sign = 1;
	do c = getchar(); while (c != '-' && (c < '0' || c > '9'));
	if (c == '-') sign = -1, c = getchar();
	while (c >= '0' && c <= '9') r = r * 10 + (int)(c - '0'), c = getchar();
	return sign * r;
}

template <typename T>
inline void print(T *a, int n) {
	for (int i = 1; i < n; ++i) cout << a[i] << " ";
	cout << a[n] << endl;
}
#define PRINT(_l, _r, _s, _t) { cout << #_l #_s "~" #_t #_r ": "; for (int _i = _s; _i != _t; ++_i) cout << _l _i _r << " "; cout << endl; }

int T, n, Case = 0;
ll ans;
bool v[10];

inline bool ok() {
	for (int i = 0; i < 10; ++i)
		if (!v[i]) return false;
	return true;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 0) ans = -1LL;
		else {
			memset(v, 0, sizeof v);
			for (ans = n; !ok(); ans += n) {
				for (ll x = ans; x > 0; x /= 10)
					v[x % 10] = true;
			}
			ans -= n;
		}
		cout << "Case #" << ++Case << ": ";
		if (ans == -1) cout << "INSOMNIA" << endl;
		else cout << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
