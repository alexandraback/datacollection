#include <stdio.h>
#include <memory.h>

#define SIZE 22222
#define CENTER SIZE/2

int maxHeight[SIZE];
int n, mX, mY;
double result;

void input();
void process();
void output( int t );
void dfs( int diamondCount, int x, int y, double probability );

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
	scanf("%d %d %d", &n, &mX, &mY );
	mX += CENTER;
}

void process()
{
	int i;
	memset ( maxHeight, 0xff, sizeof ( maxHeight ) );
	result = 0;

	dfs( 1, CENTER, maxHeight[CENTER]+1, 1 );
}

void dfs( int diamondCount, int x, int y, double probability )
{
	if ( diamondCount > n ) return;
	int tempA, tempB, tempC;
	bool leftPossible = false;
	bool rightPossible = false;
	// left-side
	if ( maxHeight[x] <= y-1 && maxHeight[x-1] <= y-2 && maxHeight[x-2] <= y-1 )
	{
		leftPossible = true;
	}
	// right-side
	if ( maxHeight[x] <= y-1 && maxHeight[x+1] <= y-2 && maxHeight[x+2] <= y-1 )
	{
		rightPossible = true;
	}

	if ( leftPossible || rightPossible )
	{
		if ( leftPossible && rightPossible )
		{
			dfs( diamondCount, x-1, y-1, probability/2 );
			dfs( diamondCount, x+1, y-1, probability/2 );
		}
		else
		{
			if ( leftPossible )
			{
				dfs( diamondCount, x-1, y-1, probability );
			}

			if ( rightPossible )
			{
				dfs( diamondCount, x+1, y-1, probability );
			}
		}
	}
	else
	{
		if ( x == mX && y == mY )
		{
			result += probability;
			return;
		}
		else
		{
			tempA = maxHeight[x];
			tempB = maxHeight[x-1];
			tempC = maxHeight[x+1];
			maxHeight[x] = y+1;
			maxHeight[x-1] = maxHeight[x+1] = y;
			dfs( diamondCount+1, CENTER, maxHeight[CENTER]+1, probability);
			maxHeight[x] = tempA;
			maxHeight[x-1] = tempB;
			maxHeight[x+1] = tempC;
		}

	}
}
void output( int t )
{
	printf("Case #%d: %lf\n", t, result );
}