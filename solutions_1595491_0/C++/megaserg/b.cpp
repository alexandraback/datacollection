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

#define PROBLEM "B"

const int MAXN = 128;
int a[MAXN];

int get1(int n) {
	int x = 0;
	if (n % 3 == 0) x = n/3;
	if (n % 3 == 1) x = n/3 + 1;
	if (n % 3 == 2) x = n/3 + 1;
	return min(x, 10);
}

int get2(int n) {
	int x = 0;
	if (n % 3 == 0) x = n/3 + 1;
	if (n % 3 == 1) x = n/3 + 1;
	if (n % 3 == 2) x = n/3 + 2;
	return min(x, 10);
}

int main() {
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	scanf("%d\n", &T);

	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);

		int n, s, p;
		scanf("%d %d %d", &n, &s, &p);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		int c1 = 0, c2 = 0;

		for (int i = 0; i < n; i++) {
			int g1 = get1(a[i]), g2 = get2(a[i]);
			if (g1 >= p) {
				c1++;
			}
			else if (2 <= a[i] && a[i] <= 28 && g2 >= p) {
				c2++;
			}
		}

		printf("%d", c1 + min(c2, s));

		printf("\n");
	}

	return 0;
}
