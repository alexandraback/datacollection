#include <stdio.h>

int main()
{
int T,N;
int S[400];
int i;
int j;
int sum;
double k;
int max;
int n;

scanf("%d\n",&T);

for(i = 0; i < T ; i++) {
	int sum2;

	scanf("%d ",&N);
	n = N;
	sum = 0;
	max = 0;
	for(j = 0; j < N; j++) { 
		scanf("%d", &S[j]);
		if(S[j] > max) max = S[j];
		sum += S[j];
		}
	k = (double)(2 * sum) / N;
	sum2 = 2*sum;	

	for(j = 0; j < N; j++) { 
		if(S[j] > k) { sum2 -= S[j]; n--;}
	}
	k = (double)( sum2) / n;
	//if(k < (double) max) k = (double) max;
	printf("Case #%d: ",i+1 );
	for(j = 0; j < N; j++) {
		if(k < S[j]) printf("0.0 " );
		else printf("%lf ", (k - S[j])*100/sum) ;
		}
	printf("\n");
	
	}
}
