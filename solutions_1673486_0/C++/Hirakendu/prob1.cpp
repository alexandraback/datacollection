#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

/*
 * Hirakendu Das. Google Code Jam 2012.
 *
 */

int main(int argc, char *argv[])
{
	// Parse arguments.
	string input_file;
	string output_file;
	int verbose_level = 2;
	string arg;
	stringstream input_args;
	for (int i = 1; i != argc; ++i) {
		input_args << " " << argv[i];
	}
	while (!input_args.eof()) {
		input_args >> arg;
		if (arg == "-i") {
			input_args >> input_file;
		} else if (arg == "-o") {
			input_args >> output_file;
		} else if (arg == "-v") {
			input_args >> verbose_level;
		}  else if (arg != "") {
			cout << "Error parsing argument \"" << arg
					<< "\"." << endl;
			return 0;
		}
	}
	if (input_file == "") {
		input_file = "input.txt";
	}
	if (output_file == "") {
		output_file = "output.txt";
	}

	ifstream input_stream(input_file.c_str());
	ofstream output_stream(output_file.c_str());

	// Scan inputs, run the algorithm, store the output.
	int num_cases;
	input_stream >> num_cases;
	string to_clear;
	getline(input_stream, to_clear);
	if (verbose_level >= 2) {
	    cout << "  Number of test cases: " << num_cases << endl;
	}
	for (int i_case = 1; i_case <= num_cases; ++i_case) {
		if  (verbose_level >= 1) {
		    cout << "  Case #" << i_case << ":" << endl;
		}
		// 1. Input.
		int A, B;
		input_stream >> A >> B;
		double *p_i = new double[A];
		for (int i = 0; i < A; i ++) {
			input_stream >> p_i[i];
		}

		// 1.1 Verbose input.
		cout << " " << A << " " << B << endl;
		for (int i = 0; i < A; i ++) {
			cout <<  " " << p_i[i];
		}
		cout << endl;

		// 2. Algorithm.
		// p = probability of no errors.
		double p = 1;
		for (int i = 0; i <= A - 1; i++) {
			p = p * p_i[i];
		}
		// Initialize expectations to case when no mistakes.
		double *e_j = new double[A + 2]; // j = # backstrokes. j = 0 => continue. j = A + 1, enter straightaway.
		e_j[A + 1] = B + 2;
		for (int j = 0; j <= A; j++) {
			e_j[j] = p * (2 * j + B - A + 1);
		}
		for (int i = A - 1; i >= 0; i--) { // Location of first mistake.
			p = 1;
			for (int i1 = 0; i1 < i; i1++) {
				p = p * p_i[i1];
			}
			p *= (1 - p_i[i]);
			for (int j = 0; j <= A; j++) {
				if (i >= A - j) {
					e_j[j] += p * (2 * j + B - A + 1);
				} else {
					e_j[j] += p * (2 * j + B - A + 1 + B + 1);
				}
			}
		}
		double min = e_j[0];
		cout << e_j[0] << " ";
		for (int j = 1; j <= A + 1; j++) {
			cout << e_j[j] << " ";
			if (min > e_j[j]) {
				min = e_j[j];
			}
		}
		cout << endl;
		cout << "min = " << min << endl;


		// 3. Output.
		output_stream << "Case #" << i_case << ": " << setiosflags(ios::fixed)
				<< setprecision(6) << min << endl;

		// 3.1 Cleanup.

	}

	// Regular cleanup.
	input_stream.close();
	output_stream.close();

	return 0;
}

