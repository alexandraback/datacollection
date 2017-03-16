#include <stdio.h>

#define N 111

int n, m;
int map[N][N];
int resultMap[N][N];
int rowMax[N];
int columnMax[N];

FILE *fin = fopen( "input.txt", "r" );
FILE *fout = fopen( "output.txt", "w" );

void input();
void process();
void output(int t);

int main()
{
	int i, T;

	fscanf( fin, "%d", &T );

	for ( i=0; i<T; i++ )
	{
		input();
		process();
		output( i );
	}
	return 0;
}

void input()
{
	int i, j;
	fscanf( fin, "%d%d", &n, &m );

	for ( i=0; i<n; i++ )
	{
		for ( j=0; j<m; j++ )
		{
			fscanf( fin, "%d", &map[i][j] );
		}
	}
}
void process()
{
	int i, j, max;
	for ( i=0; i<n; i++ )
	{
		max = 0;
		for ( j=0; j<m; j++ )
		{
			if ( map[i][j] > max ) max = map[i][j];
		}
		rowMax[i] = max;
	}
	for ( i=0; i<m; i++ )
	{
		max = 0;
		for ( j=0; j<n; j++ )
		{
			if ( map[j][i] > max ) max = map[j][i];
		}
		columnMax[i] = max;
	}

	for ( i=0; i<n; i++ )
	{
		for ( j=0; j<m; j++ )
		{
			resultMap[i][j] = 100;
		}
	}

	for ( i=0; i<n; i++ )
	{
		for ( j=0; j<m; j++ )
		{
			if ( resultMap[i][j] > rowMax[i] ) resultMap[i][j] = rowMax[i];
		}
	}

	for ( i=0; i<m; i++ )
	{
		for ( j=0; j<n; j++ )
		{
			if (resultMap[j][i] > columnMax[i] ) resultMap[j][i] = columnMax[i];
		}
	}

}
void output(int t)
{
	int i, j, resultFlag;
	fprintf( fout, "Case #%d: ", t+1 );

	resultFlag = true;
	for ( i=0; i<n; i++ )
	{
		for ( j=0; j<m; j++ )
		{
			if ( map[i][j] != resultMap[i][j] )
			{
				resultFlag = false;
				break;
			}
		}
		if ( !resultFlag ) break;
	}

	if ( resultFlag )
	{
		fprintf( fout, "YES\n");
	}
	else
	{
		fprintf( fout, "NO\n");
	}
}