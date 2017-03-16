#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//
// Definitions, typedefs
//

// Typedef for numbers
typedef unsigned long number;

// Type storing the problems

struct problemType {

	number n;
	string s;
};

/**
 * Reads in one problem, and puts it into the 
 */
problemType* readProblem(ifstream* inputFile, number t) {
	//cerr << "DEBUG: Reading problem #" << t << endl;
	problemType* problem = new problemType();

	(*inputFile) >> problem->s >> problem->n;

	return problem;
}

bool isConsonant(char c) {
	return (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

number solveProblem(problemType* problem, number t) {
	//cerr << "DEBUG: Solving problem #" << t << endl;
	number sol = 0;
	for (number a = 0; a < problem->s.length(); a++) {
		for (number b = a + problem->n - 1; b < problem->s.length(); b++) {
			number i = a;
			number consonants = 0;
			number maxConsonants = 0;
			while (i <= b) {
				//cerr << problem->s.at(i);
				if (isConsonant(problem->s.at(i))) {
					consonants++;
					if (maxConsonants < consonants) {
						maxConsonants = consonants;
					}
				} else {
					consonants = 0;
				}
				i++;
			}
			//cerr << endl;
			if (maxConsonants >= problem->n) {
				sol++;
			}
		}
	}
	return sol;
}

/**
 * Program entry point. Reads in the input and passes everything to worker
 * functions.
 */
int main(int argc, char* argv[]) {
	// "Validate" arguments
	if (argc != 2) {
		cerr << "Usage: solver <input-file>" << endl;
		cerr << "ERROR: Wrong number of arguments!" << endl;
		return 1;
	}
	// Try to open input file
	ifstream* inputFile = new ifstream();
	inputFile->open(argv[1], ifstream::in);
	if (!inputFile->is_open()) {
		cerr << "ERROR: Could not open '" << argv[1] << "'." << endl;
		return 1;
	}
	// Read all the problems
	number T;
	(*inputFile) >> T;
	//cerr << "DEBUG: Processing " << T << " problems." << endl;
	for (number t = 1; t <= T; t++) {
		problemType* problem = readProblem(inputFile, t);
		cout << "Case #" << t << ": " << solveProblem(problem, t) << endl;
	}
	return 0;
}