#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
typedef long long ll;

ll ans[128];
int main() {
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	int _, cas = 1;
	scanf("%d", &_);
	while (_--) {
		printf("Case #%d: ", cas);
		cas++;

		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		int num = (K + C - 1) / C;
		if (S < num) {
			puts("IMPOSSIBLE");
		} else {
			int cur = 0;
			for (int i = 0; i < num; ++i) {
				ll x = 0;
				for (int d = 0; d < C; ++d) {
					x = x * K + cur;
					cur = (cur + 1) % K;
				}
				ans[i] = x + 1;
			}
			for (int i = 0; i < num; ++i) {
				printf("%I64d", ans[i]);
				if (i != num - 1) printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;
}