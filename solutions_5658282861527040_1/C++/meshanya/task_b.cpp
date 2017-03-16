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
#define taskname "task_b"
const ldb pi = acos(-1.0);

int t, a, b, k;
int64 res;

int64 solve(int i, int a, int b, int k) {
	if ((a == 0) || (b == 0) || (k == 0)) return 0;
	if (k >= max(a, b)) return a * (int64) b;
	if (i == -1) return 1;
	if (a < b) swap(a, b);
	if (a <= (1 << i)) return solve(i - 1, a, b, k);
	if (b <= (1 << i)) return (a == (1 << (i + 1))) ? 2 * solve(i - 1, 1 << i, b, k) : (solve(i - 1, a - (1 << i), b, k) + solve(i - 1, (1 << i), b, k));
	int64 res = 0;
	if (k > (1 << i)) res += solve(i - 1, a - (1 << i), b - (1 << i), k - (1 << i));
	if (a == (1 << (i + 1))) {
		if (b == (1 << (i + 1)))
			res += 3 * solve(i - 1, (1 << i), (1 << i), k);
		else
			res += 2 * solve(i - 1, (1 << i), (1 << i), k) + solve(i - 1, (1 << i), b - (1 << i), k);
	} else {
		res += solve(i - 1, a - (1 << i), (1 << i), k);
		res += solve(i - 1, (1 << i), b - (1 << i), k);
		res += solve(i - 1, (1 << i), (1 << i), k);
	}
	return res;
}

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d%d", &a, &b, &k);
		printf("Case #%d: %lld\n", it + 1, solve(30, a, b, k));
	}
	return 0;
}