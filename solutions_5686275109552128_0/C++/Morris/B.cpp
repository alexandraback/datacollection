#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int numSteps(int D, int* P){
	int best = 1001;
	int numSplits;
	for (int maxStack = 1000; maxStack > 0; maxStack --){
		numSplits = 0;
		for (int i = 0; i < D; i++){
			numSplits += (P[i] - 1)/maxStack;
		}
		if (best > numSplits + maxStack) best = numSplits + maxStack;
	}
	return best;
}

int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	ofstream outfile("output");
	int numTrials, D;
	int P[1000];

	infile >> numTrials;
	for(int trial = 1; trial <= numTrials; trial ++){
		infile >> D;
		for (int j = 0; j < D; j++) infile >> P[j];
		outfile << "Case #" << trial << ": ";
		outfile << numSteps(D,P) << endl;
	}
}
