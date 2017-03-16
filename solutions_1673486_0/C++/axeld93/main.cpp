// round1AproblemA

// read in text file
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main ()
{
    long double numRead;




    char *filename = "input.txt";
    ifstream infile(filename);
	int inType=0; // 0 is T, 1 is A, 2 is B, 3 is p
	int T;
	int A;
	int B;
	int pcount=1;
	long double p[100000];
	long double minChars=1000000;
	long double pProd;
	int i;
	long double curChars;
	int numBackspace;
	int caseUpTo=1;


    if (!infile) {
        cout << "There was a problem opening " << filename << endl;
        return 0;
    }

	 // open file to write
  ofstream outfile ("output.txt");

    while (infile >> numRead) {
        if (inType==0) {
			// T
			T=int(numRead);
			inType++;
		} else if (inType==1) {
			// A
			A=int(numRead);
			inType++;

		} else if (inType==2) {
			// B
			B=int(numRead);
			inType++;

		} else if (inType==3) {
			// p
			p[pcount-1]=numRead;

			pcount++;
			if (pcount>A) { inType=1; pcount=1;
			
			
			
			
				// check each case

			
				// type rest
				pProd=p[0];
				for (i=1;i<A;i++) {
					pProd=pProd*p[i];
				}
				curChars = pProd*(B-A+1) + (1-pProd)*(2*B-A+2);
				minChars=curChars;
			
				// give up
				curChars=B+2;
				if (curChars<minChars) { minChars=curChars; }
			
				// backspacing
				for (numBackspace=1;numBackspace<A;numBackspace++) {				
					pProd=p[0];
					for (i=1;i<A-numBackspace;i++) {
						pProd=pProd*p[i];
					}
					curChars=pProd*(B-A+2*numBackspace+1) + (1-pProd)*(2*B-A+2*numBackspace+2);
					if (curChars<minChars) { minChars=curChars; }

				}
			
				// print
				outfile << fixed;
				outfile << "Case #" << caseUpTo << ": " << setprecision(6) << minChars << "\n";
			
			
				caseUpTo++;
			}
			
			
		}
	}
}