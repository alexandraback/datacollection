#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

//
// Definitions, typedefs
//

// Typedef for numbers
typedef long long number;

// Type storing the problems
struct problemType {
	number x, y;
};

struct solutionType {
	string s;
	number n;
};

map<number, map<number, solutionType> > solutions;
number jumplength;

/**
 * Reads in one problem, and puts it into the 
 */
problemType* readProblem(ifstream* inputFile, number t) {
	//cerr << "DEBUG: Reading problem #" << t << endl;
	problemType* problem = new problemType();

	(*inputFile) >> problem->x >> problem->y;

	return problem;
}

void increaseSolutions() {
	//cout << "=========" << endl;
	map<number, map<number, solutionType> > temp;
	for (map<number, map<number, solutionType> >::iterator x = solutions.begin(); x != solutions.end(); x++) {
		for (map<number, solutionType>::iterator y = solutions[x->first].begin(); y != solutions[x->first].end(); y++) {
			number X = x->first;
			number Y = y->first;
			number JL = solutions[X][Y].n;
			string s = solutions[X][Y].s;
			temp[X + JL][Y] = {s + "E", JL+1};
			temp[X - JL][Y] = {s + "W", JL+1};
			temp[X][Y + JL] = {s + "N", JL+1};
			temp[X][Y - JL] = {s + "S", JL+1};
		}
	}
	for (map<number, map<number, solutionType> >::iterator x = temp.begin(); x != temp.end(); x++) {
		for (map<number, solutionType>::iterator y = temp[x->first].begin(); y != temp[x->first].end(); y++) {
			number X = x->first;
			number Y = y->first;
			if (solutions.find(X) == solutions.end()
					|| solutions.at(X).find(Y) == solutions.at(X).end()) {
				//cout << "No " << X << " " << Y << " " << temp[X][Y].s << endl;
				solutions[x->first][y->first] = temp[X][Y];
			}
		}
	}
	for (map<number, map<number, solutionType> >::iterator x = solutions.begin(); x != solutions.end(); x++) {
		for (map<number, solutionType>::iterator y = solutions[x->first].begin(); y != solutions[x->first].end(); y++) {
			//cout << x->first << " " << y->first << " " << solutions[x->first][y->first].s << endl;
		}
	}
}

string solveProblem(problemType* problem, number t) {
	//cerr << "DEBUG: Solving problem #" << t << endl;
	while (solutions.find(problem->x) == solutions.end() || solutions.at(problem->x).find(problem->y) == solutions.at(problem->x).end() ) {
		increaseSolutions();
	}
	return solutions[problem->x][problem->y].s;
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
	// Prefill solutions
	solutions[0][0] = {"", 1};
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