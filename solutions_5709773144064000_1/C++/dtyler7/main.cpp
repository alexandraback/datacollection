/* Google Code Jam 2014 - Round Q - Problem B - Cookie Clicker Alpha */
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

	FILE * o;
	fopen_s(&o, "out.txt", "w");

	// Number of test cases
	string stemp;

	getline(f, stemp);
	int T = atoi(stemp.c_str());

	// for each test case
	for (int i = 0; i < T; i++){

		getline(f, stemp);
		istringstream iss;
		iss.str(stemp);
		double C, F, X;
		iss >> C >> F >> X;
		
		// Try buying n farms
		int n = 0;
		double sec_cost = 0;
		double best_run = 0.0;
		while (1){

			// cost to buy this farm
			sec_cost += (C / (2 + n*F));

			// cost to finish
			double this_run = sec_cost + ((X - C) / (2 + n*F));

			if (best_run == 0 || best_run > this_run){
				best_run = this_run;
			}
			else{
				break;
			}

			n++;
		}

		// output
		fprintf(o, "Case #%i: %1.7f\n", i+1, best_run);
	}

}