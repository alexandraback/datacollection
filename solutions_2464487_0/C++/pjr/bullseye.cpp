#include <stdio.h>
#define LLDMAX 8999999999999999999

long long int r, t;
long long int result;

FILE *fin = fopen ( "input.txt", "r" );
FILE *fout = fopen ( "output.txt", "w" );

void input();
void process();
void output( int T );

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
	fscanf(fin, "%lld%lld", &r, &t );
}
void process()
{
	long long int start=1, end=2000000000;
	if ( 2000000000 > LLDMAX/r ) end = LLDMAX/r;
	long long int mid;
	long long int value;

	while ( 1 )
	{
		if ( start+1 >= end )
		{
			if ( start == end )
			{
				result = start;
			}
			else
			{
				mid = start + 1;
				value = (2 * mid * r) + (2*mid*(1+mid)) - 3*mid;
				if ( value > t )
				{
					result = start;
				}
				else
				{
					result = start + 1;
				}
			}
			break;
		}
		mid = ( start + end ) / 2;
		value = (2 * mid * r) + (2*mid*(1+mid)) - 3*mid;

		if ( value > t )
		{
			end = mid-1 ;
		}
		else
		{
			start = mid;
		}

	}
}
void output( int T )
{
	fprintf( fout, "Case #%d: %lld\n", T, result );
}