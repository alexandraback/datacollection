#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

const int nm = 1002;

int n, a[nm], amax;

bool kt(int m, int l) {
	int kq = 0;
	for (int i = 1; i <= n; ++i) {
		kq += (a[i] + l - 1) / l - 1;
	}
	return kq <= m;
}

int f(int m) {
	int l = 1, r = amax, mid, kq = amax;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (kt(m, mid)) {
			kq = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	return kq + m;
}

void solve(int test) {
	printf("Case #%d: ", test);
	amax = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		amax = max(amax, a[i]);
	}
	int kq = amax;
	for (int i = 1; i < amax; ++i)
		kq = min(kq, f(i));
	printf("%d\n", kq);
}

int main() {
#ifdef LOCAL
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}
