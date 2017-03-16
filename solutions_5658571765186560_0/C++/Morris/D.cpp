#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

bool test(int X, int R, int C){
	if (X == 1) return true;
	if (X >= 7) return false;
	if ((R*C)%X != 0) return false;
	if (X == 2) return true;
	if (R <= 1 || C <= 1) return false;
	if (X == 3) return true;
	if (R <= 2 || C <= 2) return false;
	return true;
}

int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	ofstream outfile("output");

	int numTrials, X, R, C;
	infile >> numTrials;
	for (int trial = 1; trial <= numTrials; trial ++){
		outfile << "Case #" << trial << ": ";
		infile >> X >> R >> C;
		if (test(X,R,C)) outfile << "GABRIEL" << endl;
		else outfile << "RICHARD" << endl;
	}
}
