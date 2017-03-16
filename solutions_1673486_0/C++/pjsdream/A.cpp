#include <algorithm>
#include <stdio.h>
using namespace std;

int a, b;
double p[100010];

double prop[100010];

int main()
{
	int i, j;

	int t, tt=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		for (i=0; i<a; i++) scanf("%lf", &p[i]);

		prop[0] = 1;
		for (i=1; i<=a; i++) prop[i] = prop[i-1] * p[i-1];

		double answer[3];
		answer[0] = prop[a] * (b-a+1) + (1-prop[a]) * (b-a+1 + b+1);
		answer[2] = 1 + b+1;

		answer[1] = -1;
		for (i=1; i<=a; i++) {
			if (answer[1]==-1 || answer[1] > prop[i] * (a-i+1 + b-i) + (1-prop[i]) * (a-i+1 + b-i + b+1))
				answer[1] = prop[i] * (a-i+1 + b-i) + (1-prop[i]) * (a-i+1 + b-i + b+1);
		}

		printf("Case #%d: %.8lf\n", ++tt, min(min(answer[0], answer[1]), answer[2]));
	}

	return 0;
}
