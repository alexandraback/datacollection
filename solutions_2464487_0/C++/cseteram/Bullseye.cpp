#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {	// general solution : find max(n) s.t. 2n^2+(2r-1)n<=t

	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int c,T,i,j;
	unsigned long long int r,t,n,r_,n_,sum,k;

	scanf("%d", &T);

	for(c=1 ; c<=T ; c++) {
		scanf("%llu %llu", &r, &t);
		n=(unsigned long long int)(sqrt(8.0*t)/4);

		n_=n, r_=r;
		for(i=1 ; n_>0 ; n_/=10, i++);
		for(j=1 ; r_>0 ; r_/=10, j++);

		if((i-1)*(j-1)>18) {
			sum=0, k=0;
			while(sum<=t) {
				k++;
				sum+=(2*r+4*k-3);
			}

			n=k-1;
		}

		else
			while(2*n*n+(2*r-1)*n>t) n--;

		printf("Case #%d: %llu\n", c, n);
	}

	return 0;
}