#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <memory.h>

double C, F, X;

void Read()
{
	scanf( "%lf%lf%lf", &C, &F, &X );
}

double Work()
{
	double best = X / 2;

	double time = 0;
	double farm = 2;
	while( true )
	{
		time += C / farm;
		farm += F;
		double curr = time + X / farm;
		if( best <= curr )
			break;
		best = curr;
	}
	return best;
}

void Write( int test, double result )
{
	printf( "Case #%d: %.7lf\n", test, result );
}

int main()
{
	int i, t;
	scanf( "%d", &t );
	for( i = 0; i < t; ++i )
	{
		Read();
		Write( i + 1, Work() );
	}
	return 0;
}
