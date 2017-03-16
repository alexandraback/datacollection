#include "qualification_c.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

bool IsPalindrome( double number )
{
	std::string strnumber;
	std::stringstream strstream;
	strstream << setprecision( 15 ) << number;
	strstream >> strnumber;

	unsigned int strlength = strnumber.length();
	for( unsigned int i = 0; i < strlength / 2; ++i )
	{
		if( strnumber.at( i ) != strnumber.at( strlength - 1 - i ) )
			return false;
	}
	return true;
}

int main( int argc, char* argv[] )
{
	double max = 100000000000000;
	vector<double> fairandsquares;

	for( double d = 1; d < max; ++d )
	{
		if( IsPalindrome( d ) )
		{
			double square = pow( d, (int)2 );
			if( square > max )
				d = max;
			else if( IsPalindrome( square ) )
				fairandsquares.push_back( square );
		}
	}


	ifstream filereader;
	filereader.open( "C-large-1.in" );
	char output[101];

	ofstream filewriter;
	filewriter.open( "problem_c_result.txt" );

	unsigned int testcases = 0;
	unsigned int currentcase = 0;

	if( filereader.is_open() )
	{
		filereader.getline( output, 6 );
		testcases = atoi( output );

		for( currentcase = 1; currentcase <= testcases; ++ currentcase )
		{
			double minvalue, maxvalue;
			filereader.getline( output, 101, ' ' );
			minvalue = atof( output );
			
			filereader.getline( output, 101 );
			maxvalue = atof( output );

			unsigned int count = 0;
			for( unsigned int i = 0; i < fairandsquares.size(); ++i )
			{
				if( fairandsquares[i] >= minvalue && fairandsquares[i] <= maxvalue )
					++count;
			}

			filewriter << "Case #" << currentcase << ": " << count << endl;
		}
	}
	filereader.close();
	filewriter.close();

	return 0;
}