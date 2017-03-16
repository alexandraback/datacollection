#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <iostream>
#include <cstdlib>

using namespace std;

int T;
long long R, P;

int main() {
	scanf("%d", &T);
	for(int t = 1 ; t <= T ; t++) {
		scanf("%lld %lld", &R, &P);
		long long lo = 1, hi = P/(R * 2);
		while (lo < hi) {
			//cout << lo << " " << hi << endl;
			long long mid = lo + ((hi - lo + 1) >> 1);
			if (P / mid >= 2 * R + 2 * mid - 1) {
				lo = mid;
			}	else {
				hi = mid - 1;
			}
		}
		printf("Case #%d: %lld\n", t, hi);
	}
}
