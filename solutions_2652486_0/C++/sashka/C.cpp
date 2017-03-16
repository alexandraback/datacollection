#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#define INF (2000000000)

const int nmax = 1 << 10;

bool b[nmax][nmax];

void prepare() {

	int a[3];

	memset(b, 0, sizeof(b));

	for(int i = 2; i <= 5; ++i) {
		a[0] = i;
		for(int j = 2; j <= 5; ++j) {
			a[1] = j;
			for(int k = 2; k <= 5; ++k) {
				a[2] = k;

				int r = i * 100 + j * 10 + k;

				for(int p = 0; p < 8; ++p) {
					int t = 1;
					for(int q = 0; q < 3; ++q) {
						if (p & (1 << q)) {
							t *= a[q];
						}
					}
					b[r][t] = true;
				}
			}
		}
	}


}

int a[nmax];
int n;

void readTest() {
	int r, n, m, k;
	scanf("%d%d%d%d", &r, &n, &m, &k);
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < k; ++j) {
			scanf("%d", &a[j]);
		}

		int ans = -1;

		for(int j = 0; j < nmax; ++j) {

			bool good = true;

			for(int q = 0; q < k; ++q) {
				if (!b[j][a[q]]) {
					good = false;
					break;
				}
			}

			if (good) {
				ans = j;
				printf("%d\n", j);
				break;
			}

		}

		if (ans == -1) {
			throw -1;
		}

	}

}

int main()
{
	freopen("C.in", "rt", stdin);

	bool submit = true;

	if (submit) {
		freopen("C.out", "wt", stdout);
	}

	prepare();

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		printf("Case #%d:\n", tt + 1);
		readTest();
		if (submit) {
			cerr << "Case " << tt + 1 << " done\n";
		}
	}
	return 0;
}