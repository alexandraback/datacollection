#include <stdio.h>

const int MAXN = 1010;

int n;
int ans;
int a[MAXN], b[MAXN];
int stat[MAXN];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int k = 1; k <= cases; ++k) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i], &b[i]);
			stat[i] = 0;
		}
		ans = 0;
		int sum = 0, finish = 0;
		while (true) {
			if (finish == n) break;
			int choose = -1, op = 0, acc = 0;
			for (int i = 0; i < n; ++i) {
				if (stat[i] == 2) continue;
				if ((stat[i] == 0) && (sum >= b[i]) && (acc < 2)) {
					choose = i;
					op = 2;
					acc = 2;
					continue;
				}
				if ((stat[i] == 1) && (sum >= b[i]) && (acc <= 1)) {
					choose = i;
					op = 2;
					acc = 1;
					continue;
				}
				if ((stat[i] == 0) && (sum >= a[i]) && (acc <= 1)) {
					if (op == 2) continue;
					if ((choose == -1) || (b[i] > b[choose])) {
						choose = i;
						op = 1;
						acc = 1;
					}
					continue;
				}
			}
//			printf("choose = %d, op = %d, acc = %d\n", choose, op, acc);
			if (choose == -1) break;
			++ans;
			stat[choose] = op;
			if (stat[choose] == 2) ++finish;
			sum += acc;
//			printf("%d, %d, %d\n", choose, op, finish);
		}
		if (finish == n)
			printf("Case #%d: %d\n", k, ans);
		else
			printf("Case #%d: Too Bad\n", k);
	}
	return 0;
}

