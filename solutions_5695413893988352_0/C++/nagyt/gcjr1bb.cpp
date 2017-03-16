// gcjr1a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;

int cc(string& c, string& j, bool l, bool g, int i) {
	if (i == c.size()) {
		return abs(atoll(c.c_str()) - atoll(j.c_str()));
	}
	else
	{
		if (l) {
			if (c[i] == '?' && j[i] == '?') {
				string c1=c, c2=c, c3=c, j1=j, j2=j, j3=j;
				c1[i] = '0';
				j1[i] = '0';
				int r1 = cc(c1, j1, true, g, i + 1);
				c2[i] = '0';
				j2[i] = '1';
				int r2 = cc(c2, j2, false, false, i + 1);
				c3[i] = '1';
				j3[i] = '0';
				int r3 = cc(c3, j3, false, true, i + 1);
				if ((r1 <= r2) && (r1 <= r3)) {
					c = c1;
					j = j1;
					return r1;
				}
				if ((r2 <= r1) && (r2 <= r3)) {
					c = c2;
					j = j2;
					return r2;
				}
				if ((r3 <= r2) && (r3 <= r1)) {
					c = c3;
					j = j3;
					return r3;
				}
			}
			if (c[i] == '?') {
				string c1 = c, c2 = c, c3 = c, j1 = j, j2 = j, j3 = j;
				c1[i] = j[i] > '0' ? j[i] -1 : j[i];
				int r1 = cc(c1, j1, c1[i] == j[i], false, i + 1);
				c2[i] = j[i];
				int r2 = cc(c2, j2, true, g, i + 1);
				c3[i] = j[i]< '9' ? j[i]+1 : j[i];
				int r3 = cc(c3, j3, c3[i] == j[i], true, i + 1);
				if ((r1 <= r2) && (r1 <= r3)) {
					c = c1;
					j = j1;
					return r1;
				}
				if ((r2 <= r1) && (r2 <= r3)) {
					c = c2;
					j = j2;
					return r2;
				}
				if ((r3 <= r2) && (r3 <= r1)) {
					c = c3;
					j = j3;
					return r3;
				}
			}
			if (j[i] == '?') {
				string c1 = c, c2 = c, c3 = c, j1 = j, j2 = j, j3 = j;
				j1[i] = c[i] > '0' ? c[i] - 1 : c[i];
				int r1 = cc(c1, j1, c1[i] == j[i], true, i + 1);
				j2[i] = c[i];
				int r2 = cc(c2, j2, true, g, i + 1);
				j3[i] = c[i]< '9' ? c[i] + 1 : c[i];
				int r3 = cc(c3, j3, c3[i] == j[i], false, i + 1);
				if ((r1 <= r2) && (r1 <= r3)) {
					c = c1;
					j = j1;
					return r1;
				}
				if ((r2 <= r1) && (r2 <= r3)) {
					c = c2;
					j = j2;
					return r2;
				}
				if ((r3 <= r2) && (r3 <= r1)) {
					c = c3;
					j = j3;
					return r3;
				}
			}
			if (c[i] > j[i]) {
				return cc(c, j, false, true, i + 1);
			}
			if (c[i] < j[i]) {
				return cc(c, j, false, false, i + 1);
			}
			return cc(c, j, true, true, i + 1);
		}
		else {
			if (g) {
				if (c[i] == '?') {
					c[i] = '0';
				}
				if (j[i] == '?') {
					j[i] = '9';
				}
				return cc(c, j, false, true, i + 1);
			}
			else {
				if (c[i] == '?') {
					c[i] = '9';
				}
				if (j[i] == '?') {
					j[i] = '0';
				}
				return cc(c, j, false, false, i + 1);
			}
		}
	}
}


int main()
{
	ifstream a("D:\\gcj\\B-small-attempt1.in.sdx");
	ofstream o("D:\\gcj\\output.txt");
	int nr; a >> nr;
	std::string line;
	std::getline(a, line);
	for (int ii = 0; ii<nr; ii++) {
		o << "Case #" << (ii + 1) << ": ";
		cout << "Case #" << (ii + 1) << ": ";
		string c, j;		
		a >> c >> j;
		int n = c.size();
		bool l = true;
		bool g;
		cc(c, j, true, true, 0);

		cout << c << " " << j << endl;
		o << c << " " << j << endl;

	}
	a.close();
	o.close();
	char c; cin >> c;
	return 0;
}

