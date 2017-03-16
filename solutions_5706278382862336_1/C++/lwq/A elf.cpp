#include<stdio.h>
FILE *in,*out;
int main()
{
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	int tc,test;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		long long p,q,r;
		int a,o;
		fscanf(in,"%lld/%lld",&p,&q);
		bool t=false;
		r=q;
		for(a=0;a<=40;a++)
		{
			if( p%r==0 ) { t=true; break; }
			if( r%2!=0 ) break;
			r/=2;
		}
		o=-1;
		r=q;
		for(a=0;a<=40;a++)
		{
			if( p>=r ) { o=a; break; }
			r/=2;
		}
		fprintf(out,"Case #%d: ",test);
		if( p<=q && t==true ) fprintf(out,"%d",o);
		else fprintf(out,"impossible");
		fprintf(out,"\n");
	}
	return 0;
}