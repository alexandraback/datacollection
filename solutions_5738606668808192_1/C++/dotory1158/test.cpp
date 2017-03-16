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

ll chk[20];
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		
		int N, J;
		ll i, j;
		scanf("%d %d", &N, &J);

		printf("Case #%d:\n", tc);
		for (i = 0; i < J; i++) {
			ll t = 2*i+1;
			for (j = 0; j + 1 < N / 2; j++) {
				chk[j] = t % 2;
				t /= 2;
			}
			chk[N / 2 - 1] = 1;
			for (j = N / 2 - 1; j >= 0; j--) printf("%lld", chk[j]);
			for (j = N / 2 - 1; j >= 0; j--) printf("%lld", chk[j]);

			for (ll b = 2; b <= 10; b++) {
				t = 0;
				for (j = N / 2 - 1; j >= 0; j--) {
					t *= b;
					t += chk[j];
				}
				printf(" %lld", t);
			}
			printf("\n");
		}
	}
	return 0;
}