#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;

int n, m;
ld a[103000];
ld pref[103000];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	pref[0] = 1.0;
	for (int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] * a[i];
	ld res = m + 2.0;
	for (int i = 0; i <= n; ++i) {
		res = min(res, ld(i) + pref[n - i] * ld(m - (n - i) + 1) + (1.0 - pref[n - i]) * ld(m - (n - i) + 1 + m + 1));
	}
	cout.precision(16);
	cout << res << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}