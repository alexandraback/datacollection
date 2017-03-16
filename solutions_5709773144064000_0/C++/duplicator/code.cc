#include <stdio.h>
#include <math.h>

int main() {
	double X, C, F;
	int T;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt) {
		scanf("%lf %lf %lf", &C, &F, &X);
		printf ("Case #%d: ", tt);

		double rate = 2;
		double my_time = 0;
		while (true) {
			double time_x_cur = X/rate;
			double time_x_new = X/(rate + F);
			double time_c_cur = C/rate;
			if (time_x_cur < time_c_cur + time_x_new) {
				my_time += time_x_cur;
				break;
			} else {
				my_time += time_c_cur;
				rate += F;
			}
		}
		printf ("%.7lf\n", my_time);

/*		if (X <= C)
			printf ("%.7lf\n", X/2);
		else {
			int k = (int)(X/C - 1 - 2.0/F);
			if (k < 0)
				k = -1;
			double my_time = 0;
			for (int i=0; i<=k; ++i)
				my_time += C/(2+i*F);
			my_time += X/(2+(k+1)*F);
			printf ("%.7lf\n", my_time);
		}
*/	}
	return 0;
}
