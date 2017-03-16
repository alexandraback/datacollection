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
#include <algorithm>
using namespace std;
#define MIN(a, b) ((a > b) ? b : a)
#define MAX(a, b) ((a > b) ? a : b)


double comp(int y, int n) {
	double com = 1;
	for (int i = 0; i < y; i++) {
		com = com * (n - i) / (2.0 * (i+1));
	}
	com = com / (1.0 * pow(2, n - y));
	return com;
}

int main() {
	ifstream fi;
	ofstream fo;
	fi.open("in.in");
	fo.open("out.txt");

	int t;
	fi >> t;
	for (int c = 1; c <= t; c++) {
		int n, x, y;
		fi >> n >> x >> y;
		if (x < 0) x = -x;
		int k = (x + y)/2;

		if (n >= (k+1) * (2*k +1)) {
			fo << "Case #" << c << ": " << 1.0 <<"\n";
			continue;
		}

		n = n - k*(2*k -1);
		cout << c << " " << n << endl;
		int min = 0;
		if (n > 2*k) min = n - 2*k;

		n = n - 2 * min;
		y = y + 1 - min;
		if (y > n) {
			fo << "Case #" << c << ": " << 0.0 <<"\n";
			continue;
		}

		double total = 0;
		for (int i = y; i <=n; i++) {
			total = total + comp(i, n);
			cout << total << endl;
		}
		fo << "Case #" << c << ": " << total <<"\n";
	}

	fo.close();
	fi.close();
	return 0;
}
