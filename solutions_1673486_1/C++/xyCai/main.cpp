#include <stdio.h>
#include <stdlib.h>
double p[100010], q[100010];

int main()
{
//    freopen("A-large.in","r",stdin);
//    freopen("A-large.out","w",stdout);
	int t; // casesw
	int a, b, c;
	int i, j;
	double m;
	scanf("%d", &t);
	for (i = 0; i < t; ++i) {
		scanf("%d %d", &a, &b);
		for (j = 0; j < a; ++j) {
			scanf("%lf", p + j);
		}
		p[j] = 1;

		for (j = 0; j < a; ++j) {
			p[j+1] *= p[j];
		}

		//q[0] = p[a-1] * (b-a+1) + (1-p[a-1]) * (2*b-a+2);
		for (j = 0; j <= a; ++j) {
			c = j;
			q[j] = p[a-c-1] * (2*c+b-a+1) + (1 - p[a-c-1]) * (2*c+2*b-a+2);
		}
		q[a+1] = b + 2;

		m = 400000;
		for (j = 0; j < a + 2; j++)
			if (m > q[j])
				m = q[j];
		printf("Case #%d: %.6f\n",i+1,m);
	}
	return 0;
}
