#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:16000000")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 2 * acos(0.);

int a[300];

void solve() {
	int n;
	scanf("%d", &n);
	int s = 0;

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		s += a[i];
	}

		double l = 0;
		double r = s;
		for (int j = 0; j < 50; ++j) {
			double q = (l + r) / 2;
			double tmp = 0;
			for (int y = 0; y < n; ++y) {
				if (a[y] < q) {
					tmp += q - a[y];
				}
			}
			if (tmp > s) {
				r = q;
			} else {
				l = q;
			}
		}

	for (int i = 0; i < n; ++i) {
		printf("%.10lf ", max(0., 100. * (l - a[i]) / s));
	}
	printf("\n");

}

int main() {
#ifdef _DBG1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}