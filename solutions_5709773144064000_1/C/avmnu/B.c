#include <stdio.h>

double get_time(int s, double c, double f, double x) {
	double t = 0.0f;
	int i;

	for (i = 0; i < s - 1; i++) {
		t += (c / ((i * f) + 2));
	}

	t += (x / (((s - 1) * f) + 2));

	return t;
}

int main()
{
	int t;
	scanf("%d", &t);

	int i;
	for (i = 1; i <= t; i++) {
		double c, f, x;
		double t_l, t_c;
		int s = 1;

		scanf("%lf %lf %lf", &c, &f, &x);

		t_l = x / 2;

		while (1) {
			s++;

			t_c = get_time(s, c, f, x);

			if (t_c >= t_l) {
				printf("Case #%d: %.7lf\n", i, t_l);
				break;
			}

			t_l = t_c;
		}
	}

	return 0;
}
