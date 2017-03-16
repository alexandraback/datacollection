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

int absorb(int &a, int x) {
	int k = 0;
	while (pow(2, k) * (a - 1) + 1 <= x ) k++;
	a = pow(2, k) * (a - 1) + 1 + x;
	return k;
}

int main() {
	ifstream fi;
	ofstream fo;
	fi.open("in.in");
	fo.open("out.txt");

	int t;
	fi >> t;
	for (int c = 1; c <= t; c++) {
		int a, n;
		fi >> a >> n;
		vector<int> mos(n);
		for (int i = 0; i < n; i++)
			fi >> mos[i];
		if (a == 1) {
			fo << "Case #" << c << ": " << n <<"\n";
			continue;
		}

		sort(mos.begin(), mos.end());

		vector<int> count(n + 1, n);
		count[0]  = 0;

		for (int i = 0; i < n; i++) {
			int k = absorb(a, mos[i]);
			//if (k >=n ) break;
			count[i + 1] = k + count[i];
			if (count[i + 1] > n) break;
		}

		int min = n;
		for (int i = 0; i < n; i++) {
			if (count[i + 1] >=n ) break;
			if (min > count[i + 1] + n - i - 1) min = count[i + 1] + n - i - 1;
		}
		fo << "Case #" << c << ": " << min <<"\n";
	}

	fo.close();
	fi.close();
	return 0;
}
