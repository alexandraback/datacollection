// gcjr1a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

int fff(const vector<vector<int> >& c, int line) {
	if (line == c.size()-1)
		return 1;
	int sum = 0;
	for (int i = line + 1; i < c.size(); i++) {
		if (c[line][i] == 1)
			sum += fff(c, i);
	}
	return sum;
}

int main()
{
	srand(time(NULL));
	ifstream a("D:\\gcj\\example.txt");
	ofstream o("D:\\gcj\\output.txt");
	int nr; a >> nr;
	std::string line;
	std::getline(a, line);
	for (int ii = 0; ii<nr; ii++) {
		o << "Case #" << (ii + 1) << ": ";
		cout << "Case #" << (ii + 1) << ": ";
		int b;
		a >> b;
		int n;
		a >> n;

		int szum = pow(2, b - 2);
		if (n > szum) {
			o << "IMPOSSIBLE" << endl;
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		else {
			o << "POSSIBLE" << endl;
			cout << "POSSIBLE" << endl;
		}
		vector<vector<int> > v;
		for (int i = 0; i < b; i++) {
			vector<int> w;
			for (int j = 0; j < b; j++) {
				w.push_back(0);
			}
			v.push_back(w);
		}



		for (int i = 0; i < b-1; i++) {
			v[i][b - 1] = 1;
		}
		
		int ff = fff(v, 0);
		while (ff != n) {
			int r = rand() % (b - 1);
			int c = (rand() % (b - 1 - r)) + r + 1;

			if (ff < n) {
				v[r][c] = 1;
			}
			else
				v[r][c] = 0;
			ff = fff(v, 0);
			//cout << "D: " << ff << endl;
		}
		
		
		
		for (int i = 0; i < b; i++) {
			for (int j = 0; j < b; j++) {
				cout << v[i][j];
				o << v[i][j];
			}
			cout << endl;
			o << endl;
		}

	}
	a.close();
	o.close();
	char c; cin >> c;
	return 0;
}

