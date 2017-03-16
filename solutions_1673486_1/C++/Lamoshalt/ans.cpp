#include <stdio.h>

double calKeystroke(double *p, int length, int type, int backspace);

void main()
{
	FILE *in, *out;
	int T, A, B;
	double p[100000];
	int n,i;
	double prob, value, temp;

	in = fopen("A-small-attempt0.IN","r");
	out = fopen("A-small-attempt0.OUT","w");

	fscanf(in,"%d",&T);

	for(n=1;n<=T;n++) {

		fscanf(in,"%d %d",&A,&B);
		
		prob = 1;
		for(i=0; i<A; i++) {
			fscanf(in,"%lf",&p[i]);
			prob *= p[i];
		}
		
		value = B+2;

		for(i=0; i<A; i++) {
			
			temp = calKeystroke(p, B, A, i);

			if( value > temp )
				value = temp;
		}

		fprintf(out,"Case #%d: %lf\n",n,value);
	}
}

double calKeystroke(double *p, int length, int type, int backspace)
{
	int i,right, wrong;
	double prob;

	right = backspace + ( length - (type-backspace)) + 1;
	wrong = right + length + 1;

	prob = 1;
	for(i=0; i<type-backspace; i++) {
		prob *= p[i];
	}

	return prob*right + (1-prob)*wrong;	
}