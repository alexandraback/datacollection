#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int r = 0, c = 0, m = 0, v = 0, w = 0, x = 0, y = 0, a = 0, b = 0;

string empties(int count) {
	string result = "";
	for ( int i = 1; i <= count; i++)
		result += ".";
	return result;    
}

string mines(int count) {
	string result = "";
	for ( int i = 1; i <= count; i++)
		result += "*";
	return result;    
}

string c_empty_line() {
	return "c" + empties(c - 1) + "\n";
}

string empty_lines(int count) {
	string result = "";
	for ( int i = 1; i <= count; i++) {
		result += empties(c) + "\n";
	}
	return result;
}

string c_mine_line() {
	return "c" + mines(c - 1) + "\n";
}

string mine_lines(int count) {
	string result = "";
	for ( int i = 1; i <= count; i++) {
		result += mines(c) + "\n";
	}
	return result;
}

string ii_mines(int count) {
	string result = "";
	for ( int i = 1; i <= count; i++) {
		result += ".." + mines(c - 2) + "\n";
	}
	return result;
}

string mixed(string one, string two, int count2, string three, int count3) {
	string result = one;
	for ( int i = 1; i <= count2; i++) {
		result += two;
	}
	for ( int i = 1; i <= count3; i++) {
		result += three;
	}
	return result;
}

string solve() {
	int i = 0, j = 0;
	if ( m == 0 ) {
		return c_empty_line() + empty_lines(r - 1);
    }
	if ( m == r * c - 1 ) {
		return c_mine_line() + mine_lines(r - 1);
	}
	if ( r == 1 ) {
		return "c" + empties(c - m - 1) + mines(m) + "\n";
	}
	if ( c == 1 ) {
		return mixed("c\n", ".\n", r - m - 1, "*\n", m);
	}
	if ( ( ( ( r == 2 ) || ( c == 2 ) ) & ( m % 2 == 1 ) ) ||  ( ( r == 2 ) && ( ( m >> 1 ) == c - 1 ) ) || ( ( c == 2 ) && ( ( m >> 1 ) == r - 1 ) ) ) {
		return "Impossible\n";
	}
	if ( r == 2 ) {
		m >>= 1;
		return "c" + empties(c - m - 1) + mines(m) + "\n" + empties(c - m) + mines(m) + "\n";
	}
	if ( c == 2 ) {
		m >>= 1;
		return mixed("c.\n", "..\n", r - m - 1, "**\n", m);
	}
	v = r * c - m;
	if ( v == 4 ) {
		return "c." + mines(c - 2) + "\n.." + mines(c - 2) + "\n" + mine_lines(r - 2);
	}
	if ( v == 6 ) {
		return "c.." + mines(c - 3) + "\n..." + mines(c - 3) + "\n" + mine_lines(r - 2);
	}
	if ( v < 8 ) {
		return "Impossible\n";
	}
	w = v - 8;
	x = w >> 1;
	y = w % 2;
	if ( x <= c - 3 ) {
		return "c.." + empties(x) + mines(c - x - 3) + "\n..." +
			empties(x) + mines(c - x - 3) + "\n.." + (( y == 1 ) ? '.' : '*') +
			mines(c-3) + "\n" + mine_lines(r-3);
	}
	x -= c - 3;
	if ( x <= r - 3 ) {
		return c_empty_line() + empty_lines(1) + ".." + (( y == 1 ) ? '.' : '*') + mines(c - 3) +
			"\n" + ii_mines(x) + mine_lines(r - x - 3);
	}
	x -= r - 3;
	w = ( x << 1 ) + y;
	a = w / ( c - 2 );
	b = w % ( c - 2 );
	return c_empty_line() + empty_lines(a + 1) + empties(b + 2) + mines(c - b - 2) + "\n" + ii_mines(r - a - 3);
}

int main(int argc, char* argv[]) {	
	string inputFile = (argc > 1) ? argv[1] : "input.txt";
	string outputFile = (argc > 2) ? argv[2] : (argc > 1) ? (inputFile + "out.txt") : "output.txt";
	ifstream in;
	ofstream out;
	in.open(inputFile);
	out.open(outputFile);

	int tests;
	in >> tests;
	for (int test = 1; test <= tests; ++test) {
		out << "Case #" << test << ": " << endl;
		// Grab input
		in >> r >> c >> m;
		// Solve the problem and give feedback to the end user;
		out << solve();
		cerr << ": " << test << endl;
	}

	in.close();
	out.close();

	cout << inputFile << '\n' << outputFile << '\n';
	cin.get();
	return 0;
}