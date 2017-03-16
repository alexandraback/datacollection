#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;
ll A, B;
vector<ll> v;

bool Judge(ll x) {
	static char buf[64];
	sprintf(buf, "%I64d", x);
	int l = 0, r = strlen(buf) - 1;
	while (l < r) {
		if (buf[l] != buf[r]) return false;
		++ l, -- r;
	}
	return true;
}

int main() {
	freopen("t.in", "r", stdin);
	freopen("t.out", "w", stdout);
	int T;
	scanf("%d", &T);
	v.push_back(0LL);
	for (int i = 1; i <= 10000000; ++ i) {
		ll j = (ll)i * i;
		if (Judge(i) && Judge(j)) v.push_back(j);
	}
	v.push_back(10000000000000000LL);
	for (int t = 0; t < T; ++ t) {
		scanf("%I64d%I64d", &A, &B);
		int l = lower_bound(v.begin(), v.end(), A) - v.begin();
		int r = lower_bound(v.begin(), v.end(), B + 1) - v.begin();
		printf("Case #%d: %d\n", t + 1, r - l);
	}
	return 0;
}
