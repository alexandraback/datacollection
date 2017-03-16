#include <stdio.h>

int main() {
	int i, j, m1, m2, m3, t, ans;
	int n, s, p;
	int a[100];
	
	scanf("%d", &t);
	
	for (i = 0; i < t; i++) {
		ans = 0;
		scanf("%d %d %d", &n, &s, &p);
		for (j = 0; j < n; j++) {
			scanf("%d", &a[j]);
			m1 = a[j] / 3;
			m2 = (a[j] - m1) / 2;
			m3 = a[j] - m1 - m2;
			if (m3 >= p) {
				ans ++;
			}
			else if (s > 0 && m3 + 1 >= p && m3 == m2 && m2-1 >= 0) {
				ans ++;
				s --;
			}
		}
		printf("Case #%d: %d\n", i+1, ans);
	}
	
	return 0;
}