#include <cstdio>
#include <cstring>

int main() {
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--) {
		printf("Case #%d: ", cas++);
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double rate = 2.0;
		double now = 0;
		double time = 0;
		if (c >= x) {
			time += x/rate;
		} else {
			while (true) {
				time += c/rate;
				double timeDirectTo = (x-c)/rate;
				double timeBuyThenTo = x/(rate+f);
				if (timeBuyThenTo < timeDirectTo) {
					rate += f;
				} else {
					time += timeDirectTo;
					break;
				}
			}
		}
		printf("%.9lf\n", time);
	}
	return 0;
}
