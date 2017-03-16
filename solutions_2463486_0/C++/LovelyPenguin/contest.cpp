#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <bitset>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1000 * 1000 * 1000;
const int MX = 10001000;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) v.begin(), v.end()
#define SZ(v) (int) v.size()
#define MP make_pair
#define PB push_back

#define TASK ""

int cnt[MX];
int d[1 << 5];

bool check(ll x) {
	int sz = 0;
	while (x > 0) {
		d[sz++] = x % 10;
		x /= 10;
	}
	REP(i, sz)
		if (d[i] != d[sz - i - 1]) {
			return false;
		}
	return true;
}

int main() {
	#ifdef EDDY
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else 
	//	freopen(TASK ".in", "r", stdin);
	//	freopen(TASK ".out", "w", stdout);
	#endif

	for (int i = 1; i < MX; ++i) {
		cnt[i] = cnt[i - 1];
		if (check(i) && check(1LL * i * i)) {
			++cnt[i];
		}
	}

	int T;

	scanf("%d", &T);

	for (int tc = 1; tc <= T; ++tc) {
		ll A, B;
		scanf("%I64d%I64d", &A, &B);
		int x = 1, y = 1;
		while (1LL * x * x < A) {
			++x;
		}
		while (1LL * y * y <= B) {
			++y;
		}
		printf("Case #%d: %d\n", tc, cnt[y - 1] - cnt[x - 1]);
	}

	return 0;
}