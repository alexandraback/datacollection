#include <stdio.h>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <time.h>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

typedef pair <int, int> ii;
typedef pair <long long, long long> ll;

const int N = 1005;
char s[N][22], p[N][22];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s %s", s + i, p + i);

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		map <string, bool> mf, ms;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) mf[s[j]] = ms[p[j]] = 1;
		}
		bool ok = 1;
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (!(i &(1 << j))) {
				if (!mf[s[j]]) ok = 0;
				if (!ms[p[j]]) ok = 0;
				++c;
			}
		}
		if (ok) ans = max(ans, c);
	}

	printf("%d\n", ans);

}


int main() {
	
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int R = 1; R <= T; R++) {
		printf("Case #%d: ", R);
		solve();

	}

}