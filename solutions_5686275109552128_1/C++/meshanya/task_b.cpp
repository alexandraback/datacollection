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
const int N = 1111;
int a[N], t, n, mx, res;

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n), mx = 0, res = (int) 1e9;
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]), mx = max(mx, a[i]);
		for (int i = 1; i <= mx; ++i) {
			int cur = 0;
			for (int j = 0; j < n; ++j)
				cur += (a[j] + i - 1) / i - 1;
			res = min(res, cur + i);
		}
		printf("Case #%d: %d\n", it + 1, res);
	}	
	return 0;
}
