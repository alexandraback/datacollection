#include <stdio.h>

int T;

void solve(int k) {
	double c, f, x, now_guess=2000000, now_time=0, fast=2.0;

	scanf("%lf %lf %lf", &c, &f, &x);

	for(int i=0; ; i++) {
		if(now_guess>now_time+x/fast) {
			now_guess=now_time+x/fast;
//			printf("[%lf %lf]\n", now_guess, fast);
			now_time+=c/fast;
			fast+=f;
		}else break;
	}

	printf("Case #%d: %.10lf\n", k, now_guess);

}

int main() {
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &T);
	for(int i=1; i<=T; i++)
		solve(i);
	return 0;
}
