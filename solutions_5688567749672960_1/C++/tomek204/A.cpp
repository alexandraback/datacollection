#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n, out;

vector<int> numtovec(LL k) {
	vector<int> ret;
	while (k) {
		ret.push_back(k%10);
		k /= 10LL;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

LL vectonum(vector<int> vec) {
	LL ret = 0;
	for (int i = 0; i < int(vec.size()); i++) {
		ret = 10LL * ret + vec[i];
	}
	return ret;
}

LL highestpow() {
	LL pow = 1;
	while (pow <= n) pow = pow * 10LL;
	pow = pow/10LL;
	return pow;
}

void next() {
	if (n%10 == 0) {
		n--;
		out++;
	}
	vector<int> vec = numtovec(n);
	int b = int(vec.size());
	for (int i = 1; i <= b/2; i++) {
		if (i == 1) vec[b-i] = 1;
		else vec[b-i] = 0;
	}
	LL from = vectonum(vec);
	reverse(vec.begin(), vec.end());
	LL goal = vectonum(vec);
	//printf("%lld: %lld %lld\n", n, from, goal);
	if (goal != from) {
		out = out + n - from + 1;
		n = goal;
	}
	out = out + n - highestpow() + 1;
	n = highestpow()-1;
}

LL solve() {
	out = 0;
	scanf("%lld", &n);
	while (n > 0LL) {
		next();
	}
	return out;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: %lld\n", i, solve());
	}
	return 0;
}