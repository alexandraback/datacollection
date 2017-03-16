#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min(int n, int*s,int*s2) {
	int ans;
	ans = -1;
	int i;
	for (i = 0; i < n; i++) {
		if (s[i] >= 0)
			ans = i;
	}
	for (i = ans; i >= 0; i--) {
		if (ans == -1) break;
		if (s[i] >= 0 && s[i] <= s[ans]){
			if (s[i] == s[ans])
			ans = s2[i] >= s2[ans] ? i : ans+1-1;
			else ans = i;}

	}
	return ans;
}

int main() {
	int test, i;
	scanf("%d", &test);
	for (i = 1; i <= test; i++) {
		int level, m, ans, current, k;
		current = 0;
		ans = 0;
		scanf("%d", &level);
		int* s1 = malloc(sizeof(int) * level);
		int* s2 = malloc(sizeof(int) * level);
		for (k = 0; k < level; k++) {
			scanf("%d %d", &s1[k], &s2[k]);
		}
		int j;
		for (j = 1; j <= 2 * level; j++) {
			m = min(level, s2,s1);
			if (m == -1)
				break;
			else if (s2[m] <= current) {
				ans++;
				if (s1[m] == -1)
					current++;
				else {
					current += 2;
					s1[m] = -1;
				}
				s2[m] = -1;
				continue;
			}
			m = min(level, s1,s2);
			if (m == -1) {
				m = 0;
				//printf("Case #%d: Too Bad\n", i);
				break;
			}
			if (s1[m] <= current) {
				ans++;
				current++;
				s1[m] = -1;
				continue;
			} else {
				m = 0;
				//printf("Case #%d: Too Bad\n", i);
				break;
			}
		}
		if (m == -1)
			printf("Case #%d: %d\n", i, ans);
		else printf("Case #%d: Too Bad\n", i);
		free(s1);
		free(s2);
	}
	return 0;
}
