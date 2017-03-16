#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MIN(a,b) a<b?a:b
int n, m, k;
int main(){
	int t, tc = 1;
	for(scanf("%d", &t); tc <= t; tc++) {
		scanf("%d%d%d", &n, &m, &k);
		int ans = k;
		for(int i = 3; i <= n; i++) {
			for(int x = 0; x <= 4; x++) {
				int j = (k + x) / i;
				if(j > m || 3 > j || (k+x)%i) continue;
				int tmp = k - (i-2) * (j-2);
				if(x <= 2 && ((n>i && j>3) || (m>j && i>3))) {
					tmp--;
					if(x == 4 && n > i && m > j) tmp--;
				}
				ans = MIN(ans, tmp);
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}
