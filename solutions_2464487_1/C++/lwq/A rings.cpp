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
			 ~= i / (2r-1) - i^2 / 8(2r-1)^3 - ...
		*/
		long long s=2*r-1;
		if( r<(1LL<<32) ) fprintf(out,"%lld",(long long)((sqrtl(i*2+(long double)s*s/4)-(long double)s/2)/2));
		else
		{
			long long n=(long double)i/s-(long double)i*i/8/s/s/s;
			if( n*(2*n+2*r-1)<=i ) fprintf(out,"%lld",n);
			else fprintf(out,"%lld",n-1);
		}
		fprintf(out,"\n");
	}
}