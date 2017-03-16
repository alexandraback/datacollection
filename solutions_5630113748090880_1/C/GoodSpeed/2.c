#include<stdio.h>
#include<memory.h>
#include<math.h>

#define Tmax 50
#define Hmax 2501
#define Nmax 50

int hash[Hmax];

int main()
{
	int T,N,k,a,i,count;
	FILE *fin,*fout;
	fin = fopen("B-large.in","r");
	if(fin == NULL)
	{
		printf("Cannot open the file!\n");
		return(0);
	}
	fout = fopen("output.txt","w");
	if(fout == NULL)
	{
		printf("Cannot open the file!\n");
		return(0);
	}
	fscanf(fin,"%d",&T);
	for(k=1;k<=T;k++)
	{
		fscanf(fin,"%d",&N);
		fprintf(fout,"Case #%d:",k);
		memset(hash,0,sizeof(hash));
		for(i=0;i<(2*N-1)*N;i++)
		{
			fscanf(fin,"%d",&a);
			hash[a]++;
		}
		for(i=1,count=0;i<Hmax;i++)
		{
			if(hash[i]%2==1)
			{				
				printf("%d",i);
				fprintf(fout," %d",i);
				if(count!=N-1)	printf(" ");
				else printf("\n");
				count++;
			}
		}
		fprintf(fout,"\n");
		printf("\n\nIloveHyojung!%d=%d\n\n",N,count);
	}
	fclose(fin);
	fclose(fout);
	
}
