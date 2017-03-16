#include <stdio.h>

FILE *in=fopen("A-large.in","rt");
FILE *out=fopen("A-large.out","wt");

__int64 r,t;

void input()
{
	fscanf(in,"%I64d %I64d",&r,&t);
}

void process()
{
	__int64 n=0,mid=536870912,tmp;
	while(mid!=0)
	{
		tmp=n+mid;
		if(2*tmp+2*r-1<=t/tmp) n=tmp;
		else mid/=2;
	}
	fprintf(out,"%I64d",n);
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		input();
		process();
		fprintf(out,"\n");
	}
	return 0;
}