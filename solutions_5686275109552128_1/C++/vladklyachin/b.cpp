#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 1010

int t, d;
int p[NN];

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d", &d);
		for (int i = 0; i < d; ++i) {
			scanf("%d", &p[i]);
		}
		sort(p, p+d, [](int a, int b){return a > b;});
		int best = p[0];
		for (int L = 1; L < p[0]; ++L) {
			int count = 0;
			for (int i = 0; i < d; ++i) {
				if (p[i] <= L) break;
				count += (p[i]-1)/L;
			}
			count += L;
			if (best > count) {
				best = count;
			}
		}
		printf("Case #%d: %d\n", ti+1, best);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
