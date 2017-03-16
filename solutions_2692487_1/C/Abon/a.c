#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int lluint_cmp(const void * a, const void * b){
  return (*(unsigned long long int*)a-*(unsigned long long int*)b);
}

int main(){
	int T, N;
	int i=1,j,k;
	int result, worstresult;
	int subresults[101];
	unsigned long long int A, motes[101];
	scanf("%d", &T);
	while(i<=T){
		scanf("%llu %d", &A, &N);
		result=0;
		j=N;
		while(j--) scanf("%llu", &motes[j]);
		qsort (motes, N, sizeof(unsigned long long int), lluint_cmp);

		j=0;
		k=0;
		while(j<N){
			if(A<=motes[j]){
				subresults[k++]=result+N-j;
				while(A<=motes[j]){
					A=A+A-1;
					++result;
					if(result>=N) break;
				}
				A+=motes[j];
				if(result>=N) break;
			}else{
				A+=motes[j];
			}
			++j;
		}
		subresults[k++]=result;
		result=N;
		while(k--) if(result>subresults[k]) result=subresults[k];

		printf("Case #%d: %d\n", i, result);
		++i;
	}

	return 0;
}
