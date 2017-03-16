#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void solve(int c, string s) {
	int count[26];
	for (int i = 0; i < 26; i++) count[i] = 0;
	for (int i = 0; i < s.length(); i++) {
		char cc = s[i];
		count[cc - 'A']++;
	}
	int numCount[10];
	for (int i = 0; i < 10; i++) numCount[i] = 0;

	int index = 0;
	numCount[index] = count['Z' - 'A'];
	count['Z' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	count['R' - 'A'] -= numCount[index];
	count['O' - 'A'] -= numCount[index];

	index = 2;
	numCount[index] = count['W' - 'A'];
	count['T' - 'A'] -= numCount[index];
	count['W' - 'A'] -= numCount[index];
	count['O' - 'A'] -= numCount[index];

	index = 6;
	numCount[index] = count['X' - 'A'];
	count['S' - 'A'] -= numCount[index];
	count['I' - 'A'] -= numCount[index];
	count['X' - 'A'] -= numCount[index];
	
	index = 4;
	numCount[index] = count['U' - 'A'];
	count['F' - 'A'] -= numCount[index];
	count['O' - 'A'] -= numCount[index];
	count['U' - 'A'] -= numCount[index];
	count['R' - 'A'] -= numCount[index];
	
	index = 8;
	numCount[index] = count['G' - 'A'];
	count['E' - 'A'] -= numCount[index];
	count['I' - 'A'] -= numCount[index];
	count['G' - 'A'] -= numCount[index];
	count['H' - 'A'] -= numCount[index];
	count['T' - 'A'] -= numCount[index];

	index = 3;
	numCount[index] = count['H' - 'A'];
	count['T' - 'A'] -= numCount[index];
	count['H' - 'A'] -= numCount[index];
	count['R' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];

	index = 5;
	numCount[index] = count['F' - 'A'];
	count['F' - 'A'] -= numCount[index];
	count['I' - 'A'] -= numCount[index];
	count['V' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	
	index = 7;
	numCount[index] = count['V' - 'A'];
	count['S' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	count['V' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	count['N' - 'A'] -= numCount[index];
	
	index = 9;
	numCount[index] = count['I' - 'A'];
	count['N' - 'A'] -= numCount[index];
	count['I' - 'A'] -= numCount[index];
	count['N' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	
	index = 1;
	numCount[index] = count['N' - 'A'];
	count['O' - 'A'] -= numCount[index];
	count['N' - 'A'] -= numCount[index];
	count['E' - 'A'] -= numCount[index];
	
	cout << "Case #" << c << ": ";
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < numCount[i]; j++) cout << i;
	}
	cout << endl;
}

int main(int argc, const char * argv[]) {

	istream &fin = cin;
 //	fstream fin("tiny.in");

// #if __CMD__
// 	istream &fin = cin;
// #else
// 	fstream fin("tiny.in");
// #endif

	int T;
	fin >> T;
	string W;
	for (int c = 1; c <= T; c++) {
		string s;
		fin >> s;
		solve(c, s);
	}
    return 0;
}
