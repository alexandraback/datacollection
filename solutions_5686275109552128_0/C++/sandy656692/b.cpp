#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, a[1010];

int main() {
	int T;
	scanf("%d", &T);
	for (int ttt = 1; ttt <= T; ++ttt) {
		int ans = 1010;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 1; i <= 1000; ++i) {
			if (ans < i) break;
			int now = i;
			for (int j = 0; j < n; ++j) {
				now += (a[j] - i) / i;
				if (a[j] - i > 0 && (a[j] - i) % i > 0) ++now;
			}
			if (ans > now) ans = now;
		}
		printf("Case #%d: %d\n", ttt, ans);
	}
	return 0;
}