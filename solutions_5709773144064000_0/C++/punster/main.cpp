#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "stdlib.h"
using namespace std;

double cookietime(double rate, double C, double F, double X) {
	if (X < C) { return (X/rate); }
	if (((X/rate)-(X/(rate+F))) > (C/rate)) { 
		return ((C/rate)+cookietime(rate+F,C,F,X));
	}
	return (X/rate);
}
double do_something() {
	double C,F,X;
	cin >> C >> F >> X;
	cout.precision(7);
	cout << fixed; 
	return cookietime(2.0,C,F,X);
}

int main(int argc, char **argv)
{
	int tests;
	cin >> tests;

	for (int i=1; i <= tests; ++i) {
	  cout << "Case #" << i << ": " << do_something() << "\n"; 
	}
	return 0;
}