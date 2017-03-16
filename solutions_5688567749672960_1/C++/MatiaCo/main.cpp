#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>

using namespace std;


int main (int argc, char * const argv[]) {
    int ncases, cases, run, nsize, halfbool, rdig, ldig;
	long long number, nkeep;
	int digits[16], powerten[16];
	
	run = 2;
	powerten[0] = 1;
	powerten[1] = 10;
	while (run < 16) {
		powerten[run] = powerten[run - 1] + pow(10,(run/2 + (run%2))) + pow(10,(run/2)) - 1;
		run++;
	}
	
	cin >> ncases;
	
	
	for (cases = 0; cases < ncases; cases++) {
		cout << "Case #" << cases + 1 << ": ";
		cin >> number;
		
		nkeep = number;
		nsize = 0;
		
		while (number != 0) {
			digits[nsize] = number%10;
			number = number/10;
			nsize++;
		}
		
		digits[nsize] = 0;
		
		/*see if it is mostly zeros*/
		run = 0;
		halfbool = 0;
		
		
		while (run < nsize/2 + nsize%2) {
			if (digits[run] != 0) {
				halfbool = 1;
			}
			run++;
		}
		
		
		/*get digits again*/
		
		if (halfbool == 0 && nkeep > 1) {
			number = nkeep - 1;
			nsize = 0;
			
			while (number != 0) {
				digits[nsize] = number%10;
				number = number/10;
				nsize++;
			}
			digits[nsize] = 0;
		}
		
		/*get some answers*/
		ldig = 0;
		rdig = 0;
		run = 0;
		while (run < nsize/2) {
			ldig = ldig + digits[nsize - 1 - run]*pow(10,run);
			rdig = rdig + digits[run]*pow(10,run);
			run++;
		}
		
		if (nsize%2 == 1) {
			rdig = rdig + digits[run]*pow(10,run);
		}
		
		cout << ldig + rdig + powerten[nsize - 1] + (1 - halfbool) - (ldig == 1 || nkeep < 11) << endl;
	}
    return 0;
}
