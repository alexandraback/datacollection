#include<stdio.h>
#include<math.h>
double t[2005];
double x[2005];
double a[255];

double h1;
double h2;

double maximo(double aa, double bb){
	if (aa>bb) return aa;
	else return bb;
}

int main(){
	int T, N, A;	
	double D;
	scanf("%d ", &T);
	for(int g=0; g<T; g++){
		scanf("%lf %d %d ", &D, &N, &A);
		for(int r=0; r<N; r++){
			scanf("%lf %lf ", &t[r], &x[r]);	
		}
		printf("Case #%d:\n", g+1);
		for(int r=0; r<A; r++){
			//printf("N=%d\n", N);
			scanf("%lf ", &a[r]);
			h1 = sqrt((2*D)/a[r]);
			if(N==1){
				printf("%lf\n", h1);
				continue;
			}
			if(N==2){
				double v = (x[1]-x[0])/(t[1]-t[0]);
				h2 = ((D-x[0])/v);
				printf("%lf\n", maximo(h1, h2));
			}
		}
				
	}
	return 0;
}
