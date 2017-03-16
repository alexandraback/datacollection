#include <stdio.h>
#include <stdlib.h>

#define N 1111111

int a, m;
int result;
int data[N];

void input();
void process();
void output(int t);

int func_qsort( const void *a, const void *b );

int main()
{
	int i, T;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

	scanf("%d", &T );

	for ( i=0; i<T; i++ )
	{
		input();
		process();
		output( i+1 );
	}
	return 0;
}

void input()
{
	int i;

	scanf("%d %d", &a, &m );

	for ( i=0; i<m; i++ )
	{
		scanf("%d", &data[i] );
	}
}
void process()
{
	int i, j, max, temp, value;
	bool isGood;

	qsort(data, m, sizeof ( data[0] ), func_qsort );

	max = a;
	value = 0;
	result = m;
	for ( i=0; i<m; i++ )
	{
		if ( data[i] < max )
		{
			max += data[i];
		}
		else
		{

			temp = max;
			isGood = false;
			for ( j=0; j<(m-i); j++ )
			{
				temp += ( temp-1 );
				if ( temp > data[i] )
				{
					isGood = true;
					break;
				}
			}

			if ( value + (m-i) <  result ){
				result = value + (m-i);
			}

			value += (j+1);
			max = temp + data[i];

			if ( !isGood ) break;

		}
	}

	if ( value < result ) result = value;
}
void output(int t)
{
	printf("Case #%d: %d\n", t, result );
}

int func_qsort( const void *a, const void *b )
{
	int p = *(int *)a;
	int q = *(int *)b;

	return p-q;
}