/* Google Code Jam 2014 - Round Q - Problem C - Cookie Clicker Alpha */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void main(int argv, char** argc){

	if (argv < 2){
		cout << "Missing input file!" << endl;
		return;
	}

	ifstream f(argc[1]);

	ofstream o("out.txt");

	// Number of test cases
	string stemp;

	getline(f, stemp);
	int T = atoi(stemp.c_str());

	// for each test case
	for (int i = 0; i < T; i++){

		getline(f, stemp);
		istringstream iss;
		iss.str(stemp);
		int R, C, M;
		iss >> R >> C >> M;

		// Assume the player clicks the top left cell
		// Assume all the free squares form a compact block around that cell

		// How many free cells?
		int F = R*C - M;

		bool win = false;
		bool shuffle_s_to_p = false;
		int n = 1;

		// Special case: Only 1 free cell (the Click cell) is an automatic win
		if (F == 1) win = true;

		// Try putting all the free cells in n [1,c] wide columns
		if (!win) for (n = 1; n <= C; n++){

			// Rows < F/n will contain [0,n] spaces
			// Row == F/n will contain F%n spaces
			// Rows > F/n will contain 0 free spaces

			// This is invalid if n*R < F (not enough space for all frees)
			if ((R * n) < F) continue;

			// This is invalid if n == c (full width) and <= 1 standard row and at least 1 more element
			if (n == C && (F / n) <= 1 && R > 1) continue;

			// This is invalid if n == 1 (single column) and c > 1
			if (n == 1 && C > 1) continue;

			// This is invalid if n < C (not full width) and <= 2 standard rows
			if (n < C && (F / n) < 2) continue;

			// This is invalid if C > 1 and the last row has a single element
			// well ... not quite ... we can sometimes fudge stuff and this is actually OK
			if (C > 1 && (F % n) == 1){

				// actually a problem when n < 3 or < 3 standard rows or 
				if (n < 3 || (F / n) < 3) continue;

				// not a problem otherwise ... just shuffle the last standard row to the partial row
				else {
					win = true;
					shuffle_s_to_p = true;
					break;
				}
			}

			// Otherwise, we found a winning format!
			win = true;
			break;
		}

		// output
		o << "Case #" << i + 1 << ":" << endl;
		if (!win){
			o << "Impossible" << endl;
		}
		else{
			// generate the winning map
			int pos = 0;
			for (int i = 0; i < R; ++i){
				for (int j = 0; j < C; ++j){
					pos++;
					if (pos == 1)
						o << "c"; // start

					else if (shuffle_s_to_p && ((i == F / n - 1) && (j == n - 1)))
						o << "*"; // shufflee

					else if (shuffle_s_to_p && ((i == F / n) && (j == F%n)))
						o << "."; // shuffle target

					else if ((i < F / n) && (j < n))
						o << "."; // free, standard row

					else if ((i == F / n) && (j < F%n))
						o << "."; // free, partial row

					else
						o << "*";
				}
				o << endl;
			}
		}
	}
}