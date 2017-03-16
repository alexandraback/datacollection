/* 
 * Problem: Ominous Omino
 * author: aravinds007@gmail.com
 *
 */


#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>

using namespace std;

int main( void )
{
	fstream inputfile_fsp;
	fstream outputfile_fsp;
	int domino_i;
	int row_i;
	int col_i;
	int tcases_i;
	int RichardWin = 0;
	
	inputfile_fsp.open( "D-small-attempt0.in", ios::in );
	outputfile_fsp.open( "D-small-attempt0.out", ios::out );
	
	inputfile_fsp >> tcases_i;
	
	for( int i = 0; i < tcases_i; i++ )
	{
		inputfile_fsp >> domino_i >> row_i >> col_i;
	
		switch (domino_i)
		{
			case 1:
				// Gabriel wins
				RichardWin = 0; 
				break;
				
			case 2:
				if( (row_i*col_i)%2 == 0 )
				{
					//Gabriel wins
					RichardWin = 0; 
				}
				else
				{
					// Richard wins
					RichardWin = 1; 
				}
				break;
				
			case 3:
				if( (row_i*col_i)%3 == 0 )
				{
					if( (row_i == 1) || (col_i == 1) )
					{
						// Richard wins
						RichardWin = 1; 
					}
					else
					{
						// Gabriel wins
						RichardWin = 0; 
					}
				}
				else
				{
					// Richard wins
					RichardWin = 1; 
				}
				break;
				
			case 4:
				if( (row_i*col_i)%4 == 0 )
				{
					if( (row_i <= 2) || (col_i <= 2) )
					{
						// Richard wins
						RichardWin = 1; 
					}
					else
					{
						// Gabriel wins
						RichardWin = 0; 
					}
				}
				else
				{
					// Richard wins
					RichardWin = 1; 
				}
				break;
		}
		if( RichardWin == 1 )
		{
			outputfile_fsp << "Case #" << i+1 << ": RICHARD" << endl;
		}
		else
		{
			outputfile_fsp << "Case #" << i+1 << ": GABRIEL" << endl;
		}
	}
	
}