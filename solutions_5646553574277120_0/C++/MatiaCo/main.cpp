#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdlib.h>

using namespace std;

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}


int main (int argc, char * const argv[]) {
    int ncases, cases;
	int dcoins, pay, valo, run, run2;
	int coins[102];
	int values[100];
	int mint[100], newmint;
	
	
	// SOME SORTING PRACTICE
	
	/*int oi[] = {9,3,5,3,0,5};
	qsort(oi, 5, sizeof(int), compare);
	for (run = 0; run < 6; run++) {
		cout << oi[run] << " ";
	}*/
	
	cin >> ncases;
	
	
	for (cases = 0; cases < ncases; cases++) {
		cout << "Case #" << cases + 1 << ": ";
		
		cin >> pay >> dcoins >> valo;
		
		for (run = 0; run < dcoins; run++) {
			cin >> coins[run];
		}
		
		qsort(coins, dcoins, sizeof(int), compare);
		
		
		for (run = 0; run < 100; run++) {
			values[run] = 0;
		}
		
		for (run = 0; run < dcoins; run++) {
			run2 = 0;
			while (run2 < 31) {
				values[values[run2]*(run2 + 1) + coins[run] - 1] = 1;
				run2++;
			}
		}
		
		newmint = 0;
		for (run = 0; run < valo; run++) {
			if (1 - values[run]) {
				mint[newmint] = run + 1;
				run2 = newmint;
				
		
					while (run2 < 31) {
						values[values[run2]*(run2 + 1) + mint[newmint] - 1] = 1;
						run2++;
					}
			
				newmint++;
			}
		}
		
		cout << newmint << endl;
	}
    return 0;
}