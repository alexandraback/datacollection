#include <stdio.h>

#define N 111

int e, r, n;
int data[N];
int result;

FILE *fin = fopen ( "input.txt", "r" );
FILE *fout = fopen ( "output.txt", "w" );

void input();
void process();
void output(int T );

int main()
{
	int i, T;
	
	fscanf( fin, "%d", &T );

	for ( i=0; i<T; i++ )
	{
		input();
		process();
		output( i+1 );
	}
}

void input()
{
	int i;

	fscanf( fin, "%d%d%d", &e, &r, &n );

	for ( i=0; i<n; i++ )
	{
		fscanf( fin, "%d", &data[i] );
	}
}
void process()
{
	int currentEnergy = e;

	int i, j;
	int willUsed;

	result = 0;
	for ( i=0; i<n; i++ )
	{
		for ( j=i+1; j<n; j++ )
		{
			if ( data[i] >= data[j] )
			{
			}
			else
			{
				break;
			}
		}

		if ( j == n )
		{
			willUsed = currentEnergy;
		}
		else
		{
			willUsed = currentEnergy + (j-i)*r - e;
			if ( willUsed > currentEnergy ) willUsed = currentEnergy;
			if ( willUsed < 0 ) willUsed = 0;
		}

		result += willUsed*data[i];
		currentEnergy -= willUsed;
		currentEnergy += r;

	}
}
void output(int T )
{
	fprintf( fout, "Case #%d: %d\n", T, result );
}