#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int a, b, c, k;
int ba[30], bb[30], bc[30];

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int TT;
	cin >> TT;
	for (int T = 1; T <= TT; ++T) {
		fprintf(stderr, "Now is solving %d\n", T);
		printf("Case #%d: ", T);
		cin >> a >> b >> c >> k;
		if (k > c) k = c;
		int now = 0;
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < min(b, k); ++j) {
				for (int t = 0; t < k; ++t) {
					ba[now] = i;
					bb[now] = (j * min(b, k) + i) % b;
					++now;
				}
			}
		}
		int t = 0;
		for (int i = 0; i < now; ++i) {
			bc[i] = t;
			t = (t + 1) % c;
		}
		printf("%d\n", now);
		for (int i = 0; i < now; ++i) {
			printf("%d %d %d\n", ba[i] + 1, bb[i] + 1, bc[i] + 1);
		}
	}
	return 0;
}
