#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int T,A,N,i,j,count,motes[1000000];


int calc_num_moves( int A, int index, int N )
{
	if( index == N ) return 0;
	if( A > motes[index] ) return calc_num_moves(A+motes[index],index+1,N);
	
	int num_moves = 0;

	if( A == 1 ) num_moves = N;
	else
	{
		while( A <= motes[index] )
		{
			A<<=1;
			--A;
			++num_moves;
			}
	}

	return std::min(N-index, num_moves + calc_num_moves(A+motes[index],index+1,N) );
}

int main()
{
	FILE *input = fopen("A.in","r");
	fscanf(input,"%d",&T);

	for( i = 1; i <= T; ++i )
	{
		fscanf(input,"%d %d",&A,&N);
		for( j = 0; j < N; ++j ) fscanf(input,"%d",&motes[j]);
		qsort(motes,N,sizeof(unsigned int),compare);
		count = calc_num_moves( A, 0, N );
		printf("Case #%d: %d\n",i,count);
	}

	fclose(input);
	return 0;
}