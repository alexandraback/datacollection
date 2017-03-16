#include <iostream>

using namespace std;

int main()
{
  string line;
  getline( cin, line );
  const int T = stoi( line );
  
  for( int t = 1; t <= T; t++ )
  {
	string s;
	getline( cin, s );
	
	int sum = 1;
	char prev = s[ 0 ];
	for ( auto ch : s )
	{
	  if ( ch != prev )
	  {
		sum++;
	  }
	  prev = ch;
	}
	if ( s[ s.size() - 1 ] == '+' )
	{
	  sum--;
	}
	cout << "Case #" << t << ": " << sum << endl;
  }
}
