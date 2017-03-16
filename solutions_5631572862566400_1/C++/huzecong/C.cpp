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

#define N 1100
struct edge {
	int next, node;
} e[N + 1];
int head[N + 1], tot;

inline void addedge(int a, int b) {
	e[++tot].next = head[a];
	head[a] = tot, e[tot].node = b;
}

int T, n, fa[N + 1], f[N + 1], d[N + 1], Case = 0;

int dfs(int x) {
	int ret = 0;
	for (int i = head[x]; i; i = e[i].next) {
		int node = e[i].node;
		ret = max(ret, dfs(node) + 1);
	}
	return ret;
}

bool v[N + 1];

int main(int argc, char *argv[]) {
#ifdef KANARI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	scanf("%d", &T);
	while (T--) {
		memset(head, 0, sizeof head);
		tot = 0;
		
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", fa + i);
		
		int ans = 0;
		
		for (int i = 1; i <= n; ++i) {
			if (fa[fa[i]] != i) addedge(fa[i], i);
			else ++ans;
		}
		for (int i = 1; i <= n; ++i)
			if (fa[fa[i]] == i)
				ans += dfs(i);
		
		for (int i = 1; i <= n; ++i) {
			memset(v, 0, sizeof v);
			int cnt = 0;
			for (int x = i; ; v[x] = true, x = fa[x], ++cnt) {
				if (v[x]) {
					if (x != i) cnt = 0;
					break;
				}
			}
			ans = max(ans, cnt);
		}
		
		cout << "Case #" << ++Case << ": " << ans << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
