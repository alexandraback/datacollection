#include <stdio.h>

FILE* in=fopen("A-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

void solve()
{
	char A[1001];
	char front[1001];
	char back[1001];
	int i,a=0,b=0;
	fscanf(in,"%s",A);
	front[a++]=A[0];
	for(i=1;A[i];i++)
	{
		if(front[a-1]>A[i]) back[b++]=A[i];
		else front[a++]=A[i];
	}
	for(i=a;i--;) fprintf(out,"%c",front[i]);
	for(i=0;i<b;i++) fprintf(out,"%c",back[i]);
	fprintf(out,"\n");
	return;
}

int main()
{
	int i,t;
	fscanf(in,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fprintf(out,"Case #%d: ",i);
		solve();
	}
	return 0;
}
