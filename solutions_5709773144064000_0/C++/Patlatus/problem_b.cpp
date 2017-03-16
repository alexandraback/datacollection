#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <set>
#include <iterator>


using namespace std;

long double c = 0.0, f = 0.0, x = 0.0;

long double solve() {
	long double r1 = 0.0, r2 = 0.0, t = 0.0, e1 = 0.0, e2 = 0.0;
	r1 = 2;
	e1 = x / r1;
	r2 = r1 + f;
	t = c / r1;
	e2 = t + x / r2;
	while ( e2 < e1 )
	{
		r1 = r2;
		e1 = e2;
		r2 = r1 + f;
		t = t + c / r1;
		e2 = t + x / r2;
	}
	return e1;
}

int main(int argc, char* argv[]) {	
	string inputFile = (argc > 1) ? argv[1] : "input.txt";
	string outputFile = (argc > 2) ? argv[2] : (argc > 1) ? (inputFile + "out.txt") : "output.txt";
	ifstream in;
	ofstream out;
	in.open(inputFile);
	out.open(outputFile);
	out.precision(15);

	int tests;
	in >> tests;
	for (int test = 1; test <= tests; ++test) {
		out << "Case #" << test << ": ";
		// Grab input
		in >> c >> f >> x;
		// Solve the problem and give feedback to the end user;
		out << solve() << endl;
		cerr << ": " << test << endl;
	}

	in.close();
	out.close();

	cout << inputFile << '\n' << outputFile << '\n';

	cin.get();
	return 0;
}