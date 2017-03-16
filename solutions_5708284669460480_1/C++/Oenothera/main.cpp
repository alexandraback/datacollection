#include<stdio.h>

int T;
int K,L,S;

char key[111];
char target[111];

int alpha[30];

int pow(int x, int n){

	if(n == 0) return 1;
	if(n == 1) return x;

	int result = pow(x,n/2);
	result *= result;

	if(n%2)
		result *= x;
	return result;
}

int main()
{
	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");

	double prob = 0;
	double max = 0;
	int fail;

	fscanf(fin,"%d",&T);

	int t;

	for( t = 1; t<=T; t++ )
	{
		fscanf(fin,"%d %d %d ",&K ,&L ,&S );
		fscanf(fin,"%s %s ",key ,target );

		fail = L;
		max = 0;

		int i,j;

		for( i = 1; i < L; i ++ )
		{
			for( j = 0; i+j < L; j ++ )
			{
				if(target[i+j]!=target[j]) break;
				if( i+j == L-1 )
					fail = i;
			}
			if(fail != L) break;
		}

		max = 1+((int)(S-L)/fail);

		for( i = 0; i < 30; i ++ )
			alpha[i] = 0;
		
		for( i = 0; i < K; i ++ )
		{
			alpha[key[i]-'A']++;
		}
		prob = S-L+1;

		for( i = 0; i < L; i ++ )
		{
			prob = prob * (double)alpha[target[i]-'A'] / K;
		}
		if(prob == 0)
			max = 0;

		fprintf(fout,"Case #%d: %lf\n",t,max-prob);
	}

	return 0;
}