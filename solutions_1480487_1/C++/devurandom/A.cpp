#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double err = 1e-9;
int s[300];
double a, b, m;
int N, C;
int sum = 0;

bool test(double p) { //gewinnt
	double ca = s[C] + p*sum;
	double r = 0;
	for(int i=0; i<N; i++) {
		if(s[i]<ca) {
			//printf("es fehlen %lf\n", ca - s[i]);
			r += (ca-(double)s[i])/(double)sum;
		}
	}
	//printf("bei %lf %lf ist r=%lf\n", ca, p, r);
	if(r>1) return false;
	else return true;
}
int main() {
	//freopen("A.in", "r", stdin);
	int T;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++) {
		N = 0;
		scanf("%d", &N);
		sum = 0;
		for(int i=0; i<N; i++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		printf("Case #%d:", t);
		for(C=0; C<N; C++) {
			a = 0; b = 1;
			
			while(b-a>err) {
				
				m = (a+b)/2;
				if(test(m))
					a = m;
				else
					b = m;
			}
			printf(" %lf", a*100);
		}
		printf("\n");
		
		
	}
}
