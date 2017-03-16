#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
#include <map>
#include <set>
#include <list>
#include <iostream>

using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const lli LINF = 0x3f3f3f3f3f3f3f3f;

//#define _LOCAL_DEBUG_
#ifdef _LOCAL_DEBUG_
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...) 
#endif

void clear() {
}

void solve(int t) {
	int n;
	scanf("%d", &n);
	map<int, int> m;
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			m[a]++;
		}
	}

	vi res;
	for (auto p : m) if (p.second & 1) res.push_back(p.first);
	sort(res.begin(), res.end());
	printf("Case #%d: ", t);
	for (int i = 0; i < res.size(); i++)
		printf(i == res.size() - 1 ? "%d\n" : "%d ", res[i]);
}

int main() {
#ifdef _LOCAL_VAN
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		clear();
		solve(i + 1);
	}
	return 0;
}