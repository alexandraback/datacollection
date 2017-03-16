#include <iostream>
#include <set>

using namespace std;

int main()
{
  long long int T;
  cin >> T;

  for( long long int t = 1; t <= T; t++ )
  {
	cout << "Case #" << t << ": ";
	long long int base;
	cin >> base;
	if ( base > 0 )
	{
	  set<long long int> s;
	  long long int n = base;
	  while ( s.size() < 10 )
	  {
		long long int tmp = n;
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
