#include <cstdio>

#define MAX_LEN 100000
double p[MAX_LEN];

int main(int argc, char const *argv[])
{
	freopen("in.txt", "r", stdin);
	int t, ti, a, b;
	scanf("%d", &t);
	ti = 0;
	while (ti++ < t) {
		scanf("%d %d", &a, &b);
		int ai = 0;
		double all = 1.0;
		while (ai < a) {
			scanf("%lf", p+ai);
			all *= p[ai];
			ai++;
		}
		int x = b-a+1;
		int y = 2*b-a+2;
		double tmp = x*all + y*(1-all);
		//printf("firest:%d %d %f %d %d tmp:%f\n",a, b, all, x, y, tmp);
		double min = tmp;
		double px = all;
	
		for (int i=a-1; i>=0; i--) {
			px = px/p[i];
			x += 2;
			y += 2;
			tmp = x*px + y*(1-px);
		//	printf("---%f\n", tmp);
			if (tmp < min) {
				min = tmp;
			}
		}
		if ((b+2.0) < min) {
			min = b+2.0;
		}
		printf("Case #%d: %f\n", ti, min);

	}
	return 0;
}