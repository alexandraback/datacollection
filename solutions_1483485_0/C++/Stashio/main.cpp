#include <iostream>
#include "config.h"

using namespace std;

#if QUALIFY_A

const char* const replacements = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	ifstream* ifs = openFileForInput( INPUT_FILE );
	ofstream* ofs = openFileForOutput( OUTPUT_FILE );

	if ( !ifs || !ofs )
	{
		return 0;
	}

	Cases testCases = readFile( ifs );

	for ( int i = 0; i < testCases.numTestCases; ++i )
	{
		int len = strlen( testCases.testCase[i] );
		ofs->write( "Case #", 6 );
		char tmp[12] = {0};
		itoa( i+1, tmp, 10 );
		ofs->write( tmp, strlen(tmp) );
		ofs->write( ": ", 2 );
		for ( int j = 0; j < len; ++j )
		{
			char c = testCases.testCase[i][j];
			if ( c >= 'a' && c <= 'z' )
			{
				ofs->put( replacements[c - 'a'] );
			}
			else
			{
				ofs->put( c );
			}
		}
		ofs->put( '\n' );
	}

	closeInputFile( ifs );
	closeOutputFile( ofs );
}

#endif