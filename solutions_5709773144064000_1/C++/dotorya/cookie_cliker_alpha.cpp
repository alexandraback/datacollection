#include <stdio.h>
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int data_no, T, N, i;
	double C, F, X, ans;
	scanf("%d", &T);
	for(data_no = 1; data_no <= T; data_no++) {
		scanf("%lf %lf %lf", &C, &F, &X);
		ans = 0;
		if(X/C - 2.0/F - 1.0 < 0) N = 0;
		else N = (int) (X/C-2.0/F-1.0) + 1;
		for(i = 0; i < N; i++) ans += C/(2+i*F);
		ans += X / (2.0+N*F);
		printf("Case #%d: %.7lf\n", data_no, ans);
	}
	return 0;
}

