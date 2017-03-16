#include <stdio.h>
#include <math.h>

double probab[100010];
double accu[100010];
void pro(int A){
	double accum = 0;
	accu[0] = 1;
	for(int i = 1;i<=A;i++){
		accu[i] = accu[i-1]*probab[i-1];
	}
	for(int i = A;i>=0;i--){
		accu[i] = accu[i]-accum;
		accum+=accu[i];
	}
}

int main(){
	double avgmin, avg; 
	int A,B;
	int C;
	scanf("%d",&C);
	for(int c = 1;c<=C;c++){
	scanf("%d %d",&A,&B);
	avgmin = 2+B;
	for(int i = 0;i<A;i++){
		scanf("%lf",&(probab[i]));
	}
	pro(A);
	for(int apaga = 0;apaga<=A;apaga++){
		avg = 0;
		int se = (B-A+2*apaga+1);
		int ce =  B+1+(B-A+2*apaga+1);
		for(int i = 0;i<=A;i++){
			if(i<=apaga){
				avg+=accu[A-i]*se;
			}else {
				avg+=accu[A-i]*ce;

			}
		}
		avgmin = fmin(avgmin,avg);
	}
	printf("Case #%d: %.6f\n",c,avgmin);
	}
	return 0;
}
