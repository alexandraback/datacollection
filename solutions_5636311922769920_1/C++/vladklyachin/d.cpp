#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define CC 110

int t, k, c, s;

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		printf("Case #%d: ", ti+1);
		scanf("%d%d%d", &k, &c, &s);
		if (s * c < k) {
			printf("IMPOSSIBLE\n");
		} else {
			int64_t prod = 1;
			int64_t sum = 0;
			for (int i = 0; i < k; ++i) {
				if (i % c == 0) {
					if (i != 0) {
						printf("%lld ", sum+1);
					}
					prod = 1;
					sum = 0;
				}
				sum += i * prod;
				prod *= k;
			}
			printf("%lld\n", sum+1);
		}
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
