#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int t,T;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++){
		int A,B,K;
		int n_pairs;
		int i;
		scanf("%d %d %d\n",&A,&B,&K);
#if 0
#else
		// brute force search
		n_pairs=0;
		int a,b;
		for (a=0;a<A;a++){
			for (b=0;b<B;b++){
				if ((a&b)<K)n_pairs++;
			}
		}
#endif
		printf("Case #%d: %d\n",t,n_pairs);
	}
	return 0;
}
