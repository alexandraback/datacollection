#include "stdio.h"
#include "iostream"


int main()
{
	FILE * finp;
	FILE * foutp;

	int t,n,an,ab;
	int a,b,c;
	int temp;

	finp=fopen("1.in","r");
	foutp=fopen("1.out","w");

	fscanf(finp,"%d",&t);

	for(int i=0;i<t;i++)
	{
		an=0;ab=1;
		fscanf(finp,"%d %d %d",&a,&b,&c);
		for(int j=0;j<a;j++)
			for(int k=0;k<b;k++)
			{
				temp=j&k;
				if(temp<c)an++;
			}

		if(ab) fprintf(foutp,"Case #%d: %d\n",i+1,an);
		else fprintf(foutp,"Case #%d: \n",i+1);
	}

	fclose(finp);
	fclose(foutp);

	return 0;
}
