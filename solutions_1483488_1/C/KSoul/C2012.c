#include <stdio.h>

int main()
{
	FILE *pFile1,*pFile2;
	pFile1=fopen("C-large.in","r");
	pFile2=fopen("C-large.out","w");
	int i,j,k,l,t,a,b,ten[10],sol;
	char num[10];
	ten[0]=1;
	for(i=1;i<10;i++) ten[i]=10*ten[i-1];
	fscanf(pFile1,"%d",&t);
	for(i=0;i<t;i++)
	{
		fscanf(pFile1,"%d %d",&a,&b);
		sol=0;
		for(j=a;j<=b;j++)
		{
			int length,check[10],checkrep=0;
			sprintf(num,"%d",j);
			for(length=0;num[length]!='\0';length++);
			for(k=1;k<length;k++)
			{
				check[k]=((j%ten[k])*ten[length-k])+j/ten[k];
				if(check[k]<=b&&check[k]>=a&&check[k]>j)
				{
					for(l=1;l<k;l++) if(check[k]==check[l]) checkrep=1;
					if(checkrep==0)	sol++;
				}
				
			}
		}
		fprintf(pFile2,"Case #%d: %d\n",i+1,sol);
	}
    return 0;
}
