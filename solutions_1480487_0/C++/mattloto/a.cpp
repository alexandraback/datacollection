#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream fin("a.in");
	ofstream fout("a.out");
	fout.precision(7);
	fout.setf(ios::fixed,ios::floatfield);
	int T;
	fin >> T;
	for (int t = 0; t < T; t++) {
		int N;
		fin >> N;
		int x = 0;
		int * scores = new int[N];
		double * answer = new double[N];
		/*
		int lowestScore;
		int lowestIndex;
		fin >> scores[0];
		lowestScore = scores[0];
		lowestIndex = 0;
		x = scores[0];
		*/
		for (int i = 0; i < N; i++) {
			fin >> scores[i];
			x += scores[i];
			/*
			if (scores[i] < lowestScore) {
				lowestScore = scores[i];
				lowestIndex = i;
			}
			*/
		}
		fout << "Case #" << (t+1) << ": ";
		double negTotal = 0;
		int negCount = 0;
		for (int i = 0; i < N; i++) {
			int sumLow = 0;
			int numLow = 0;
			for (int j = 0; j < N; j++) {
				if (i==j) continue;
				if (scores[j] <= scores[i]) {
					sumLow += scores[j];
					numLow++;
				}
			}
			if (numLow == 0) numLow = 1;
			//double y = (double)(sumLow + x - scores[i] * numLow)/(double)(x * numLow * (1 + 1/(double)numLow));
			//double y = (double)(x - scores[i] + x - (scores[i] * (N-1)))/(double)(x * N);
			double y = (double)(2 * x - scores[i] * N) / (double)(N * x);
			if (y < 0.0) {
				negTotal -= y;
				answer[i] = 0;
				negCount++;
			}
			else answer[i] = y;
			//fout << (y * 100.0) << ' ';
		}
		double neg = 0.0;
		if (negCount != 0) neg = negTotal / (double)(N-negCount);
		for (int i = 0; i < N; i++) {
			if (answer[i] != 0.0) {
				fout << 100.0 * (answer[i] - neg) << ' ';
			}
			else fout << "0.0 ";
		}
		fout << endl;
	}
}