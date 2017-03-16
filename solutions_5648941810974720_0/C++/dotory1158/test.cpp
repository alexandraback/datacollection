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
const int INF = 534567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[2050];
int cnt[1000];
int ans[10];
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int i;
		scanf("%s", in);
		for (i = 0; in[i] != 0; i++) cnt[in[i]]++;

		ans[0] = cnt['Z'];
		ans[2] = cnt['W'];
		ans[4] = cnt['U'];
		ans[6] = cnt['X'];
		ans[8] = cnt['G'];
		ans[1] = cnt['O'] - ans[0] - ans[2] - ans[4];
		ans[3] = cnt['H'] - cnt['G'];
		ans[5] = cnt['F'] - cnt['U'];
		ans[7] = cnt['S'] - cnt['X'];
		ans[9] = cnt['I'] - ans[5] - ans[6] - ans[8];

		printf("Case #%d: ", tc);
		for (i = 0; i < 10; i++) while (ans[i]--) printf("%d", i);
		printf("\n");

		fill(cnt, cnt + 1000, 0);
	}
	return 0;
}