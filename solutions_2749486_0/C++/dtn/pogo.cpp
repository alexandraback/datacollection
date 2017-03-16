
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define MIN(a, b) ((a > b) ? b : a)
#define MAX(a, b) ((a > b) ? a : b)

string move(int x, int y) {
	string s = "";
	if (x > 0) {
		for (int i = 0; i < x; i++) s.append("WE");
	} else {
	for (int i = 0; i < -x; i++) s.append("EW");
	}

	if (y > 0) {

				for (int i = 0; i < y; i++) s.append("SN");
	} else {
		for (int i = 0; i < -y; i++) s.append("NS");
	}
	return s;
}
int main() {
	ifstream fi;
	ofstream fo;
	fi.open("in.in");
	fo.open("out.txt");

	int t;
	fi >> t;
	for (int c = 1; c <= t; c++) {
		int x, y;

		fi >> x >> y;
		//cout << s << n << endl;
		fo << "Case #" << c << ": " << move(x, y) <<"\n";
	}

	fo.close();
	fi.close();
	return 0;
}
