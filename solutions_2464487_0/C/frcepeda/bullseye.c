#include <stdio.h>

int T;
unsigned long long int r, t, ans;

int main(void){
	int c, i;

	scanf("%d", &T);

	for (c = 1; c <= T; c++){
		scanf("%lld %lld", &r, &t);

		ans = 0;

		for (i = r+1; t > 0; i += 2){
			unsigned long long int n = i*i - (i-1)*(i-1);
			if (t >= n){
				t -= n;
				ans++;
			} else break;
		}

		printf("Case #%d: %llu\n", c, ans);
	}

	return 0;
}
