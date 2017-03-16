#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <sstream>
#include <string>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>

#include <algorithm>

#include <utility>

using namespace std;

#define INF 2000000000
#define INFL 9000000000000000000LL
#define INFF 1.0e18
#define EPS 1.0e-8

int T, R, N, M, K, a[15], ans[15];

int b[155], bw;

bool check() {
	b[1] = bw;
	for (int i = 0; i < N; ++i) {
		for (int j = 150; j > 0; --j) {
			if (b[j] == bw && j * ans[i] < 150) {
				b[j * ans[i]] = bw;
			}
		}
	}
	bool ret = true;
	for (int i = 0; i < K; ++i) {
		if (b[a[i]] != bw) ret = false;
	}
	bw++;
	return ret;
}

bool doit(int n) {
	if (n == N) {
		if (check()) {
			for (int i = 0; i < N; ++i) {
				printf("%d", ans[i]);
			}
			printf("\n");
			return true;
		}
		return false;
	}
	for (int i = 2; i <= M; ++i) {
		ans[n] = i;
		if (doit(n+1)) return true;
	}
	return false;
}

int main() {
	scanf("%d", &T); 
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d%d%d", &R, &N, &M, &K);
		printf("Case #%d:\n", tc);
		while (R--) {
			bw = 0;
			memset(b, -1, sizeof(b));
			for (int i = 0; i < K; ++i) {
				scanf("%d", &a[i]);
			}
			if (!doit(0)) {
				for (int i = 0; i < N; ++i) {
					printf("1");
				}
				printf("\n");
			}
		}
	}


	return 0;
}

