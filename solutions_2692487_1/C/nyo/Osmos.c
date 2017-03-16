#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int T;
	long long int A;
	int N;
	int i,j,k;
	long long int m[100];
	int y,delmin;

	scanf("%d", &T);

	for(i=0;i<T;i++){
		y=0;
		scanf("%lld %d", &A, &N);

		for(j=0;j<N;j++){
			scanf("%lld", &m[j]);
			for(k=j;k>0;k--){
				if(m[k]<m[k-1]){
					long long int tmp=m[k];
					m[k]=m[k-1];
					m[k-1]=tmp;
				} else {
					break;
				}
			}
		}
/*
		printf("A:%lld N:%d\n", A, N);
		for(j=0;j<N;j++){
			printf("%lld ", m[j]);
		}
		printf("\n");
*/


		delmin=N;
		for(j=0;j<N;j++){
			if(m[j] < A){
				A+=m[j];
//				printf("%lld ", A);
			} else if(m[j] < A*2-1) {
//				printf("(+%lld) ", A-1);
				A+=A-1;
				y++;
				A+=m[j];
//				printf("%lld ", A);
			} else if(A > 1){
				if(delmin > y+N-j){
					delmin = y+N-j;
				}
				while(m[j] >= A){
//					printf("(+%lld) ", A-1);
					A+=A-1;
					y++;
				}
				A+=m[j];
//				printf("%lld ", A);
			} else {
				y++;
//				printf("del ");
			}
		}
//		printf("\n");
		if(delmin < y){
			y = delmin;
		}

		printf("Case #%d: %d\n", i+1, y);
		
	}
}
