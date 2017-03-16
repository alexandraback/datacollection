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

int r,t;

ll solve() {
	scanf("%lld %lld", &r, &t);
	ll ans = 0;
	while(true) {
		if (2 * r + 1 > t) break;
		t -= 2 * r + 1;
		++ans;
		r += 2;
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc){
		printf("Case #%d: %lld\n", tc, solve());
	}
}
