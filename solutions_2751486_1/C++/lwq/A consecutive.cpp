#include<stdio.h>
#include<string.h>
typedef long long lli;
FILE *in,*out;
char i[1048577];
int main()
{
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	int tc,test;
	int k,n,c,a;
	lli p,o;
	bool v;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		fscanf(in,"%s%d",i,&k);
		n=strlen(i);
		o=0;
		p=-1;
		c=0;
		for(a=0;a<n;a++)
		{
			v=false;
			if( i[a]=='a' ) v=true;
			if( i[a]=='e' ) v=true;
			if( i[a]=='i' ) v=true;
			if( i[a]=='o' ) v=true;
			if( i[a]=='u' ) v=true;
			if( v==false ) c++;
			else c=0;
			if( c>=k ) p=a-k+1;
			o+=p+1;
		}
		fprintf(out,"Case #%d: ",test);
		fprintf(out,"%I64d",o);
		fprintf(out,"\n");
	}
	return 0;
}