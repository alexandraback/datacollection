#include <algorithm>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <strstream>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
typedef int64_t i64;
typedef double dbl;

#define NN 64

int t;
int B;
int64_t M;
int a[NN];
int64_t c[NN];
int total;

int main()
{
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%lld", &B, &M);
		if (M > (1L << (B-2))) {
			printf("Case #%d: IMPOSSIBLE\n", ti+1);
			continue;
		}
		printf("Case #%d: POSSIBLE\n", ti+1);
		memset(a, 0, sizeof(a));
		a[B-1] = 1;
		--M;
		for (int i = 0; i < B-1; ++i) {
			if (M & (1L << i)) {
				a[B-2-i] = 1;
			}
		}
#if 0
		c[B-1] = 1;
		for (int j = B-2; j >= 0; --j) {
			c[j] = 0;
			for (int i = j+1; i < B; ++i) {
				if (j > 0 || a[i]) {
					c[j] += c[i];
				}
			}
		}
		printf("A:");
		for (int j = 0; j < B; ++j) {
			printf(" %d", a[j]);
		}
		printf("\n");
		printf("C:");
		for (int j = 0; j < B; ++j) {
			printf(" %lld", c[j]);
		}
		printf("\n");
#endif
		for (int j = 0; j < B; ++j) {
			for (int i = 0; i < B; ++i) {
				printf("%d", (j == 0) ? a[i] : (i > j) ? 1 : 0);
			}
			printf("\n");
		}
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
