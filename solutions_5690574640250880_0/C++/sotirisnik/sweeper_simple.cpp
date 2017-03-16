#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>

#define MAXN 51
#define MAXR 5
#define MAXC 5

using namespace std;

struct state {
	int x, y;
	state( ) { };
	state( int x, int y ) : x(x), y(y) { };
};

state start, top, temp;

int tests, R, C, M, tot;
char board[MAXN][MAXN];

int dx[] = {-1,0,1,0,-1,1,1,-1};
int dy[] = {0,1,0,-1,1,1,-1,-1};

bool valid( int x, int y ) {
	if ( x < 1 || y < 1 || x > R || y > C )
		return ( false );
	return ( true );
}

bool isCandidate( int i, int j ) {
    for ( int k = 0; k < 8; ++k ) {
		if ( valid( i+dx[k], j+dy[k] ) && board[ i+dx[k] ][ j+dy[k] ] == '*' ) {
			return ( false );
		}
	}
	return ( true );
}

void print( ) {

	for ( int i = 1; i <= R; ++i ) {
		for ( int j = 1; j <= C; ++j )
			if ( board[i][j] == 'P' )
				putchar( '.' );
			else
				printf( "%c", board[i][j] );
		putchar( '\n' );
	}

}

bool isGoal( ) {

	queue <state> q;
	q.push( start );

	int cnt = 0;

	while ( !q.empty() ) {
		top = q.front();
		q.pop();

		if ( !isCandidate( top.x, top.y ) ) {
			continue;
		}

		int i = top.x;
		int j = top.y;

		for ( int k = 0; k < 8; ++k ) {
			if ( valid( i+dx[k], j+dy[k] ) && board[ i+dx[k] ][ j+dy[k] ] == '.' ) {
				board[ i+dx[k] ][ j + dy[k] ] = 'P';
				q.push( state( i+dx[k], j+dy[k] ) );
				++cnt;
			}
		}

	}
	//printf( "%d %d\n", cnt, tot );
	return ( cnt == (R*C-M-1) );

}

char A[MAXR*MAXC+1];

int main( ) {

	scanf( "%d", &tests );

	for ( int T = 1; T <= tests; ++T ) {

		scanf( "%d %d %d", &R, &C, &M );

		//printf( "%d %d %d\n", R, C, M );

		printf( "Case #%d:\n", T );

		for ( int i = 1; i <= R*C; ++i )
			A[i] = '.';
		for ( int i = 1; i <= M; ++i )
			A[i] = '*';
		A[R*C] = 'c';

		bool possible = false;

		do {

			int x = 1, y = 1;

			for ( int i = 1; i <= R*C; ++i ) {
				//printf( "%c", A[i] );
				board[x][y] = A[i];
				if ( A[i] == 'c' ) {
					start.x = x;
					start.y = y;
				}
				++y;
				if ( y > C ) {
					++x;
					y = 1;
				}
				//if ( i % C == 0 ) putchar( '\n' );
			}

			if ( isGoal( ) ) {
				print( );
				possible = true;
				break;
			}


		}while ( next_permutation( A+1, A+R*C+1 ) );

		if ( !possible ) {
			printf( "Impossible\n" );
		}

	}

	return 0;

}
