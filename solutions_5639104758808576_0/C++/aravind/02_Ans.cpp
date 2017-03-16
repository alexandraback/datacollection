 
/* 
 * Standing ovation
 * Author: aravinds007@gmail.com 
 */

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main( void )
{
	char readChar_c;
	string presence_sz;
	int presence_ia[1005];
	int current_ia[1005];
	int neededFriends_i;
	int totalFriends_i;
	int index_i;
	int maxSlevel_i;
	int tcases_i;
	fstream inputfile_fsp;
	fstream outputfile_fsp;
	
	inputfile_fsp.open( "A-small-attempt2.in", ios::in );
	//inputfile_fsp.open( "inputfile.txt", ios::in );
	outputfile_fsp.open( "A-small-attempt2.out", ios::out );
	//outputfile_fsp.open( "outputfile.txt", ios::out );
	
	inputfile_fsp >> tcases_i;
	//cout << "Arv Testcode: Read cases - " << tcases_i << endl;
	
	
	for( int i = 0; i < tcases_i; i++ )
	{
		memset( presence_ia, 0, sizeof(presence_ia) );
		memset( current_ia, 0, sizeof(current_ia) );
		neededFriends_i = 0;
		totalFriends_i = 0;
		presence_sz = "";
		
		// Read the max shyness level
		inputfile_fsp >> maxSlevel_i;
		inputfile_fsp >> presence_sz;
		
		//cout << "Arv Testcode: Read shyness level - " << maxSlevel_i << endl;
		//cout << "Arv Testcode: Read presecne string - " << presence_sz << endl;
		
	
		// Read the characters
		for( index_i = 0; index_i <= maxSlevel_i; index_i++ )
		{
			readChar_c = presence_sz[index_i];
			
			//cout << "Arv Testcode: Read char - " << readChar_c << endl;
			
			if( (readChar_c >= '0') && (readChar_c <= '9') )
			{
				presence_ia[index_i] = readChar_c - '0';
				
				//cout << "Arv Testcode: Read int - " << presence_ia[index_i] << endl;
				
				if( index_i != 0 )
				{
					if( presence_ia[index_i] > 0 )  
					{
						if( current_ia[index_i-1] < index_i )
						{
							neededFriends_i = index_i - current_ia[index_i-1];
							current_ia[index_i] = current_ia[index_i-1] + presence_ia[index_i] + neededFriends_i;
							totalFriends_i = totalFriends_i + neededFriends_i;
						}
						else
						{
							current_ia[index_i] = current_ia[index_i-1] + presence_ia[index_i];
						}
					}
					else
					{
						current_ia[index_i] = current_ia[index_i-1];
					}
				}
				else
				{
					current_ia[0] = presence_ia[0];
				}
			}
			else
			{
				cout << "Read char does not seem to be a digit" << endl;
			}
		}
		
		//cout << "Case #" << i+1 << ": " << totalFriends_i << endl;
		outputfile_fsp << "Case #" << i+1 << ": " << totalFriends_i << endl;
		//cout << endl;
	}

	
}