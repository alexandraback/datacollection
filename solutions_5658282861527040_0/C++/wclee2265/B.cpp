#include <stdio.h>

FILE *in=fopen("B-small-attempt0.in","rt");
FILE *out=fopen("B-small-attempt0.out","wt");

int A,B,K;
int sum;

void input()
{
	fscanf(in,"%d %d %d",&A,&B,&K);
}

void process()
{
	sum=0;
	for(int i=0; i<A; i++) {
		for(int j=0; j<B; j++) sum+=((i&j)<K);
	}
}

int main()
{
	int t;
	fscanf(in,"%d",&t);
	for(int i=1; i<=t; i++) {
		fprintf(out,"Case #%d: ",i);
		input();
		process();
		fprintf(out,"%d\n",sum);
	}
	fclose(in);
	fclose(out);
	return 0;
}