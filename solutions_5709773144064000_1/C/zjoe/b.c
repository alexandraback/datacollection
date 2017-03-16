#include <stdio.h>

int main(){
	long i, j, tot, n;
	double c, f, x, temp, ans;
	
	scanf("%d\n", &tot);
	for(i = 1; i <= tot; i++){
		scanf("%lf%lf%lf", &c,&f, &x);
		if(x / 2 <= c / 2 + x / (2 + f)){
			printf("Case #%d: %.7lf\n", i, x / 2);
			continue ;
		}

		temp = ((x - c) * f - 2 * c) / (c * f);
		n = (long)temp;
		if(temp == n){
			n -= 1;
		}

		ans = x / (2 + (n + 1) * f);
		for(j = 0; j <= n; j++){
			ans += c / (2 + j * f);
		}

		printf("Case #%d: %.7lf\n", i, ans);
	}
	return 0;
}
