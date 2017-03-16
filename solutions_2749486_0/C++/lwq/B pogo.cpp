#include<stdio.h>
FILE *in,*out;
int main()
{
	in=fopen("b.in","r");
	out=fopen("b.out","w");
	int tc,test;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		int m,n,a;
		fscanf(in,"%d%d",&m,&n);
		fprintf(out,"Case #%d: ",test);
		if( m>0 ) for(a=0;a<m;a++) fprintf(out,"WE");
		if( m<0 ) for(a=0;a<-m;a++) fprintf(out,"EW");
		if( n>0 ) for(a=0;a<n;a++) fprintf(out,"SN");
		if( n<0 ) for(a=0;a<-n;a++) fprintf(out,"NS");
		fprintf(out,"\n");
	}
	return 0;
}