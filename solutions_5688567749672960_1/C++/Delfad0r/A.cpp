#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n_digits(ll x) {
	return int(ceil(log10(x + 1)));
}

ll mpow10(int n) {
	ll p = 1;
	while(n--)
		p *= 10;
	return p;
}

ll invert_digits(ll x) {
	string S = to_string(x);
	reverse(S.begin(), S.end());
	return stoll(S);
}

void solve(int t) {
	ll ans = 0;
	ll N;
	scanf("%lld", &N);
	while(N != 1) {
		if((N % 10) == 0) {
			--N;
			++ans;
		}
		ll N1 = N % ll(mpow10((n_digits(N) + 1) / 2));
		--N1;
		ans += N1;
		N -= N1;
		//printf("%lld\n", N);
		if(N == 1) break;
		if(N == invert_digits(N)) {
			N -= 2;
			ans += 2;
		} else {
			N = invert_digits(N);
			++ans;
		}
		//printf("%lld\n", N);
	}
	printf("Case #%d: %lld\n", t, ans + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
		solve(t);
}
