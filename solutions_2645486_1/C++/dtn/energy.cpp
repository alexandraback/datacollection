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
		int e, r, n;
		unsigned long long total = 0;

		fi >> e >> r >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			fi >> v[i];
		//for (int i = 0; i< n; i++) cout << v[i] << endl;
		int re = e;
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				total = total + re * v[i];
				re = 0;
			} else {
				//find next big
				int j = i + 1;
				while (j < n) {
					if (v[j] <= v[i]) j++;
					else break;
				}
				if (j == n) { // no one
					total = total + re*v[i];
					re = 0;
				} else {
					int use = MIN(re, re + (j-i) * r - e);
					if (use < 0) use = 0;
					total = total + use * v[i];
					re = re - use;
				}
			}
			re = re + r;
		}
		fo << "Case #" << c << ": " << total <<"\n";
	}

	fo.close();
	fi.close();
	return 0;
}
