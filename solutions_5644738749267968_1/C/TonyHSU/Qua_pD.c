#include<stdio.h>
#include<stdlib.h>

double input1[1005], input2[1005];

int cmp(const void *a, const void *b) {
	double ta= *(double *)a;
	double tb= *(double *)b;
	if (ta>tb) return -1;
	else if (ta<tb) return 1;
	else return 0;
}

int main() {
	int T, nm= 1;
	scanf("%d", &T);
	int i, j, k;
	while (T--) {
		int n;
		scanf("%d", &n);
		for (i=0;i<n;i++) {
			scanf("%lf", &input1[i]);
		}
		for (i=0;i<n;i++) {
			scanf("%lf", &input2[i]);
		}
		qsort(input1, n, sizeof(double), cmp);
		qsort(input2, n, sizeof(double), cmp);
		int ans1= 0, ans2= 0;
		i= 0;
		j= 0;
		while (i<n && j<n) {
			if (input2[j] > input1[i]) {
				i++;
				j++;
				ans2++;
			}
			else {
				i++;
			}
		}
		i= 0;
		j= 0;
		while (i<n && j<n) {
			if (input2[j] < input1[i]) {
				i++;
				j++;
				ans1++;
			}
			else {
				j++;
			}
		}
		
		
		printf("Case #%d: %d %d\n", nm++, ans1, n-ans2);
	}
	return 0;
}
