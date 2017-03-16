#include <iostream>
#include <cmath>

using namespace std;

typedef long long int lli;

lli my_pow( lli base, lli index )
{
  if ( index == 0 ) return 1;
  else return my_pow( base, index - 1 ) * base;
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
	  lli d = ( my_pow( K, C ) - 1 ) / ( K - 1 );
	  cout << "Case #" << t << ":";
	  for ( lli i = 0; i < S; i++ )
	  {
		cout << " " << i * d + 1;
	  }
	  cout << endl;
	}
  }
}
