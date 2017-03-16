#include<stdio.h>

int T;
int c;
int d,v;

int coins[111];
bool check[113];

int process()
{
	int i,j;
	int cnt = 0;
	for( i = 0; i <= v; i ++ )
		check[i] = false;
	check[0] = true;

	for( i = 0; i < d; i ++ )
	{
		for( j = v; j >=coins[i]; j -- )
			check[j] = check[j] | check[ j-coins[i] ];
	}

	for( i = 1; i <= v; i ++ )
	{
		if(!check[i])
		{
			cnt++;

			for( j = v; j >= i; j -- )
				check[j] = check[j] | check[j-i];
		}
	}

	return cnt;
}

int main()
{
	FILE *fin = fopen("input.txt","r");
	FILE *fout = fopen("output.txt","w");

	fscanf(fin,"%d",&T);

	int t;

	for( t = 1; t <= T; t ++ )
	{
		fscanf(fin,"%d %d %d",&c,&d,&v);
		for(int i = 0; i < d; i ++ )
		{
			fscanf(fin,"%d",&coins[i]);
		}

		fprintf(fout,"Case #%d: %d\n",t ,process());
	}

	return 0;
}