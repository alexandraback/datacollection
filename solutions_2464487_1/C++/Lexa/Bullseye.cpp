//============================================================================
// Name        : Bullseye.cpp
// Author      : Jeongseok Son
// Version     :
// Copyright   : GNU LGPL
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gmpxx.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; i++) {
		mpz_class r, t;
		cin >> r >> t;
		cout << "Case #" << i << ": " << ((1 - 2 * r + sqrt((2 * r - 1) * (2 * r - 1) + 8 * t)) / 4) << endl;
	}
	return 0;
}
