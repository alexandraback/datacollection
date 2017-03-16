#pragma warning(disable:4996)
#include<stdio.h>
int main()
{
	int TC, T;
	double a, b, c, k, S, S2, t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%lf%lf%lf", &a, &b, &c);
		S = c / 2;
		t = 2;
		while (c / t > c / (t + b) + a / t){
			S = S - (c / t - c / (t + b) - a / t);
			t += b;
		}
		printf("%.7lf\n", S);
	}
}