#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 20;
int a[N], mark[3000000];

int main() {
	int tc, n;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		memset(mark, 0, sizeof(mark));
		printf("Case #%d:\n", t);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}

		bool find = false;
		for (int i = 1; i < (1 << n); i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					sum += a[j];
				}
			}
			bool flag;
			if (mark[sum] != 0) {
				flag = true;
				for (int j = 0; j < n; j++) {
					if (mark[sum] & (1 << j)) {
						if (flag) {
							flag = false;
						} else {
							printf(" ");
						}
						printf("%d", a[j]);
					}
				}
				printf("\n");

				flag = true;
				for (int j = 0; j < n; j++) {
					if (i & (1 << j)) {
						if (flag) {
							flag = false;
						} else {
							printf(" ");
						}
						printf("%d", a[j]);
					}
				}
				printf("\n");
				find = true;
				break;
			} else {
				mark[sum] = i;
			}
		}
		if (!find) {
			printf("Impossible\n");
		}
	}
	return 0;
}

