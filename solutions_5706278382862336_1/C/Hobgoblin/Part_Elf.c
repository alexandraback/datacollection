#include"stdio.h"

void main()
{
	FILE *fp1,*fp2;

	int t,i,j,result;
	double p,q,elf,tem;

	fp1=fopen("small.in","r");
	fp2=fopen("small.out","w");
	fscanf(fp1,"%d",&t);

	for (i=1;i<t+1;i++)
	{
		fscanf(fp1,"%lf/%lf",&p,&q);
		elf=p/q;
		tem=2;
		result=41;
		for (j=0;j<41;j++)
		{
			tem/=2;
			if (elf-tem>=0)
			{
				if (j<result) result=j;
				elf-=tem;
			}
			if (elf==0) break;
		}
		if (elf!=0) fprintf(fp2,"Case #%d: impossible\n",i);
		else fprintf(fp2,"Case #%d: %d\n",i,result);
	}


	fclose(fp1);
	fclose(fp2);

}
