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

long long b, m;
long long up;
char ans[111][111];

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int TT;
	cin >> TT;
	for (int T = 1; T <= TT; ++T) {
		fprintf(stderr, "Now is solving %d\n", T);
		printf("Case #%d: ", T);
		cin >> b >> m;
		up = (1 << (b - 2));
		if (up < m) {
			puts("IMPOSSIBLE");
			continue;
		}
		puts("POSSIBLE");
		if (up == m) {
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < b; ++j) {
					if (i < j) putchar('1');
					else putchar('0');
				}
				puts("");
			}
		}
		else {
			for (int i = 0; i < b - 1; ++i) {
				for (int j = 0; j < b - 1; ++j) {
					if (i < j) ans[i][j] = '1';
					else ans[i][j] = '0';
				}
			}
			for (int i = 0; i < b; ++i) {
				ans[i][b - 1] = ans[b - 1][i] = '0';
			}
			for (int i = 0; i < b - 1; ++i) {
				if ((m >> i & 1) == 1) ans[i + 1][b - 1] = '1';
			}
			for (int i = 0; i < b; ++i) {
				for (int j = 0; j < b; ++j) {
					putchar(ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}
