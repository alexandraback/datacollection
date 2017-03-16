#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

long long tp[20] = {1};

long long T, N;

long long func(long long x) {
	int o = upper_bound(tp, tp + 20, x) - tp;
	if(o == 1)
		return x;
	if(x % 10 == 0)
		return 1 + func(x - 1);
	long long v = tp[o - 1] - 1;
	long long ans = 1 + func(v);
	int i = 0, d;
	while(x) {
		d = x % 10;
		ans += d * tp[min(i, o - i - 1)];
		x /= 10;
		if(i == (o - 1) / 2 && x == tp[o - i - 2])
			--ans;
		++i;
	}
	return ans;
}

int main() {
	for(int i = 1; i < 20; ++i)
		tp[i] = 10 * tp[i - 1];
	scanf("%lld", &T);
	for(int t= 1; t <= T; ++t) {
		scanf("%lld", &N);
		printf("Case #%d: %lld\n", t, func(N));
	}
	return 0;
}
