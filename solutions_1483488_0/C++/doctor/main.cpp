#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include <algorithm>

using namespace std;

// main
int doIt( int A, int B)
{
	if( B<11)
		return 0;

	int result = 0, dummy;

	// prepare
	stringstream ss;
	ss << A;

	int length = ( int)(ss.str().length() - 1);
	int mp = ( int)( pow( 10.0, length));

	map< int, int> subResult;
	for( int i = A, j; i<=B; i++)
	{
		subResult.clear();
		// rotate it
		for( j = 0, dummy = i; j < length; j++)
		{
			dummy = ( dummy / 10) + ( (dummy % 10) * mp);

			if( dummy < i && dummy >= A)
				subResult.insert( pair< int, int>( dummy, 0));
		}

		result += subResult.size();
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

	for( int A, B; i <= TestCases; i++)
	{
		f >> A >> B;
		f.ignore( 256, '\n');

		cout << "Case #" << i << ": " << doIt( A, B) << endl;
	}

	doIt( 12345, 12345);

	f.close();
	return 0;
}
