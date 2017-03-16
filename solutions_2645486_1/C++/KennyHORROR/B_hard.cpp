#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long v[100005];
int e, r, n;

long long solve(long long lb, long long rb, long long le, long long re) {
	if (le + (rb - lb) * r <= re) {
		return 0;
	}
	long long mx = -1, mpos = -1;
	for (int i = lb; i < rb; ++i) {
		if (mx < v[i]) {
			mx = v[i];
			mpos = i;
		}
	}
	long long mne = max(0LL, re - r * (rb - mpos));
	long long mxe = 0;
	if (le + (mpos - lb) * r <= e) {
		mxe = (le + (mpos - lb) * r);
	} else {
		mxe = e;
	}
	long long ret = 0;
	ret += (mxe - mne) * v[mpos];
	ret += solve(lb, mpos, le, mxe);
	ret += solve(mpos + 1, rb, mne + r, re);
	return ret;
}

int main() {
	freopen("b.in", "r", stdin);
	freopen("b_hard.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int I = 0; I < T; ++I) {
		printf("Case #%d: ", I + 1);
		scanf("%d%d%d", &e, &r, &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &v[i]);
		}
		r = min(r, e);
		cout << solve(0, n, e, r) << endl;
	}
	return 0;
}