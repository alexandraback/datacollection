#include <stdio.h>
#include <memory.h>

bool check(int a[], int idx, int sum, int N, double m) {
	double c1 = m * sum;
	double d1 = a[idx] + c1;
	//printf("check %d %d %lf %lf %lf\n", sum, idx, m, c1, d1);
	double s = 0;
	for (int i = 0; i < N; i++) {
		if (i == idx)
			s += m;
		else {
			if (d1 < a[i]-1) continue;// return true;
			s += (d1 - a[i]) / sum;
		}
	}
	//printf("s = %lf\n", s);
	return s <= 1;	
}

int main() {
	int T;
	scanf("%d", &T);
	for (int ca = 1; ca <= T; ca++) {
		int N;
		scanf("%d", &N);
		
		int sum = 0, a[N];
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		
		//check(a, 0, sum, N, 0.3466666);
		//return 0;
		
		printf("Case #%d: ", ca);
		for (int i = 0; i < N; i++) {
			double l = 0, r = 1;
			while (r - l > 0.000000001) {
				double m = (l + r) / 2;
				
				if (check(a, i, sum, N, m))
					l = m;
				else
					r = m;
			}
			printf("%.6lf ", l * 100);
		}
		putchar(10);
	}
	
	
}
