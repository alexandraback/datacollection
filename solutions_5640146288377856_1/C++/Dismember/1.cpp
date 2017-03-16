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

int R, C, W;
bool pos[333];

void solve() {
	memset(pos, 0, sizeof(pos));
	scanf("%d %d %d", &R, &C, &W);

	int base = R * (C / W);
	for (int i = W; i <= C; i += W)
		pos[i] = true;
	
	int cnt = 0;
	int o = C / W * W;
	for (int i = o - 1; i >= 1 && pos[i] == false; --i)
		++cnt;
	for (int i = o + 1; i <= C && pos[i] == false; ++i)
		++cnt;
	if (cnt >= W)
		++base;
	base += W - 1;
	printf("%d\n", base);
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
