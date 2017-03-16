#include "qualification_a.h"

#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{
	ifstream filereader;
	filereader.open( "A-large.in" );
	char output[8];

	ofstream filewriter;
	filewriter.open( "problem_a_result.txt" );

	unsigned int testcases = 0;
	unsigned int currentcase = 0;

	if( filereader.is_open() )
	{
		filereader.eof();
		filereader >> output;
		testcases = atoi( output );

		TicTacToeTomek tic;

		for( currentcase = 1; currentcase <= testcases; ++ currentcase )
		{
			tic.Clear();

			for( unsigned int i = 0; i < 4; ++i )
			{
				filereader.eof();
				filereader >> output;
				tic.AddLine( i, output[0], output[1], output[2], output[3] );
			}

			filewriter << "Case #" << currentcase << ": " << tic.GetResult() << endl;

			if( currentcase != testcases )
				filereader.eof();
		}
	}
	filereader.close();
	filewriter.close();

	return 0;
}