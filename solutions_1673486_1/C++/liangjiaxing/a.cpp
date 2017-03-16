#include<stdio.h>
#include<string.h>

double p[100100];
double a[100100];

int main(){
	int i, j, k, m, n;
	int A, B, s, S;
	int T, re;
	freopen("x.txt", "r", stdin);
	freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for(re = 1; re <= T; re++){
		scanf("%d%d", &A, &B);
		p[0] = 1;
		//printf("A B = %d %d\n", A, B);
		for(i = 1; i <= A; i++){
			scanf("%lf", a + i);
			//printf("%d\n", a[i]);
			p[i] = p[i - 1] * a[i];
			//printf("p[%d]=%lf\n", i, p[i]);
		}
		p[A + 1] = 0;
		s = B + 1 - A;
		double ans = B + 2, E;
		for(j = 0; j <= A; j++){
			E = p[A-j] * s + (1-p[A-j]) * (s + B + 1);
			//printf("P = %lf E = %lf\n", p[A-j], E);
			if(E < ans)
				ans = E;
			s += 2;
		}
		printf("Case #%d: %lf\n", re, ans);
	}
	
}
