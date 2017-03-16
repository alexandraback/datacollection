#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

//2 million should be okay, for testing purposes
#define LIMIT 10000000

int main(int argc, char **argv) {
	ifstream infile;
	ofstream outfile;
	
	assert(argc == 3);
	infile.open(argv[1]);
	if (!infile.is_open()) { cout << "can't open file " << argv[1] << "\n"; exit(1); }
	int numCases;
	infile >> numCases;
	
	outfile.open(argv[2]);
	if (!outfile.is_open()) { cout << "can't open file " << argv[2] << "\n"; exit(1); }
	
	int i, j, k, lower, upper, numDigits, num, base, tempNum, validCycles;
	long perms, totalPerms;
	char *isUsed;
	char base10Array[7];	//limit of 2 million = 7 digits
	isUsed = new char[LIMIT+1];
	
	for (int itr=1; itr<=numCases; itr++) {
		infile >> lower >> upper;
		if (upper<10) numDigits = 1;
		else if (upper<100) numDigits = 2;
		else if (upper<1000) numDigits = 3;
		else if (upper<10000) numDigits = 4;
		else if (upper<100000) numDigits = 5;
		else if (upper<1000000) numDigits = 6;
		else numDigits = 7;
		
		for (i=lower; i<=upper; i++) isUsed[i] = 0;
		
		base = 1;
		for (i=0; i<numDigits; i++) {
			base10Array[i] = (lower/base) % 10;
			base *= 10;
		}
		num = lower;
		totalPerms = 0;
		while (1) {
			
		//	cout << "num " << num << "   base10array ";
		//	for (k=numDigits-1; k>=0; k--) cout << (int)base10Array[k] << " ";
		//	cout << "\n";
			
			tempNum = 0;
			base = 1;
			for (k=0; k<numDigits; k++) {
				tempNum += base10Array[k]*base;
				base *= 10;
			}
			if (tempNum != num) {
				cout << "mismatch " << tempNum << " " << num << "\n";
				exit(1);
			}
			
			//count cycles
			if (isUsed[num]==0) {
				for (i=1; i<numDigits; i++) if (base10Array[0]!=base10Array[i]) break;
				if (i<numDigits) {	//not all the digits are the same
					validCycles = 0;
					for (j=0; j<numDigits; j++) {
						tempNum = 0;
						base = 1;
						for (k=0; k<numDigits; k++) {
							tempNum += base10Array[k]*base;
							base *= 10;
						}
						if (tempNum >= lower && tempNum <= upper && isUsed[tempNum]==0) {
							isUsed[tempNum] = 1;
							validCycles++;
						}
						
						//cycle
						tempNum = base10Array[0];
						for (k=0; k<numDigits-1; k++) base10Array[k] = base10Array[k+1];
						base10Array[k] = tempNum;
					}
					
					perms = (validCycles==0) ? 0 : validCycles*(validCycles-1)/2;
					
			//		if (perms) {
			//			for (k=numDigits-1; k>=0; k--) cout << (int)base10Array[k];
			//			cout << " " << perms << "\n";
			//		}
					
					totalPerms += perms;
				}
			}
			
			num++;
			if (num > upper) break;
			
			//add 1 to num in base10Array
			for (i=0; i<numDigits; i++) {
				base10Array[i]++;
				if (base10Array[i]==10) base10Array[i] = 0;
				else break;
			}
		}
		
		outfile << "Case #" << itr << ": " << totalPerms << "\n";
	}
	infile.close();
	outfile.close();
	
	delete[] isUsed;
	
	return 0;
}