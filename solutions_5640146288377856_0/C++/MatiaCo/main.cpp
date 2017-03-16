#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>

using namespace std;


int main (int argc, char * const argv[]) {
    int ncases, cases, row, col, ship;
	
	cin >> ncases;
	
	
	for (cases = 0; cases < ncases; cases++) {
		cout << "Case #" << cases + 1 << ": ";
		cin >> row >> col >> ship;
		
		cout << (row - 1)*(col/ship) + ((col - 1)/ship) + ship << endl;
		
	}
    return 0;
}