#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;

FILE* fin;
FILE* fout;

long* vals = new long[2000001];

int test(int n, int min)
{
	if(n<10)
	return 0;
	int i=0;
	int w=n;
	int pwr=1;
	int digs[7]={0,0,0,0,0,0,0};
	while(w>0)
	{
		digs[i]=w%10;
		w/=10;
		i++;
		pwr*=10;
	}
	pwr/=10;
	int N[7];
	for(int j=0; j<i; j++)
	{
		N[j]=n;
		n=n/10+(n%10)*pwr;
	}
	int ncomp=0;
	for(int j=1; j<i; j++)
	{
		if(N[j]<min)
			continue;
		bool unique=true;
		for(int k=0; k<j; k++)
			unique&=(N[j]!=N[k]);
		if(unique && N[j]!=N[0] && N[j]<N[0] && digs[(i+j-1)%i]!=0){ ncomp++;}
	}
	return ncomp;
		
}

int main(void)
{
	fin = fopen("Csmall.in", "r");
	fout = fopen("Csmall.out", "w");
	vals[0]=0;
	/*int i=0;
	while(true)
	{
		printf("%d %ld", i, vals[i]);
		i++;
		getchar();
	}*/
	int T;
	fscanf(fin, "%d", &T);
	printf("%d", T);
	for(int t=1; t<=T; t++)
	{
		int A, B;
		fscanf(fin, "%d %d", &A, &B);
		long long V=0;
		for(int i=1; i<=B; i++)
			V+=test(i, A);
		fprintf(fout, "Case #%d: %lld\n", t, V);
				
	}
	return 0;
}
