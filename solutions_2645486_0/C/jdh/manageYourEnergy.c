#include <stdio.h>
#include <stdlib.h>

int sol1(int E, int R, int e, int t, int n, int idx, int *v)
{
	if(idx>=n)
		return t;
	int sol=t;
	for(int i=0;i<=e;++i)
	{
		int ne=e-i+R;
		if(ne>E)
		{
			ne=E;
		}
		int nt=t+i*v[idx];
		int nsol=sol1(E,R,ne,nt,n,idx+1,v);
		if(sol<nsol)
		{
			sol=nsol;
		}
		//printf("%d %d %d %d nsol %d\n",E,R,ne,nt,sol);
	}
	return sol;
}

int sol(int E, int R, int n, int *v)
{
	printf("here\n");
	int e=E;
	int t=0;
	int sol=0;
	if(n==0)
	{
		printf("n==0\n");
		return 0;
	}
	if(E<=0)
	{
		printf("E<=0\n");
		return 0;
	}
	if(n==1)
	{
		printf("n==1\n");
		return E*v[0];
	}
	for(int i=0;i<=E;++i)
	{
		int ne=E-i+R;
		if(ne>E)
		{
			ne=E;
		}
		int nt=t+i*v[0];
		int nsol=sol1(E,R,ne,nt,n,1,v);
		//printf("%d %d %d %d nsol %d\n",E,R,ne,nt,nsol);
		if(sol<nsol)
			sol=nsol;
	}
	printf("sol %d\n",sol);
	return sol;
}

int main()
{
	FILE *pInput,*pOutput;
	pInput=fopen("input.txt","r");
	pOutput=fopen("output.txt","w+");
	int nbCase;
	fscanf(pInput,"%d",&nbCase);
	printf("nbCase : %d\n",nbCase);
	for(int i=0;i<nbCase;++i)
	{
		int E,R,n;
		fscanf(pInput,"%d",&E);
		fscanf(pInput,"%d",&R);
		fscanf(pInput,"%d\n",&n);
		printf("E : %d, R : %d, n : %d\n",E,R,n);
		int *values=(int *)calloc(n,sizeof(int));
		for(int j=0;j<n;++j)
		{
			int d;
			fscanf(pInput,"%d",&d);
			printf("%d ",d);
			values[j]=d;
		}
		fscanf(pInput,"\n");
		printf("\n");
		int ret=sol(E,R,n,values);
		fprintf(pOutput,"Case #%d: %d\n",(i+1),(ret));
		printf("Case #%d: %d\n",(i+1),(ret));
	}
	return 0;
}