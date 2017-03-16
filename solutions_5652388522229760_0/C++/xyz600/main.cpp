#include <iostream>
#include <set>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for( int t = 1; t <= T; t++ )
  {
	cout << "Case #" << t << ": ";
	int base;
	cin >> base;
	if ( base > 0 )
	{
	  set<int> s;
	  int n = base;
	  while ( s.size() < 10 )
	  {
		int tmp = n;
		while( tmp > 0 )
		{
		  s.insert( tmp % 10 );
		  tmp /= 10;
		}
		n += base;
	  }
	  cout << n - base << endl;
	}
	else
	{
	  cout << "INSOMNIA" << endl;
	}
  }
}
