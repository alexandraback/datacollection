// #pragma comment(linker, "/STACK:10240000")

#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define Pow2(x) (1 << (x))
#define Contain(a, x) (((a) >> (x)) & 1)
#define Rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define Foru(i, a, b) for(int i = (a); i < (b); ++i)
#define Debug(x) (cerr << #x << " = " << (x) << endl)
#define Debug2(x, y) (cerr << #x << " = " << (x) << ", " << #y << " = " << (y) << endl)

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int INF = 1000000000;
const double EPS = 1e-7;

template <class T> inline bool cMin(T &a, const T &b) {
	return (a > b) ? (a = b, true) : (false);
}

template <class T> inline bool cMax(T &a, const T &b) {
	return (a < b) ? (a = b, true) : (false);
}

int C, D, V, x[133];
bool reachable[133];

int getMinUnreachable() {
	memset(reachable, 0, sizeof(reachable));
	Rep(S, 0, Pow2(D) - 1) {
		int sum = 0;
		for (int i = 0; i < D; ++i)
			if (S & Pow2(i))
				sum += x[i];
		if (sum <= V)
			reachable[sum] = true;
	}
	int now = 0;
	for ( ; now <= V && reachable[now]; ++now);
	return now;
}

void solve() {
	scanf("%d %d %d", &C, &D, &V);
	int cnt = 0;
	Rep(i, 1, D) {
		int v;
		scanf("%d", &v);
		if (v > V)
			continue;
		x[cnt++] = v;
	}
	D = cnt;
	int ans = 0;
	for ( ; ; ) {
		int vv = getMinUnreachable();
		if (vv > V)
			break;
		x[D++] = vv;
		++ans;
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	Rep(Case, 1, T) {
		printf("Case #%d: ", Case);
		solve();
	}
	return 0;
}
