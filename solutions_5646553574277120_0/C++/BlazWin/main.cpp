#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define ll long long


bool a[1000000];
bool c[100000];
int d, v;
int mmax = 100;

void doit(int p, int cur) {
	if (cur >= mmax) {
		return;
	}
	if (p == v + 1) {
		fill(c, c + v + 1, false);
		c[0] = true;
		int count = 0;
		for (int j = 1; j <= v; j++) {
			if (a[j]) {
				for (int i = v; i >= 0; i--) {
					if (c[i] && i + j <= v && !c[i + j]) {
						c[i + j] = true;
						count++;
					}
				}
			}
		}
		// cout << count << endl;
		if (count == v) {
			mmax = cur;
		}
		return;
	}

	if (!a[p]) {

		a[p] = true;
		doit(p + 1, cur + 1);
		a[p] = false;
		doit(p + 1, cur);
	} else {
		doit(p + 1, cur);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int jk = 0; jk < t; jk++) {
		int jjj;
		scanf("%d%d%d", &jjj, &d, &v);
		fill(a, a + v + 1, false);

		for (int i = 0; i < d; i++) {
			int j;
			scanf("%d", &j);
			a[j] = true;
		}
		mmax = 100;

		doit(1, d);

		printf("Case #%d: %d\n", jk + 1, mmax - d);
	}

	return 0;
}
