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
const int N = 1111;
char c;
int n, t, cnt[N];

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d", &n);
		for (int i = 0; i <= n; ++i)
			scanf(" %c", &c), cnt[i] = c - '0';
		int ans = 0, cur_bad = 0, cur_cnt = 0;
		while (true) {
			while ((cur_bad <= n) && (cur_bad <= cur_cnt)) {
				cur_cnt += cnt[cur_bad];
				cur_bad++;
			}
			if (cur_bad > n) break;
			ans++, cur_cnt++;
		}
		printf("Case #%d: %d\n", it + 1, ans);
	}	
	return 0;
}
