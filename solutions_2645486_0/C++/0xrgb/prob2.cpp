// C++11 code by 0xrgb / Using VS Express 2012
// DL : http://www.microsoft.com/visualstudio/kor/downloads

// Google Code Jam Project
// Round 1A. 2013 - B. Manage your Energy

// Standard libraries
// Console, file io
#include <iostream>
#include <fstream>

// Useful functions
#include <exception>
#include <algorithm>
#include <functional>
#include <cmath>
#include <memory.h>

// Good things
#include <string>
#include <vector>

using namespace std;

int dy[15][15], dat[15];

int main(int argc, char **argv) {
	// Set some vars
	int tCases, eMax , rEnergy, aNum;

	// Set file io
	ifstream inFile (   "input.in" , ifstream::in  );
	ofstream outFile( "output.out" , ofstream::out );

	// How many cases are there?
	inFile >> tCases;

	for ( int i = 1 ; i <= tCases ; ++i ) {
		inFile >> eMax >> rEnergy >> aNum;
		for(int j=1 ; j<=aNum ; ++j) inFile >> dat[j];

		// Process
		memset( dy , 0 , sizeof(dy) );
		for( int j = 1 ; j <= aNum ; ++j ) {
			for( int k = 0 ; k <= eMax ; ++k ) {
				for ( int l = (k > rEnergy ? k-rEnergy : 0 ) ; l <= eMax ; ++l ) {
					int imsi = ((l+rEnergy > eMax ? eMax : l+rEnergy)-k)*dat[j]+dy[j-1][l];
					if ( dy[j][k] < imsi ) dy[j][k] = imsi;
				}
			}
		}
		try{
			outFile << "Case #" << i << ": " << dy[aNum][0] << endl;
			cout << "Case #"<< i << ": Solved" << endl;
		} catch( std::exception e ) {
			cerr << e.what() << endl;
		} catch( ... ) {
			cerr << "Bad error occured..." << endl ;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}