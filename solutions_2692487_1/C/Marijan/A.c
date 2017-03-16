#include <stdio.h>
#include <stdlib.h>
/* Problem A */

int m[100];

int main() {
	int i,j,T,tt,y,n,N,A,temp,oldn;

	scanf("%d\n",&T);
	for (tt=1;tt<=T;tt++) {
		printf("Case #%d: ",tt);
		scanf("%d %d\n",&A,&N);
		for (i=0;i<N;i++) {
			scanf("%d",&m[i]);
			for (j=0;j<i;j++)		/* insertion sort */
				if (m[i] < m[j]) 
					temp = m[i], m[i] = m[j], m[j] = temp;
			
		}
		if (A == 1) {
			printf("%d\n", N);
			continue;
		}
		n = 0;
		for (i=0;i<N;i++) {
			oldn = n;
			while (A<=m[i]) {
				n++;
				A += A-1;
			}
			if (n-oldn > N-i) {
				n = oldn+N-i;
				break;
			}
			A += m[i];
			if (n >= N) {
				n = N;
				break;
			}
		}
		printf("%d\n", n);
	}
}
