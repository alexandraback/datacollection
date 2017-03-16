#include<stdio.h>

int main()
{
	int nscores[200];
	int ntest,ncontestant;
	int sum=0,i,j;
	int vn,vsum;
	float factor,vfactor;
	//float nresult[50][200];
	scanf("%d",&ntest);
	for(i=0;i<ntest;i++)
	{
		sum=0;
		scanf("%d",&ncontestant);
		for(j=0;j<ncontestant;j++)
		{
			scanf("%d",&nscores[j]);
			sum+=nscores[j];
		}
		factor = (2.0*sum)/ncontestant;
		printf("Case #%d: ",i+1);
		vn=0;
		vsum=0;
		for(j=0;j<ncontestant;j++)
		{
			if((int)factor<nscores[j])
			{
				vn++;
				vsum+=nscores[j];	
			}
		}
		vfactor = ((2.0*sum)-vsum)/(ncontestant-vn);
		for(j=0;j<ncontestant;j++)
		{
			if((int)factor<nscores[j])
				printf("%f ",0.0);
			else
				printf("%f ",((vfactor-nscores[j])/(float)sum)*100);
			//nresult[i][j]=(sum-nscores[j])/(float)sum;
		}		
		printf("\n");
	}
	//for(i=0;i<ntest;i++)
	//{
	//	printf("Case #%d: ",
	//}
}
