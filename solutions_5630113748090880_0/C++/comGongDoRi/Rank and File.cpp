#include <stdio.h>
#include <algorithm>

FILE* in=fopen("B-small-attempt0.in","r");
FILE* out=fopen("out.txt","w");

void solve()
{
	int i,j,h,n;
	int H[2501]={};
	int line[50];
	fscanf(in,"%d",&n);
	for(i=0;i<2*n-1;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(in,"%d",&h);
			H[h]=1-H[h];
		}
	}
	i=j=0;
	for(i=1;i<=2500;i++) if(H[i]) line[j++]=i;
	std::sort(H,H+j);
	for(i=0;i<j;i++) fprintf(out,"%d ",line[i]);
	fprintf(out,"\n");
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
