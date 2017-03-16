#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <sstream>

using namespace std;

ofstream fout("output.txt");
ifstream fin("input.txt");

void Target() {
	long long R, T;
	fin >> R >> T;
	
	long long answer = (1 - 2*R + floor(sqrt((long double)(4*R*R - 4*R + 1 + 8*T))))/4;
	fout << answer << endl;
}

void Energy() {
	int E, R, N;
	fin >> E >> R >> N;
	int Activities[10100];
	for (int i=0; i<N; ++i)
		fin >> Activities[i];
	if (R >= E) {
		int Score = 0;
		for (int i=0; i<N; ++i)
			Score += Activities[i] * E;
		fout << Score << endl;
		return;
	}
	int MaxSteps = floor((double)E / (double)R);

	int CurrentE = E;
	int CurrentN = 0;
	int Score = 0;

	while (CurrentN < N) {
		int NextA = Activities[CurrentN];
		if (CurrentN == N-1) {
			Score += CurrentE*NextA;
			break;
		}
		int BestA = 0;
		int BestIndex = -1;
		for (int j=CurrentN+1; j<=CurrentN+MaxSteps; ++j) {
			if (j >= N)
				break;
			if (Activities[j] > BestA) {
				BestA = Activities[j];
				BestIndex = j;
				if (BestA > NextA)
					break;
			}
		}
		if (BestA >= NextA) {
			int Diff = (BestIndex - CurrentN)*R;
			if (CurrentE + Diff > E) {
				int Spend = CurrentE - (E - Diff);
				Score += Spend*NextA;
				CurrentE -= Spend;
			}
			CurrentE += Diff;
			CurrentN = BestIndex;
		}
		else {
			int Spend = CurrentE;
			Score += Spend * NextA;
			CurrentE -= Spend;

			int Diff = (BestIndex - CurrentN)*R;
			CurrentE += Diff;
			CurrentN = BestIndex;
		}
	}

	fout << Score << endl;
}

int main() {
	int N;
	fin >> N;
	for (int i=1; i<=N; ++i) {
		fout << "Case #" << i << ": ";
		// Call function
		//Target();
		Energy();
	}
	return 0;
}