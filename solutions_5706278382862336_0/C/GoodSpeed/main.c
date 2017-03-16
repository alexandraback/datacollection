#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define N 400

int Lenth(int A)
{
	return((int)(log(A)/log(2)+1));
}



int main()
{
    int P,Q,nP,nQ,k,Nsam,i,j;
	char a;
	FILE *fp1,*fp2;
	if ((fp1=fopen("in.txt", "r")) ==NULL)                                        
	{
		printf("Error opening file\n");
		exit(1); 
	}
	if ((fp2=fopen("out.txt", "w+")) ==NULL)            
    {
		printf("Error opening file\n");
		exit(1); 
    }
	fscanf(fp1,"%d",&Nsam);
	for(k=0;k<Nsam;k++)
	{
		fscanf(fp1,"%d",&P);
		a=fgetc(fp1);
		fscanf(fp1,"%d",&Q);
		j=P;
		for(i=1;i<=j;i++)
		{
			if((P%i==0)&&(Q%i==0))
			{
				P /=i;
				Q /=i;
			}
		}
		nP=Lenth(P);
		nQ=Lenth(Q);
		printf("%d,,,%d\n",P,Q);
		if(pow(2,nQ-1.0)+0.1<Q)
		{
			fprintf(fp2,"Case #%d: impossible\n",k+1);
		}
		else
		{
			fprintf(fp2,"Case #%d: %d\n",k+1,nQ-nP);
		}
	}
	getchar();

		
}