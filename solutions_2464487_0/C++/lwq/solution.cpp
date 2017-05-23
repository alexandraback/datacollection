#include<stdio.h>
#include<math.h>
FILE *in,*out;
int main()
{
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	int tc,test;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		long long r,i;
		fscanf(in,"%lld%lld",&r,&i);
		fprintf(out,"Case #%d: ",test);
		/*
			(2r+1)+(2r+5)+...+(4(n-1)+2r+1)
			 = n(2n+2r-1) = 2 n^2 + (2r-1) n
			2 n^2 + (2r-1) n - i = 0
			n = ( sqrt( (2r-1)^2 + 8 i ) - (2r-1) ) / 4
			 ~= i / (2r-1) - O( i/(2r-1)^3 )
		*/
		if( r<(1LL<<32) ) fprintf(out,"%lld",(long long)((sqrtl(i*8+(long double)(2*r-1)*(2*r-1))-(2*r-1))/4));
		else fprintf(out,"%lld",i/(2*r-1)-1);
		fprintf(out,"\n");
	}
}