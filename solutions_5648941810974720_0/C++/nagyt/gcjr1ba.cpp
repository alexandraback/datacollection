// gcjr1a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>

using namespace std;


int main()
{
	ifstream a("D:\\gcj\\A-small-attempt0.in.sdx");
	ofstream o("D:\\gcj\\output.txt");
	int nr; a >> nr;
	std::string line;
	std::getline(a, line);
	for (int i = 0; i<nr; i++) {
		o << "Case #" << (i + 1) << ": ";
		string word;
		a >> word;
		int abc[26] = {0};
		int digits[10] = { 0 };

		for (auto it = word.begin(); it != word.end(); it++) {
			abc[*it - 'A']++;
		}

		if (abc['Z' - 'A'] > 0) {
			digits[0] = abc['Z' - 'A'];
			abc['E' - 'A'] -= abc['Z' - 'A'];
			abc['R' - 'A'] -= abc['Z' - 'A'];
			abc['O' - 'A'] -= abc['Z' - 'A'];
			abc['Z' - 'A'] = 0;
		}

		if (abc['W' - 'A'] > 0) {
			digits[2] = abc['W' - 'A'];
			abc['T' - 'A'] -= abc['W' - 'A'];
			abc['O' - 'A'] -= abc['W' - 'A'];
			abc['W' - 'A'] = 0;
		}

		if (abc['U' - 'A'] > 0) {
			digits[4] = abc['U' - 'A'];
			abc['F' - 'A'] -= abc['U' - 'A'];
			abc['O' - 'A'] -= abc['U' - 'A'];
			abc['R' - 'A'] -= abc['U' - 'A'];
			abc['U' - 'A'] = 0;
		}

		if (abc['F' - 'A'] > 0) {
			digits[5] = abc['F' - 'A'];
			abc['I' - 'A'] -= abc['F' - 'A'];
			abc['V' - 'A'] -= abc['F' - 'A'];
			abc['E' - 'A'] -= abc['F' - 'A'];
			abc['F' - 'A'] = 0;
		}

		if (abc['X' - 'A'] > 0) {
			digits[6] = abc['X' - 'A'];
			abc['I' - 'A'] -= abc['X' - 'A'];
			abc['S' - 'A'] -= abc['X' - 'A'];
			abc['X' - 'A'] = 0;
		}

		if (abc['S' - 'A'] > 0) {
			digits[7] = abc['S' - 'A'];
			abc['E' - 'A'] -= abc['S' - 'A'];
			abc['V' - 'A'] -= abc['S' - 'A'];
			abc['E' - 'A'] -= abc['S' - 'A'];
			abc['N' - 'A'] -= abc['S' - 'A'];
			abc['S' - 'A'] = 0;
		}

		if (abc['G' - 'A'] > 0) {
			digits[8] = abc['G' - 'A'];
			abc['E' - 'A'] -= abc['G' - 'A'];
			abc['I' - 'A'] -= abc['G' - 'A'];
			abc['H' - 'A'] -= abc['G' - 'A'];
			abc['T' - 'A'] -= abc['G' - 'A'];
			abc['G' - 'A'] = 0;
		}

		if (abc['I' - 'A'] > 0) {
			digits[9] = abc['I' - 'A'];
			abc['N' - 'A'] -= abc['I' - 'A'];
			abc['N' - 'A'] -= abc['I' - 'A'];
			abc['E' - 'A'] -= abc['I' - 'A'];
			abc['I' - 'A'] = 0;
		}

		if (abc['N' - 'A'] > 0) {
			digits[1] = abc['N' - 'A'];
			abc['O' - 'A'] -= abc['N' - 'A'];
			abc['E' - 'A'] -= abc['N' - 'A'];
			abc['N' - 'A'] = 0;
		}

		if (abc['T' - 'A'] > 0) {
			digits[3] = abc['T' - 'A'];
			abc['H' - 'A'] -= abc['T' - 'A'];
			abc['R' - 'A'] -= abc['T' - 'A'];
			abc['E' - 'A'] -= abc['T' - 'A'];
			abc['E' - 'A'] -= abc['T' - 'A'];
			abc['T' - 'A'] = 0;
		}

		for (int j=0; j<10;j++)
			for (int k = 0; k < digits[j]; k++)
			{
				o << j;
				cout << j;
			}

		o << endl;
		cout << endl;

	}
	a.close();
	o.close();
	char c; cin >> c;
	return 0;
}

