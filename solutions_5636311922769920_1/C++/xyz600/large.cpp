#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int lli;

lli my_pow( lli base, lli index )
{
  if ( index == 0 ) return 1;
  else return my_pow( base, index - 1 ) * base;
}

lli get_index( lli K, lli C, vector<int> &indices )
{
  lli ans = 0;
  for( lli i = 0; i < C; i++ )
  {
	ans += my_pow( K, C - 1 - i ) * indices[ i ];
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;
  for( int t = 1; t <= T; t++ )
  {
	lli K, C, S;
	cin >> K >> C >> S;
	if ( K == 1 )
	{
	  cout << "Case #" << t << ": 1" << endl;
	}
	else
	{
	  cout << "Case #" << t << ":";
	  const lli lim = ( K + C - 1 ) / C;
	  if ( lim <= S )
	  {
		for ( lli i = 0; i < lim; i++ )
		{
		  vector<int> indices;
		  for ( lli j = 0; j < C; j++ )
		  {
			indices.push_back( min( K - 1, i * C + j ) );
		  }
		  cout << " " << get_index( K, C, indices ) + 1;
		}
		cout << endl;
	  }
	  else
	  {
		cout << " IMPOSSIBLE" << endl;
	  }
	}
  }
}
