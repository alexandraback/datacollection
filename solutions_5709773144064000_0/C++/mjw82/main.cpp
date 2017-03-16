#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

// #define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf (stderr, __VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif



int main(int argc, char **argv)
{
	if (argc != 2) {
		cerr << argv[0] << "filename" << endl;
		return 1;
	}
	
	ifstream InputFile (argv[1]);
	
	int NbTestCases = 0;
	
	if (!InputFile.is_open()) {
		cerr << "Could not open input file" << endl;
		return 1;
	}
	
	InputFile >> NbTestCases;
	
	DEBUG_PRINT("NbTestCases = %d\n", NbTestCases);

	for (int CurTestCase = 0; CurTestCase < NbTestCases; CurTestCase++) {
		
		DEBUG_PRINT("\n\nTest Case %d\n", CurTestCase+1);

		long double F_0 = 2.0; // default cookie production without farms
		long double C = 0.0;	// Cost of a cookie farm
		long double F = 0.0; // Extra cookies per cookie farm
		long double X = 0.0; // Winning threshold
		
		InputFile >> C >> F >> X;
		
		DEBUG_PRINT("C = %f - F = %f - X = %f\n", C, F, X);
		
		long double A0 = F_0;			
		long double currentTime = 0.0;
			

		if (C == 0.0 && F > 0.0) {
			
			// we can directly buy an unlimited amount of farms which will create an unlimited amount of cookies.
			
			currentTime = 0;
			
		} else if (F == 0.0) {
			
			// it does not make sense to buy a farm because it will not produce anything.
			
			currentTime = X / A0;
			
		} else if (X < C) {
			
			// it does not make sense to buy a farm because winning threshold is below cost to buy it
			
			currentTime = X / A0;
			
		} else {
		

			while (true) {
							
				// Sanity check: if X < C, just wait to get X cookies.
				
				if (X < C) {
					currentTime += (X / A0);
					break;
				}
				
				// Calculate next function: 
				// current function: A0 * x - C/A0
				// new function NewA * x (with NewA = A0+F)
				
				const long double NewA = A0 + F;				
				const long double smallX = C / F;
				const long double smallY = NewA * smallX;
				
				DEBUG_PRINT("currentTime = %f, A0 = %f, NewA = %f, smallX = %f\n", currentTime, A0, NewA, smallX);
				
				// return on investement too long for new cookie farm
				if (smallY >= X) {
					currentTime += (X / A0);
					break;				
				} else {
					currentTime += (C / A0);				
					A0 = NewA;
				}
							
			}
			
		}
		
		
		fprintf(stdout, "Case #%d: %.7Lf\n", CurTestCase+1, currentTime);
		// cout << "Case #" << (CurTestCase+1) << ": " << currentTime << endl;
	}
	
	
	
	return 0;
}
