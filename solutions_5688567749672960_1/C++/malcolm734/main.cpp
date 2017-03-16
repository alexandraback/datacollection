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
typedef unsigned long long lint64;

const int64 inf = (1 << 30) - 1;
const int64 N = 1e6 + 100;

int64 n;

int64 reverse(int64 a) {
	int64 res = 0;
	while (a > 0) {
		res = res * 10 + (a % 10);
		a /= 10;
	}
	return res;
}

inline int64 solve(int64 n) {
	if (n == 1) {
		return 1;
	}
	if (n % 10 != 1) {
		return solve(n - 1) + 1;
	}
	int64 pw = 1;
	int64 t = n;
	while (t > 0) {
		t /= 100;
		pw *= 10;
	}
	if (n % pw == 1 && reverse(n) < n) {
		return solve(reverse(n)) + 1;
	}
	return solve(n - 1) + 1;
}

inline void solve() {
	cin >> n;
	cout << solve(n) << endl;
}

int main() {
	int64 t; cin >> t;
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		solve();
		eprintf("Case #%d OK!\n", i);
	}
    return 0;
}
