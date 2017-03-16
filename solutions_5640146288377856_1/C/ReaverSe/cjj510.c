#include <stdio.h>

int main(void)
{
	int t,r,c,w,i;
	FILE *in=fopen("A-large.in","r");
	FILE *out=fopen("510A2.txt","w");

	fscanf(in,"%d",&t);

	for(i=1;i<=t;i++)
	{
		fscanf(in,"%d %d %d",&r,&c,&w);
		
		fprintf(out,"Case #%d: %d\n",i,r*((c/w)+w-(c%w==0)));
	}

	fclose(in);
	fclose(out);

	return 0;
}
