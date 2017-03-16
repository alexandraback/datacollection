#include <stdio.h>

int coins[30];

int test(int k,int j)
{
	if(k==0)
		return 1;

	else if(j<1)
		return 0;

	else
		return test(k-coins[j-1],j-1) || test(k,j-1);
}
int main(void)
{
	int t,c,d,v;
	int i,j,k,l;
	FILE* in=fopen("C-small-attempt3.in","r");
	FILE* out=fopen("outccc.txt","w");

	fscanf(in,"%d",&t);

	for(i=1;i<=t;i++)
	{
		int alpha=0;
		k=1;

		fscanf(in,"%d %d %d",&c,&d,&v);

		for(j=0;j<d;j++)
			fscanf(in,"%d",&coins[j]);
		
		for(k=1;k<=v;k++)
			if(!test(k,d+alpha))
			{
				coins[d+alpha]=k;

				alpha++;
			}

		fprintf(out,"Case #%d: %d\n",i,alpha);
	}

	fclose(in);
	fclose(out);

	return 0;
}
