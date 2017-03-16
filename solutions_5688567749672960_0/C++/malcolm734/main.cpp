#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;
const int N = 1e6 + 100;

int n;
int dp[N + 100];

int reverse(int a) {
	int res = 0;
	while (a > 0) {
		res = res * 10 + (a % 10);
		a /= 10;
	}
	return res;
}

inline void solve() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		dp[i] = inf;
	}
	dp[1] = 1;
	for (int i = 1; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int rev = reverse(i);
		if (rev <= n) {
			dp[rev] = min(dp[rev], dp[i] + 1);
		}
	}
	cout << dp[n] << endl;
}

int main() {
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
	}
    return 0;
}
