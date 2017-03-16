#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ULL long long

ULL mmax, re, n;
ULL val[10042];

ULL best(int l, int r, ULL start, ULL end) {
	if (l >= r) return 0;

	int hi = l;
	for (int i = l+1; i < r; ++i) {
		if (val[i] > val[hi]) hi = i;
	}
	
	ULL max_can_get = min(mmax, start + (hi-l)*re);
	ULL must_remain = max(0ll, end - (r-hi)*re);
	
	//printf("take %lld from %lld (mcg: %lld, mr: %lld)\n", max_can_get - must_remain, val[hi], max_can_get, must_remain);
	
	return val[hi] * (max_can_get - must_remain)
		+ best(l, hi, start, max_can_get)
		+ best(hi+1, r, must_remain + re, end);
}

int main() {
	int testcases;
	scanf("%d", &testcases);
	for (int testcase = 1; testcase <= testcases; ++testcase) {
		scanf("%lld %lld %lld", &mmax, &re, &n);
		for (int i = 0; i < n; ++i) scanf("%lld", &val[i]);
		printf("Case #%d: %lld\n", testcase, best(0, n, mmax, 0));
	}
}
