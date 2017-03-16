#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

array<int, 1001> visited;
array<int, 1001> bff;
int N;

void rec2( const int cur, const int depth, int &max_circle )
{
  visited[ cur ]++;
  for ( int i = 0; i < N; i++ )
  {
	if ( !visited[ i ] && bff[ i ] == cur )
	{
	  max_circle = max( max_circle, depth );
	  rec2( i, depth + 1, max_circle );
	}
  }  
  visited[ cur ]--;
}

void rec( const int cur, const int depth, int &max_circle, const int left, const int right )
{
  if ( !visited[ cur ] )
  {
	visited[ cur ]++;
	if ( bff[ cur ] == left )
	{
	  max_circle = max( max_circle, depth );
	}
	else if ( bff[ cur ] == right )
	{
	  int add_depth = 0;
	  rec2( cur, 1, add_depth );
	  max_circle = max( max_circle, depth + add_depth );
	}
	else if ( !visited[ bff[ cur ] ] )
	{
	  rec( bff[ cur ], depth + 1, max_circle, left, cur );
	}
	visited[ cur ]--;
  }
}

int main()
{
  int T;
  cin >> T;

  for ( int t = 1; t <= T; t++ )
  {
	cin >> N;
	for( int i = 0; i < N; i++ )
	{
	  cin >> bff[ i ];
	  bff[ i ]--;
	}
	
	int max_circle = 0;
	for ( int i = 0; i < N; i++ )
	{
	  fill( visited.begin(), visited.end(), false );
	  rec( i, 1, max_circle, i, -1 );
	}
	cout << "Case #" << t << ": " << max_circle << endl;
	
  }
}
