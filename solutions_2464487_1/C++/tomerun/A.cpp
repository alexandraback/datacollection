#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

ll r,t;

ll solve() {
	scanf("%lld %lld", &r, &t);
	ll left = 0;
	ll right = (ll)sqrt(t) + 1;
	while(left + 1 < right) {
		ll mid = (left + right) / 2;
		ll sum = mid * (2 * r + 2 * mid - 1);
		if (sum > t || (2 * r + 2 * mid - 1) > (ll)2e18 / mid + 1) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		printf("Case #%d: %lld\n", tc, solve());
	}
}
