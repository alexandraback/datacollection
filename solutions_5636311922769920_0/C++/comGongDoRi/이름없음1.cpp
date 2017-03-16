#include <stdio.h>

FILE* in=fopen("D-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

int main()
{
	int i,j,t,k,c,s;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(in,"%d %d %d",&k,&c,&s);
		fprintf(out,"Case #%d: ",i);
		for(j=1;j<=s;j++) fprintf(out,"%d ",j);
		fprintf(out,"\n");
	}
	
	return 0;
}
