#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	unsigned t,a,b;
	unsigned i,j;
	double * p;
	double keep,stop;
	double back_c;
	double ptot;
	
	scanf("%u\n",&t);
	for(i=1; i<=t; i++) {
		//read the testcase
		scanf("%u %u\n",&a,&b);
		p = malloc(a*sizeof(double));
		ptot = 1;
		for(j=0; j<a; j++) {
			scanf("%lf",p+j);
			ptot *= p[j];
		}
		//The probability we get it right if we keep going is prod(p), which we've been calculating as we went in 'keep'
		//if we hit enter immediately, we type
		stop = b+2;
		//if we try to finish, the expected number of keys is 
		keep = (b-a+1)*ptot + (b-a+b+2)*(1-ptot);
		//fprintf(stderr,"\tkeep:%f\tstop:%f\n",keep,stop);
		for (j=1; j<a; j++) {
			//For each time we hit backspace, we increase our expectation by 2 keystrokes (backspace plus re-type to get to the current point)
			// and decrease it by whatever the effect of changing p[j]->1 is.
			ptot /= p[a-j];
			back_c = (b-a+1)*ptot + (b-a+b+2)*(1-ptot)+2*j;
			//fprintf(stderr,"\tbackspace %u:%f\n",j,back_c);
			if(back_c<keep) { keep = back_c; }
		}
		if (stop<keep) {
			keep = stop;
		}
		
		printf("Case #%u: %f\n",i,keep);

		free(p);
	}
	return 0;
}