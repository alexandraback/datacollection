#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-8;

ll u[105];
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++) {
		ll K, C, S, i, j;
		scanf("%lld %lld %lld", &K, &C, &S);

		printf("Case #%d: ", tc);
		if (C*S < K) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		while (C*(S - 1) >= K) S--;
		for (i = 0; i < S; i++) {
			for (j = 0; j < C; j++) u[j] = min(K - 1, i*C + j);
			ll v = 0;
			for (j = 0; j < C; j++) v = v*K + u[j];
			printf("%lld ", v + 1);
		}
		printf("\n");
	}
	return 0;
}