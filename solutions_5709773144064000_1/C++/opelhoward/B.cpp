#include <cstdio>
int main() {
	int nt;
	scanf("%d", &nt);
	for (int t = 1; t <= nt; t++) {
		double c, f, x;
		scanf("%lf %lf %lf", &c, &f, &x);

		double time_prev, time_next, ans;
		double cost_rate = 2.0;
		time_prev = 0.0;
		time_next = x/cost_rate;
		do {
			ans = time_next;
			time_prev = time_prev+c/cost_rate;
			cost_rate += f;
			time_next = time_prev+x/cost_rate;
		}
		while (ans > time_next);
		printf("Case #%d: %.7lf\n", t, ans);
	}
	return 0;
}