#include<iostream>
#include<fstream>
#include<vector>
#include <algorithm>


using namespace std;

int DeceitfulWar(vector<double> Naomi, vector<double> Ken, int size) {
	int currentIndexN = 0;
	int lowerBoundK = 0;
	int upperBoundK = size - 1;

	int numNaomiWins = 0;

	for (int i = 0; i < size; ++i) {
		if (Naomi[i] > Ken[lowerBoundK]) {
			++numNaomiWins;
			++lowerBoundK;
		}
		else {
			--upperBoundK;
		}
	}

	return numNaomiWins;
}

int TruthfulWar(vector<double> Naomi, vector<double> Ken, int size) {
	int currentIndexN = 0;
	int lowerBoundK = 0;
	int upperBoundK = size - 1;

	int numNaomiWins = 0;

	for (int i = size - 1; i >= 0; --i) {
		if (Naomi[i] > Ken[upperBoundK]) {
			++numNaomiWins;
			++lowerBoundK;
		}
		else {
			--upperBoundK;
		}
	}
	return numNaomiWins;
}


int main() {

	string FILENAME = "D-small-attempt0.in";
	string OUT_FILENAME = "output.out";

	ifstream inputfile;
	inputfile.open(FILENAME);
	int testCases;
	ofstream outfile;
	outfile.open(OUT_FILENAME);
	outfile.precision(10);



	inputfile >> testCases;

	for (int i = 1; i <= testCases; ++i) {
		int size;
		inputfile >> size;
		vector<double> N(size);
		vector<double> K(size);
		for (int j = 0; j < size; ++j) {
			inputfile >> N[j];
		}
		for (int j = 0; j < size; ++j) {
			inputfile >> K[j];
		}
		sort(N.begin(), N.end());
		sort(K.begin(), K.end());
//		for (int j = 0; j < size; ++j) {
//			cout << N[j] << " ";
//		}
		outfile << "Case #" << i << ": " << DeceitfulWar(N, K, size) << " " << TruthfulWar(N, K, size) << endl;
	}

	return 0;

}