#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

int table[ 1000 ];

// heuristic
void update1( array<int, 3> &state, const int J, const int P, const int S )
{
  // cout << J << ", " << P << ", " << S << endl;
  state[ 1 ]++;
  if ( state[ 1 ] == P + 1 )
  {
	state[ 1 ] = 1;
	state[ 0 ]++;
  }
  if ( state[ 0 ] == J + 1 )
  {
	state[ 0 ] = 1;
  }
  state[ 2 ] = table[ state[ 0 ] * P + state[ 1 ] ];
}

// perumutation
void update2( array<int, 3> &state, const int J, const int P, const int S )
{
  state[ 2 ]++;
  if ( state[ 2 ] == S + 1 )
  {
	state[ 2 ] = 1;
	state[ 1 ]++;
  }
  
  if ( state[ 1 ] == P + 1 )
  {
	state[ 1 ] = 1;
	state[ 0 ]++;
  }
  if ( state[ 0 ] == J + 1 )
  {
	state[ 0 ] = 1;
  }							   
}

void prepare( int J, int P )
{
  for ( int i = 0; i < J; i++ )
  {
	for ( int j = 0; j < P; j++ )
	{
	  table[ i * P + j ] = j;
	}
  }

  for ( int i = 0; i < J * P; i++ )
  {
	int y = i / P;
	int x = i % P;
	int j = i;
	while ( j < J * P && table[ j ] != y && table[ j ] != x )
	{
	  j++;
	}
	swap( table[ i ], table[ j ] );
  }  
}

int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; t++ )
  {
	int J, P, S, K;
	cin >> J >> P >> S >> K;
	const int ans = J * P * min( S, K );
	cout << "Case #" << t << ": " << ans << endl;
	
	array<int, 3> state{ 1, 1, 1 };
	if ( S > K ) // k回発動
	{
	  prepare( J, P );
	  
	  for ( int i = 0; i < ans; i++ )
	  {
		cout << state[ 0 ] << " " << state[ 1 ] << " " << state[ 2 ] << endl;
		update1( state, J, P, S );
	  }
	} else {
	  for ( int i = 0; i < ans; i++ ) // permutation
	  {
		cout << state[ 0 ] << " " << state[ 1 ] << " " << state[ 2 ] << endl;
		update2( state, J, P, S );
	  }
	}
  }
}
