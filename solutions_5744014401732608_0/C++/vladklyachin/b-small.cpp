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
int a[NN][NN];
int64_t c[NN];
int total;

int main()
{
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%lld", &B, &M);
		if (M < 1 && M > (2L >> B)) {
			printf("Case #%d: IMPOSSIBLE\n", ti+1);
			continue;
		}
		memset(a, 0, sizeof(a));
		int bits = B*(B-1)/2;
		int power = 1 << bits;
		bool found = false;
		for (int cs = 1; cs < power; ++cs) {
			int bit = 1;
			for (int j = 0; j < B; ++j) {
				for (int i = j+1; i < B; ++i) {
					a[j][i] = !!(cs & bit);
					bit <<= 1;
				}
			}
#if 0
			printf("TRY cs=%d\n", cs);
			for (int j = 0; j < B; ++j) {
				for (int i = 0; i < B; ++i) {
					printf("%d", a[j][i]);
				}
				printf("\n");
			}
#endif
			c[B-1] = 1;
			for (int j = B-2; j >= 0; --j) {
				c[j] = 0;
				for (int i = j+1; i < B; ++i) {
					if (a[j][i]) {
						c[j] += c[i];
					}
				}
			}
#if 0
			printf("C:");
			for (int j = 0; j < B; ++j) {
				printf(" %lld", c[j]);
			}
			printf("\n");
#endif
			if (c[0] == M) {
				printf("Case #%d: POSSIBLE\n", ti+1);
				for (int j = 0; j < B; ++j) {
					for (int i = 0; i < B; ++i) {
						printf("%d", a[j][i]);
					}
					printf("\n");
				}
				found = true;
				break;
			}
		}
		if (!found) {
			printf("Case #%d: IMPOSSIBLE\n", ti+1);
		}
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
