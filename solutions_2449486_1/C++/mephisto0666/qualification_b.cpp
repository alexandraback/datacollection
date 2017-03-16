#include "qualification_b.h"

#include <iostream>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{
	ifstream filereader;
	filereader.open( "B-large.in" );
	char output[4];

	ofstream filewriter;
	filewriter.open( "problem_b_result.txt" );

	unsigned int testcases = 0;
	unsigned int currentcase = 0;

	if( filereader.is_open() )
	{
		filereader.getline( output, 4 );
		testcases = atoi( output );

		for( currentcase = 1; currentcase <= testcases; ++ currentcase )
		{
			unsigned int height, width, cell, i = 0, j = 0;

			filereader.getline( output, 4, ' ' );
			height = atoi( output );
			
			filereader.getline( output, 4 );
			width = atoi( output );

			Garden garden( height, width );

			for( i = 0; i < height; ++i )
			{
				for( j = 0; j < width; ++j )
				{
					if( j != width - 1 )
						filereader.getline( output, 4, ' ' );
					else
						filereader.getline( output, 4 );

					cell = atoi( output );
					garden.SetCell( cell, i, j );
				}
			}
			
			bool possible = garden.IsSetupPossible();
			if( possible )
				filewriter << "Case #" << currentcase << ": YES" << endl;
			else
				filewriter << "Case #" << currentcase << ": NO" << endl;
		}
	}
	filereader.close();
	filewriter.close();

	return 0;
}