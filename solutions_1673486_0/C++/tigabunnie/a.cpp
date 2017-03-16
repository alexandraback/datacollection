#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <new>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(int argc, char **argv) {
	if (argc!=3) {
		cerr << "provide input and output file names as the first 2 command line parameters\n";
		exit(1);
	}
	if (strcmp(argv[1], argv[2])==0) {
		cerr << "don't use the same input and output file names\n";
		exit(1);
	}
	
	ifstream infile;
//	ofstream outfile;
	FILE *outfile;
	
	infile.open(argv[1]);
	if (!infile.is_open()) {
		cerr << "can't open file " << argv[1] << " for reading\n";
		exit(1);
	}
	
	/*
	outfile.open(argv[2]);
	if (!outfile.is_open()) {
		cerr << "can't open file " << argv[2] << " for writing\n";
		exit(1);
	}
	*/
	outfile = fopen(argv[2],"w");
	if (outfile==NULL) {
		cerr << "can't open file " << argv[2] << " for writing\n";
		exit(1);
	}
	 
	int numCases;
	int A, B, a;
	double *probCorrect, prob, *probCorrectCumulative, *probErrorAtKey;
	
	probCorrect = new double[150000];
	probCorrectCumulative = new double[150000];
	probErrorAtKey = new double[150000];
	double solution, bestSolution, probGood, goodSolution, badSolution;
	int pressBackspace;
	
	infile >> numCases;
	for (int caseNum = 1; caseNum <= numCases; caseNum++) {
		infile >> A >> B;
		for (a=0; a<A; a++) {
			infile >> prob;
			probCorrect[a] = prob;
		}
		
		probCorrectCumulative[0] = probCorrect[0];
		for (a=1; a<A; a++) {
			probCorrectCumulative[a] = probCorrect[a] * probCorrectCumulative[a-1];
//			cout << "probCorrectCumulative " << probCorrectCumulative[a] << "\n";
		}
		
		probErrorAtKey[0] = 1.0-probCorrect[0];		//probability first key is wrong
		for (a=1; a<A; a++) probErrorAtKey[a] = probCorrectCumulative[a-1] * (1.0-probCorrect[a]);	//correct up to n-1, wrong on this key, don't care what happens later
		probErrorAtKey[A] = probCorrectCumulative[A-1];	//probability of every key correct
		/*
		double test_sum = 0;	//all keys correct
		for (a=0; a<=A; a++) test_sum += probErrorAtKey[a];
		
		if (fabs(test_sum - 1.0) > 1.0e-6) {
			cout << "error\n";
			cout << "test sum " << test_sum << "\n";
			exit(1);
		}
		*/
		
		bestSolution = 1 + B + 1;	//enter, press all keys again, enter
		probGood = 0;
		for (pressBackspace=0; pressBackspace<=A; pressBackspace++) {
			probGood += probErrorAtKey[A-pressBackspace];
			
			goodSolution = probGood*(pressBackspace+pressBackspace+B-A+1);	//hit backspace a few time, retype the characters, type the remaining, press enter
			badSolution = (1.0-probGood)*(pressBackspace+pressBackspace+B-A+1+B+1);	//same, press all keys again, press enter
			solution = goodSolution + badSolution;
			if (solution < bestSolution) bestSolution = solution;
		}
		
		fprintf(outfile, "Case #%d: %lf\n", caseNum, bestSolution);
		
	}
	infile.close();
//	outfile.close();
	fclose(outfile);
	
	
	return 0;
}
