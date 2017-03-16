#include <iostream>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;
int main()
{

	long long int numCase, X, Y;
	cin >> numCase;

	ofstream myfile;
  	myfile.open ("output.txt");

	for (int num = 0; num < numCase; num++)
	{

		// Read dimensions
		cin >> X;
		cin >> Y;
		
		int myX=0;
		int myY=0;
		string mytrip="";
		
		// Move one coordinate upwards:    N
		// Move two coordinates upwards:   NSN
		// Move three coordinates upwards: NSNSN
		int nextJump=1, lastJump;
		if(myY<Y) {lastJump=-1;} // Means south}
		else {lastJump=1;} // Means north}
		
		while(myY!=Y) {
			if(lastJump==-1) {myY+=nextJump; lastJump=1; nextJump++; mytrip.push_back('N');}
			else {myY-=nextJump; lastJump=-1; nextJump++; mytrip.push_back('S');}
		}
		
		// Do the same for X
		if(X!=0) {
			if(myX<X) {lastJump=1;} // Means west}
			else {lastJump=-1;} // Means east}
		
			while(myX!=X) {
				if(lastJump==-1) {myX+=nextJump; lastJump=1; nextJump++; mytrip.push_back('E');}
				else {myX-=nextJump; lastJump=-1; nextJump++; mytrip.push_back('W');}
			}
		}
			
		// Print outcome
		myfile << "Case #" << (num+1) << ": " << mytrip << endl;
	}

  	myfile.close();
	return 0;
}
