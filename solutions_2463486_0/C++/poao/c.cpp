#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long ll;

std::vector<ll> ans;

inline bool check(ll a) {
	char buf[30];
	int cnt = 0;
	while(a > 0) {
		buf[cnt] = a % 10;
		a /= 10;
		cnt ++;
	}
	for(int i=0; i<cnt; i++)
		if(buf[i] != buf[cnt-i-1])
			return false;
	return true;
}

int count(ll pos) {
	return std::upper_bound(ans.begin(), ans.end(), pos) - ans.begin();
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small.txt", "w", stdout);
	for(int i=1; i<=10000000; i++)
		if(check(i) && check((ll)i*i))
			ans.push_back((ll)i*i);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		ll a, b;
		scanf("%I64d%I64d", &a, &b);
		printf("Case #%d: %d\n", tc, count(b)-count(a-1));
	}
}
