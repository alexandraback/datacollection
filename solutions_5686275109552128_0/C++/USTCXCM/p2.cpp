using namespace std;
#include <iostream>
int main()
{
	FILE *fp1,*fp2;
	if((fp1=fopen("B-small-attempt0.in","r"))==NULL)
	{
		printf("Cannot open this file\n");
		exit(0);
	}
	fp2=fopen("B-small-attempt0.out","w");
	int n,d,*p,h,i,j,max=0,high,special,step,temp;
	fscanf(fp1,"%d\n",&n);
	for(h=0;h<n;h++)
	{
	fscanf(fp1,"%d\n",&d);
	p=new int[d];
	for(i=0;i<d;i++)
		fscanf(fp1,"%d",&p[i]);
	for(i=0;i<d;i++)
		if(p[i]>max)
			max=p[i];
	step=max;
	for(high=max;high>0;high--)
	{
		special=0;
		for(i=0;i<d;i++)
		{
			if(p[i]>high)
			{
				special+=p[i]/high;
				if(p[i]%high==0)
					special--;
			}
		}
		if(high+special<step)
			step=high+special;
	}
	printf("Case #%d: %d\n",h+1,step);
	fprintf(fp2,"Case #%d: %d\n",h+1,step);
	}
	fclose(fp2);

	getchar();
	getchar();
	return 0;
}