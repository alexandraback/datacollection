#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

typedef long long int64;
typedef long double ldouble;

#define PB(a) push_back(a)
#define MP(a, b) make_pair(a, b)

#define PROBLEM "C"

int logten(int x) {
	int a = 0;
	while (x > 0) {
		x /= 10;
		a++;
	}
	return a;
}

int cycle(int x, int w, int l) {
	int a[10];
	for (int i = 0; i < l; i++) {
		a[i] = x % 10;
		x /= 10;
	}
	int st = w, y = 0;
	for (int i = 0; i < l; i++) {
		st = (st - 1 + l) % l;
		y = y * 10 + a[st];
	}

	return y;
}

int main() {
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);

		int a, b;
		scanf("%d %d", &a, &b);

		int ans = 0;
		for (int x = a; x < b; x++) {
			int l = logten(x);
			set<int> ok;
			for (int i = 1; i < l; i++) {
				int y = cycle(x, i, l);
                if (x < y && y <= b) {
                	assert(logten(x) == logten(y));
                	assert(x == cycle(y, l-i, l));
                	ok.insert(y);
                }
            }
            ans += ok.size();
		}

		printf("%d", ans);

		printf("\n");
	}

	return 0;
}
