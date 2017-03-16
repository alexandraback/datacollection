//============================================================================
// Name        : codejam.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
#define MIN(a, b) ((a > b) ? b : a)
#define MAX(a, b) ((a > b) ? a : b)

int main() {
	ifstream fi;
	ofstream fo;
	fi.open("in.in");
	fo.open("out.txt");

	int t;
	fi >> t;
	for (int c = 1; c <= t; c++) {
		unsigned long long r, t, k;
		fi >> r >> t;
		unsigned long long l, h, mid;
		h = 1;
		while ((2*h + 2*r - 1)* h <= t) h = h * 2;
		l = h/2;
		while (l + 1 < h) {
			mid = (l + h)/2;
			if ((2*mid + 2*r - 1) * mid > t) h = mid;
			else l = mid;
		}
		fo << "Case #" << c << ": " << l <<"\n";
	}

	fo.close();
	fi.close();
	return 0;
}
