#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_a"
const ldb pi = acos(-1.0);

const int N = (int) 1e6 + 10;
int ans[N], t, n;

int get_rev(int x) {
	if (x % 10 == 0) return x;
	int y = 0;
	while (x > 0)
		y = (y * 10) + (x % 10), x /= 10;
	return y;
}

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	ans[1] = 1;
	for (int i = 2; i < N; ++i) {
		ans[i] = ans[i - 1] + 1;
		int j = get_rev(i);
		if (j < i) ans[i] = min(ans[i], ans[j] + 1);
	}
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		printf("Case #%d: %d\n", it + 1, ans[n]);
	}
	return 0;
}
