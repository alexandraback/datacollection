#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
long long ans[maxn];
int cans = 0;

bool ispal(long long num) {
	int dig[20];
	int cnt = 0;
	while(num) {
		dig[cnt++] = num % 10;
		num /= 10;
	}
	for(int l = 0, r = cnt - 1; l < r; ++l, --r) {
		if(dig[l] != dig[r])
			return false;
	}
	return true;
}

void precalc() {
	for(int i = 1; i <= maxn; ++i) {
		long long sq = 1ll * i * i;
		if(ispal(i) && ispal(sq)) {
			ans[cans++] = sq;
		}
	}
}

void solve() {
	long long l, r;
	cin >> l >> r;
	long long cnt1 = lower_bound(ans, ans + cans, l) - ans;
	long long cnt2 = upper_bound(ans, ans + cans, r) - ans;
	cout << cnt2 - cnt1 << endl;
}

int main(int argc, char **argv) {
	freopen("C-large-1.in", "r", stdin);
	freopen("C-large-1.out", "w", stdout);
	int tt;
	precalc();
	scanf("%d", &tt);
	for(int t = 1; t <= tt; ++t) {
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}
