#include <cstdio>
using namespace std;

int main() {
	freopen("qual\\D-large.in", "r", stdin);
	freopen("qual\\D-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int N=1; N<=T; ++N) {
		int k, c, s;
		scanf("%d%d%d", &k, &c, &s);
		printf("Case #%d: ", N);
		if (k == 1) {
			printf("1");
		} else if (c == 1) {
			if (s >= k) {
				for (int i=1; i<=k; ++i)
					printf("%d ", i);
			} else {
				printf("IMPOSSIBLE");
			}
		} else {
			if (s >= k-1) {
				for (int i=2; i<=k; ++i)
					printf("%d ", i);
			} else {
				printf("IMPOSSIBLE");
			}
		}
		puts("");
	}
}