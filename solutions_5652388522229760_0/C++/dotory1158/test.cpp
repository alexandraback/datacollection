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

int chk[10];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("ouitput.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		ll N;
		int i, j;
		scanf("%lld", &N);
		if (N == 0) {
			printf("Case #%d: INSOMNIA\n", tc);
			continue;
		}
		for (i = 1;; i++) {
			ll u = N * i;
			while (u != 0) {
				chk[u % 10] = tc;
				u /= 10;
			}
			for (j = 0; j < 10; j++) if (chk[j] != tc) break;
			if (j == 10) {
				printf("Case #%d: %lld\n", tc, N*i);
				break;
			}
		}
	}
	return 0;
}