#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

#define sz(x) ((int)(x.size()))
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl
#define forn(i, x) for (int i = 0; i < (int)(x); ++i)
#define all(x) x.begin(), x.end()
#define PATH "C:\\Users\\Malkav\\Desktop\\"

typedef long long ll;

const int N = 100;

int n;
ll x;
ll a[N];

int solve() {
	if (x == 1) {
		return n;
	}
	int result = n;
	int cur = 0;
	
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		result = min(result, cur + n - i);
		while (x <= a[i]) {
			x += x - 1;
			cur++;
		}
		x += a[i];
	}
	result = min(result, cur);
	return result;
}

int main() {
	freopen(PATH"a.in", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%lld %d", &x, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
		}
		printf("Case #%d: %d\n", t, solve());
	}
	return 0;
}