#include <stdio.h>

int main()
{
	int k, t;
	scanf("%d", &t);
	for (k = 0; k < t; k++) {
		printf("Case #%d: ", k + 1);
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double speed = 2.0;
		double result = 0.0;
		while (x / speed > (c / speed + x / (speed + f))) {
			result += c / speed;
			speed += f;
		}
		result += x / speed;
		printf("%.7f\n", result);
	}
	return 0;
}