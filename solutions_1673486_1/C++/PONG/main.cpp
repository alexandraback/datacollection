#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main (int argc, char * const argv[]) {
//    ifstream in("..//..//sample.in.txt");
	ifstream in("..//..//A-large.in.txt");
	
	
	if(!in) {
		cout << "Input file cannot be opened";
		return 1;
	}
	
	ofstream out("output.txt");
	if (!out) {
		cout << "Output file cannot be opened";
		in.close();
		return 1;
	}
	
	int T;
	in >> T;
	
	for (int t = 0; t < T; t++) {
		double expected = 200000.0;
		double expected1, expected2, expected3;
		expected2 = expected;
		int A, B;
		
		in >> A;
		in >> B;
		double p[B];
		
		//cout << A << " " << B;
		
		for (int a = 0; a < A; a++) {
			in >> p[a];
		}
		
		// case 1 - keep typing
		int correctStroke = B - A + 1;
		int incorrectStroke = correctStroke + B + 1;
		double correctProbability = 1;
		for (int a = 0; a < A; a++) {
			correctProbability *= p[a];
		}
		expected1 = correctStroke * correctProbability + incorrectStroke * (1 - correctProbability);
		if (expected1 < expected)
			expected = expected1;
		
		// case 2
		for (int a = 1; a <= A; a++) {
			// backspace a-character
			
			correctStroke = a + a + B - A + 1;
			incorrectStroke = correctStroke + B + 1;
			correctProbability = 1;
			for (int c = 0; c < A - a; c++) {
				correctProbability *= p[c];
			}
			double tempExpected = correctStroke * correctProbability + incorrectStroke * (1 - correctProbability);
			
			if (tempExpected < expected2)
				expected2 = tempExpected;
		}
		if (expected2 < expected)
			expected = expected2;
		
		// case 3
		expected3 = 1 + B + 1;
		if (expected3 < expected)
			expected = expected3;
		
		cout << fixed;		
		cout << "Case #" << (t + 1) << ": " << setprecision(6) << expected << endl;
		out << fixed;
		out << "Case #" << (t + 1) << ": "  << setprecision(6) << expected << endl;
	}
	
	
	in.close();
	out.close();
	
    return 0;
}
