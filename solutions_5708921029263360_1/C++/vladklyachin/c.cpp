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

#define NN 12*12*12

int t;
int J, P, S, K;

int main()
{
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%d%d%d", &J, &P, &S, &K);
		if (K > S) {
			K = S;
		}
		printf("Case #%d: %d\n", ti+1, J*P*K);
		int s0 = 0;
		for (int j = 0; j < J; ++j) {
			int s = s0;
			for (int p = 0; p < P; ++p) {
				for (int k = 0; k < K; ++k) {
					printf("%d %d %d\n", j+1, p+1, s+1);
					s = (s + 1 + J*P)%S;
				}
			}
			++s0;
		}
		fflush(stdout);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
