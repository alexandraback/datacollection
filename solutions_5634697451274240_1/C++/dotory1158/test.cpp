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

char in[105];
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%s", in);

		int L = strlen(in);
		in[L] = '+';
		int ans = 0, i;
		for (i = 0; i < L; i++) if (in[i] != in[i + 1]) ans++;

		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}