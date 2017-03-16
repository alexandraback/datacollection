#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t; scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		int smax;
		char s[1005];
		scanf("%d ", &smax);
		scanf("%s", s);
		int sum = 0, ans = 0;
		for (int i = 0; i <= smax; i++) {
			if (sum < i) {
				ans += (i - sum);
				sum += (i - sum);
			}
			sum += (s[i] - '0');
		}
		printf("Case #%d: %d\n", k + 1, ans);
	
	}

	return 0;
}