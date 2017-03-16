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

#define N 4000000
int T, l;
ll x;
char s[N + 1];

const int I = 2, J = 3, K = 4;

inline int mul(int a, int b) {
	static map<int, map<int, int> > h =
		{{1, {{1, 1}, {I, I}, {J, J}, {K, K}}},
		 {I, {{1, I}, {I, -1}, {J, K}, {K, -J}}},
		 {J, {{1, J}, {I, -K}, {J, -1}, {K, I}}},
		 {K, {{1, K}, {I, J}, {J, -I}, {K, -1}}}};
	int sign = 1;
	if (a < 0) a = -a, sign = -sign;
	if (b < 0) b = -b, sign = -sign;
	return h[a][b] * sign;
}

inline int conv(char ch) {
	static map<char, int> h = 
		{{'1', 1}, {'i', I}, {'j', J}, {'k', K}};
	return h[ch];
}

inline int pw(int a, ll b) {
	int r = 1;
	while (b > 0LL) {
		if (b & 1LL) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

bool check(char *s, int l, ll x) {
	int m = min(x, 32LL);
	for (int k = 1; k < m; ++k)
		for (int i = 0; i < l; ++i)
			s[k * l + i] = s[i];
	
	bool ok = false;
	int cur = 1, p = 0;
	for (; !ok && p < m * l; ++p) {
		cur = mul(cur, conv(s[p]));
		if (cur == I) ok = true;
	}
	if (!ok) return false;
	for (ok = false, cur = 1; !ok && p < m * l; ++p) {
		cur = mul(cur, conv(s[p]));
		if (cur == J) ok = true;
	}
	if (!ok) return false;
	for (ok = false, cur = 1; !ok && p < m * l; ++p) {
		cur = mul(cur, conv(s[p]));
		if (cur == K) ok = true;
	}
	if (!ok) return false;
	cur = 1;
	for (; p < m * l; ++p)
		cur = mul(cur, conv(s[p]));
	int all = 1;
	for (int i = 0; i < l; ++i)
		all = mul(all, conv(s[i]));
	return mul(cur, pw(all, x - m)) == 1;
}

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int Case = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &l, &x);
		scanf("%s", s);
		bool ans = check(s, l, x);
		printf("Case #%d: %s\n", ++Case, ans ? "YES" : "NO");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
