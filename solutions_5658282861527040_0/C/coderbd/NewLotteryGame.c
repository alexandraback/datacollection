#include <stdio.h>

void solve(int case_no) {
	int a, b, k, i, j, ans = 0;

	scanf("%d%d%d", &a, &b, &k);
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++) {
			int kk = i & j;
			if (kk < k)
				ans++;
		}

	printf("Case #%d: %d\n", case_no, ans);
}

int main() {
	int t;

	scanf("%d", &t);
	for (int case_no = 1; case_no <= t; case_no++)
		solve(case_no);

	return 0;
}