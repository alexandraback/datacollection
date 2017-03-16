#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ld long double

using namespace std;

const int nm = 1010;

int n, a[nm];
vector<int> b;
bool fr[nm];

bool ok(int mask, int i) {
	b.pb(i);
	fr[i] = 0;
	bool res = 0;
	if (b.size() < 2 || b[b.size() - 2] != a[i]) {
		if (a[i] == b[0])
			if (b.size() == __builtin_popcount(mask))
				res = 1;
			else
				res = 0;
		else if (fr[a[i]])
			res = ok(mask, a[i]);
		else
			res = 0;
	} else {

		if (b.size() == __builtin_popcount(mask))
			res = 1;
		else {
			for (int j = 1; j <= n && !res; ++j) {
				if (((mask >> (j - 1)) & 1) && fr[j])
					res = ok(mask, j);
			}
		}

	}
	b.pop_back();
	fr[i] = 1;
	return res;
}

bool kt(int mask) {
	for (int i = 1; i <= n; ++i)
		if ((mask >> (i - 1) & 1) && ((mask >> (a[i] - 1)) & 1) == 0)
			return 0;
	for (int i = 1; i <= n; ++i)
		if ((mask >> (i - 1)) & 1) {
			b.clear();
			memset(fr, 1, sizeof(fr));
			return ok(mask, i);
		}
	return 0;
}

void solve(int test) {
	printf("Case #%d: ", test);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	int res = 1;
	for (int mask = 1; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) > res && kt(mask))
			res = __builtin_popcount(mask);
	}
	printf("%d\n", res);
}

int main() {
#ifdef LOCAL
	freopen("C-small-attempt0 (1).in", "r", stdin);
//	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}

