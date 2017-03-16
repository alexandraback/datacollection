#include<fstream>
#include<iostream>
#include<vector>

using namespace std;

int main ()
{
	//ifstream cin ( "input.txt" );
	//ofstream cout ( "output.txt" );
	int t;
	cin >> t;
	for ( int q = 0; q < t; ++q )
	{
		int n, s, p;
		cin >> n >> s >> p;
		vector < int > people ( n );
		for ( int i = 0; i < n; ++i )
			cin >> people [ i ];
		long long res = 0, need = 0;
		for ( int i = 0; i < n; ++i )
		{
			if ( people [ i ] == 0 )
			{
				if ( 0 >= p )
					++res;
				continue;
			}
			if ( people [ i ] == 1 )
			{
				if ( 1 >= p )
					++res;
				continue;
			}
			if ( people [ i ] == 2 )
			{
				if ( 1 >= p )
					++res;
				else
					if ( 2 >= p )
						++need;
				continue;
			}
			if ( people [ i ] % 3 == 0 )
				if ( people [ i ] / 3 >= p )
					++res;
				else
					if ( people [ i ] / 3 + 1 >= p )
						++need;
			if ( people [ i ] % 3 == 1 )
				if ( ( people [ i ] - 1 ) / 3 + 1 >= p )
					++res;
			if ( people [ i ] % 3 == 2 )
				if ( ( people [ i ] - 2 ) / 3 + 1 >= p )
					++res;
				else
					if ( ( people [ i ] - 2 ) / 3 + 2 >= p )
						++need;
		}
		res += min ( need, ( long long ) s );
		cout << "Case #" << q + 1 << ": " << res << endl;
	}
}