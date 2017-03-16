#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define sqr(x) ((x) * (x))
#define mp make_pair
#define TASKNAME ""

const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

using namespace std;

void solve() {
	int r, c, w;
	scanf("%d %d %d", &r, &c, &w);
	int cc = c / w;
	int mcur = 0;
	for (int i = w; i <= c; i += w) {
		int len = min(c, i + w - 1) - max(1, i - w + 1);
		int cur = i / w + min(w, len);
		mcur = max(mcur, cur);
	}
	int ans = mcur + (r - 1) * cc;
	printf("%d", ans);
}

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif
	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; i++) {
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}