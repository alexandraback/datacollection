#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define N 400

long int Lenth(long int A)
{
	return((long int)(log(A)/log(2)+1));
}



int main()
{
    long int P,Q,nP,nQ,k,Nsam,i,j;
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
	fscanf(fp1,"%ld",&Nsam);
	for(k=0;k<Nsam;k++)
	{
		fscanf(fp1,"%ld",&P);
		a=fgetc(fp1);
		fscanf(fp1,"%ld",&Q);
		j=Q;
		nQ=Lenth(j);
		for(i=1;i<=nQ;i++)
		{
			if(j%2==0)
				j /=2;
			else
				break;
		}
		if(P%j!=0)
		{
			fprintf(fp2,"Case #%ld: impossible\n",k+1);
		}
		else
		{
			P /=j;
			Q /=j;
			nP=Lenth(P);
			nQ=Lenth(Q);
			fprintf(fp2,"Case #%ld: %ld\n",k+1,nQ-nP);
		}
	}
	getchar();

		
}