#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <string>

using namespace std;

int main()
{
	int numCase;
	cin >> numCase;
	int n;
	string name;
	  	
	ofstream myfile;
  	myfile.open ("output.txt");

	
	// Test cases
	for (int num = 0; num < numCase; num++)
	{

		// Read dimensions
		cin >> name;
		cin >> n;
		int namelength=name.length();
		
		int a[namelength];
		// Represent vowel by 0 and consonant by 1
		for(int i=0;i<namelength;i++) {
			if( name.at(i)=='a' || name.at(i)=='e' || name.at(i)=='i' || name.at(i)=='o' || name.at(i)=='u' ) {a[i]=0;}
			else {a[i]=1;}
			//cout << a[i];
		}
		//cout << endl << name << endl;
		
		// Build a left position indicator vector for n consecutive consonants
		int lpositions[namelength];
		for(int i=0;i<namelength;i++) {
			lpositions[i]=0;
		}
		
		for(int lpos=0;lpos<namelength-n+1;lpos++) {
			int sum=0;
			for(int i=lpos;i<lpos+n;i++) {
				sum+=a[i];
			}
			if(sum==n) {lpositions[lpos]=1;}
		}
		
		// Now search through all substrings and use the blocks
		int sum=0;
		for(int lpos=0;lpos<namelength-n+1;lpos++) {
			int nextBlock=lpos;
			while(lpositions[nextBlock]==0 && nextBlock<namelength-n+1) {
				nextBlock++; // Search for the next block
			}
			sum+=namelength-n+1-nextBlock;
		}

		// Print outcome
		myfile << "Case #" << (num+1) << ": " << sum << endl;
	}

  	myfile.close();
	return 0;
}
