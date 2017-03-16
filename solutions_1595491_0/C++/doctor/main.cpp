#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include <algorithm>

using namespace std;

// main
int doIt( int N, int S, int p, string &str)
{
	int result = 0;

	// split string
	int last = 0, pos = str.find_first_of( " ", 0);
	vector< int> v;

	while( pos != string::npos || last != string::npos)
	{
		string entry = str.substr( last, pos - last);
		if( !entry.empty())
			v.push_back( atoi( entry.c_str()));

		last = str.find_first_not_of( " ", pos);
		pos = str.find_first_of( " ", last);
	}

	v.resize( N);
	sort( v.begin(), v.end(), greater< int>());

	int avg = p * 3;

	for( auto it = v.begin(); it != v.end(); ++it)
	{
		if( ( *it) == 0)
		{
			if( p == 0)
				result ++;
		}
		else
		{
			int dummy = avg - ( *it);
			if( dummy > 4)
				break;
			else if( dummy > 2)
			{
				if(S > 0)
				{
					result ++;
					S --;
				}
			}
			else
				result ++;
		}
		
//		cout << *it << ", avg: " << avg << ", dummy: " << dummy << endl;
	}

	return result;
}

int main( const int argc, const char **argv)
{
	if( argc < 2)
		return 0;

	ifstream f( argv[ 1], ifstream::in);

	// get 'T'
	size_t TestCases, i = 1;
	f >> TestCases;

	f.ignore( 256, '\n');

	for( int N, S, p; i <= TestCases; i++)
	{
		string line;

		f >> N >> S >> p;
		getline( f, line);

		cout << "Case #" << i << ": " << doIt( N, S, p, line) << endl;
	}

	f.close();
	return 0;
}
