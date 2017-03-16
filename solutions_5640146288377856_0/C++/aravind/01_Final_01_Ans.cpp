#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main( void )
{
	fstream inputfile_fsp;
	fstream outputfile_fsp;
	
	int tcases_i;
	int row_i;
	int col_i;
	int remcol_i;
	int anyremain_i;
	int shiplen_i;
	int factor_i;
	int hits_i;


	//inputfile_fsp.open( "A-small-attempt0.in", ios::in );
	//outputfile_fsp.open( "A-small-attempt0.out", ios::out );
	
	inputfile_fsp.open( "A-small-attempt1.in", ios::in );
	outputfile_fsp.open( "A-small-attempt1.out", ios::out );
	
	
	inputfile_fsp >> tcases_i;
	
	for( int i = 0; i < tcases_i; i++ )
	{
		inputfile_fsp >> row_i >> col_i >> shiplen_i;
		
		if( col_i == shiplen_i )
		{
			hits_i = shiplen_i;
		}
		else
		{
			remcol_i = col_i - shiplen_i;
			factor_i = remcol_i / shiplen_i;
			if( (remcol_i % shiplen_i) != 0)
				factor_i++;; 
			hits_i = factor_i + shiplen_i;
		}
		
		cout << "Case #" << i+1 << ": " << hits_i <<  endl;
		outputfile_fsp << "Case #" << i+1 << ": " << hits_i <<  endl;
	}
}
