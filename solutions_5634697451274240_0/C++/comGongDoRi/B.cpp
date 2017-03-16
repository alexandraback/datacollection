#include <stdio.h>

FILE* in=fopen("B-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

char P[101];

int f()
{
	char prev=P[0];
	int i,ret=0;
	for(i=0;P[i];i++)
	{
		if(P[i]!=prev) ret++;
		prev=P[i];
	}
	return ret+1-(prev=='+');
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(in,"%s",P);
		fprintf(out,"Case #%d: %d\n",i,f());
	}
	
	return 0;
}
