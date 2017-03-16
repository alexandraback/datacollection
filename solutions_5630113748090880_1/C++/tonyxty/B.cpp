#include <cstdio>
#include <cstring>
using namespace std;

int count[2501];
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(count, 0, sizeof(count));
		int n;
		scanf("%d", &n);
		int k = n * (2 * n - 1);
		while (k--) {
			int _;
			scanf("%d", &_);
			count[_]++;
		}
		printf("Case #%d:", t);
		for (int h = 0; h <= 2500; h++) if(count[h] & 1)
			printf(" %d", h);
		putchar('\n');
	}
}
