#pragma comment(linker, "/STACK:66777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <assert.h>
#include <memory.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(a) (int)a.size()
#define fill(a, x) memset (a, x, sizeof(a))

#ifdef _DEBUG
	#define Eo(x) {cout << "# " << #x << " = " << (x) << endl;}
	#define E(x) {cout << "# " << #x << " = " << (x) << " ";}
	#define Ou(x) {cout << "# " << (x) << endl;}
#else
	#define Eo(x)
	#define E(x)
	#define Ou(x)
#endif

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

void sIO();
void iIO();
void fIO(string fn);
void TM();

int __;

int n, m;
vector< vector<int> > g;
bool ok, w[1111];

bool dfs(int v) {
	w[v] = true;
	int kk = sz(g[v]), tto;
	for (int i = 0; i < kk; ++i) {
		tto = g[v][i];
		if (w[tto]) return true;
		if (dfs(tto)) return true;
	}
	return false;
}

int main() {
	sIO();
	scanf("%d", &__);
	for (int _ = 1; _ <= __; ++_) {
		printf("Case #%d: ", _);
		scanf("%d", &n);
		g.clear();
		g.resize(n + 5);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			g[i].resize(m);
			for (int j = 0; j < m; ++j)
				scanf("%d", &g[i][j]);
		}
		ok = false;
		for (int i = 1; i <= n; ++i) {
			fill(w, 0);
			if (dfs(i)) {
				ok = true;
				break;
			}
		}
		if (ok) printf("Yes\n"); else printf("No\n");
	}
    return 0;
}

inline void sIO() {
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
}

inline void iIO() {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
}

inline void fIO(string fn) {
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	freopen ((fn + ".in").c_str(), "r", stdin);
	freopen ((fn + ".out").c_str(), "w", stdout);
#endif
}

inline void TM() {
#ifdef _DEBUG
	cout << endl << "# Time: " << clock() / 1000. << endl;
#endif
}