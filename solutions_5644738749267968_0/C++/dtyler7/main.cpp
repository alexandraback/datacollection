/* Google Code Jam 2014 - Round Q - Problem D - Deceitful War */
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <set>

using namespace std;

double SmallestNotSmallerThan(set<double> set, double value){
	double v = 0;
	for (auto it = set.rbegin(); it != set.rend(); it++){
		if ((*it) > value) v = (*it);
		else break;
	}
	return v;
}

double LargestNotGreaterThan(set<double> set, double value){
	double v = 0;
	for (auto it = set.begin(); it != set.end(); it++){
		if ((*it) < value) v = (*it);
		else break;
	}
	return v;
}

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

	double tmp;

	// for each test case
	for (int i = 0; i < T; i++){

		// number of blocks
		getline(f, stemp);
		int N = atoi(stemp.c_str());

		// naomi's data
		set<double> naomi;
		getline(f, stemp);
		istringstream iss;
		iss.str(stemp);
		for (int k = 0; k < N; ++k){
			iss >> tmp;
			naomi.insert(tmp);
		}

		// ken's data
		set<double> ken;
		getline(f, stemp);
		istringstream iss2;
		iss2.str(stemp);
		for (int k = 0; k < N; ++k){
			iss2 >> tmp;
			ken.insert(tmp);
		}

		// deceitful mode
		set<double> naomi_edit(naomi);
		set<double> ken_edit(ken);

		int naomi_deceitful_points = 0;

		for (auto it = naomi.begin(); it != naomi.end(); it++){
		
			// naomi will pick her smallest block
			double naomi_block = *it;

			// largest block this might beat
			double ken_block = LargestNotGreaterThan(ken_edit, naomi_block);

			if (ken_block == 0){
				// this block can't beat anything
				// naomi will sacrifice this block to destroy ken's largest block
				ken_edit.erase(--ken_edit.end());
			}

			else{
				// point naomi!
				naomi_deceitful_points++;
				ken_edit.erase(ken_block);
			}
		}

		// normal mode
		set<double> naomi_edit2(naomi);
		set<double> ken_edit2(ken);

		// for each of naomi's blocks, ken will use the smallest one he has that beats it
		int naomi_normal_points = 0;
		
		for (auto it = naomi.begin(); it != naomi.end(); it++){
			
			// naomi will pick her smallest block
			double naomi_block = *it;

			// see if ken has a block that can take this
			double ken_block = SmallestNotSmallerThan(ken_edit2, naomi_block);

			if (ken_block == 0){
				// point naomi!
				naomi_normal_points++;

				// ken must use up his smallest block
				ken_edit2.erase(ken_edit2.begin());
			}

			else{
				// ken destroys naomi + his own block
				ken_edit2.erase(ken_block);
			}
		}

		// output

		o << "Case #" << i + 1 << ": " << naomi_deceitful_points << " " << naomi_normal_points << endl;

	}

}