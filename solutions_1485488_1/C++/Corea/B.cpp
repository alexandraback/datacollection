#include <stdio.h>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[ 4 ] = { 0, 1, 0, -1 };
const int dy[ 4 ] = { 1, 0, -1, 0 };

int H, N, M;

int UP[ 103 ][ 103 ];
int DOWN[ 103 ][ 103 ];
int table[ 103 ][ 103 ];

priority_queue< pair<int, pair<int, int> > > pq;

void back( int x, int y ) 
{
	pq.push( make_pair( H, make_pair( x, y ) ) );
	table[ x ][ y ] = H;

	for( int i = 0; i < 4; i ++ ) 
	{
		int px, py;
		px = x + dx[ i ];
		py = y + dy[ i ];
		if( px <= 0 || py <= 0 || px > N || py > M ) continue;
		if( table[ px ][ py ] == H ) continue; 
		if( UP[ px ][ py ] - 50 < DOWN[ px ][ py ] ) continue;
		if( UP[ px ][ py ] - 50 < DOWN[ x ][ y ] ) continue;
		if( UP[ x ][ y ] - 50 < DOWN[ px ][ py ] ) continue;
		if( UP[ px ][ py ] - 50 < H ) continue;
		back( px, py );
	}
}
void process( ) 
{
	pair< int, pair< int, int > > now;

	while( !pq.empty() ) pq.pop();

	back( 1, 1 );

	while( !pq.empty() ) 
	{
		now = pq.top();
		pq.pop();
		if( now.second.first == N && now.second.second == M ) 
		{
			printf( "%d.%d\n", (H - now.first)/10, (H - now.first) % 10 );
			break;
		}

		for( int i = 0; i < 4; i ++ ) 
		{
			int px, py;

			px = now.second.first + dx[ i ];
			py = now.second.second + dy[ i ];
			if( px <= 0 || py <= 0 || px > N || py > M ) continue;
			if( table[ px ][ py ] >= now.first ) continue;
			if( UP[ px ][ py ] - 50 < DOWN[ now.second.first ][ now.second.second ] ) continue;
			if( UP[ px ][ py ] - 50 < DOWN[ px ][ py ] ) continue;
			if( UP[ now.second.first ][ now.second.second ] - 50 < DOWN[ px ][ py ] ) continue;

			int waitH = UP[ px ][ py ] - 50;
			if( waitH > UP[ now.second.first ][ now.second.second ] - 50 )
				waitH = UP[ now.second.first ][ now.second.second ] - 50;
			if( waitH > now.first ) 
				waitH = now.first;
			if( waitH >= DOWN[ now.second.first ][ now.second.second ] + 20 )
				waitH -= 10;
			else
				waitH -= 100;
			if( table[ px ][ py ] < waitH )
			{
				pq.push( make_pair( waitH, make_pair( px, py ) ) );
				table[ px ][ py ] = waitH;
			}
		}
	}
}

int main( ) 
{
	int T;
	scanf( "%d", &T );

	for( int tt = 1; tt <= T; tt ++ ) 
	{
		scanf( "%d %d %d", &H, &N, &M );
		for( int i = 1; i <= N; i ++ ) 
			for( int j = 1; j <= M; j ++ )
				scanf( "%d", &UP[ i ][ j ] );
		for( int i = 1; i <= N; i ++ ) 
			for( int j = 1; j <= M; j ++ )
			{
				scanf( "%d", &DOWN[ i ][ j ] );
				table[ i ][ j ] = -2147483600;
			}

		printf( "Case #%d: ", tt );
		process();
	}
	return 0;
}
