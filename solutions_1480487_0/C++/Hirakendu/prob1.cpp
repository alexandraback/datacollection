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
		int n;
		input_stream >> n;
		double *s = new double[n];
		for (int i = 0; i < n; i++) {
			input_stream >> s[i];
		}

		// 1.1 Verbose input.

		// 2. Algorithm.
		double S = 0;
		for (int i = 0; i < n; i++) {
			S += s[i];
		}
		double *y = new double[n];
		for (int i = 0; i < n; i++) {
			y[i] = (2.0 / n) - (s[i] / S);
			if (y[i] < 0) {
				y[i] = 0;
			}
		}
		double Sg = 0;
		int ng = 0;
		for (int i = 0; i < n; i++) {
			if (y[i] > 0) {
				ng++;
				Sg += s[i];
			}
		}
		cout << ng << " " << Sg << " " << S << endl;
		for (int i = 0; i < n; i++) {
			if (y[i] > 0) {
				y[i] = (1.0 / ng) + (Sg / (S * ng))
						- (s[i] / S);
			}
		}
		for (int i = 0; i < n; i++) {
			// cout << " " << setiosflags(ios::fixed)
			// << setprecision(6) << 100 *y[i];
		}
		cout << endl;


		// 3. Output.
		output_stream << "Case #" << i_case << ":";
		for (int i = 0; i < n; i++) {
			//output_stream << " " << setprecision(7) << 100 * y[i];
			output_stream << " " << setiosflags(ios::fixed)
							<< setprecision(6) << 100 * y[i];
		}
		output_stream << endl;

		// 3.1 Cleanup.

	}

	// Regular cleanup.
	input_stream.close();
	output_stream.close();

	return 0;
}

