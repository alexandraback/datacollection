#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int multTable[4][4] = { {1, 2, 3, 4},
	{2,-1, 4,-3},
	{3,-4,-1, 2},
	{4, 3,-2,-1} };


int times(int a, int b){
	int s = 1;
	if (a*b < 0) s = -1;
	a = abs(a);
	b = abs(b);
	return s*multTable[a-1][b-1];
}

bool trial(int L, string word, int Xshort, int Xmod){
	int partials[L+1];
	partials[0] = 1;
	for (int i = 1; i <= L; i++){
		int token = word[i-1] - 'g';
		partials[i] = times(partials[i-1], token);
	}

	int t = partials[L];

	// Check total
	int total = 1;
	for (int i = 0; i < Xmod; i++) total = times(total, t);
	if (total != -1) return false; 

	int targets[4];
	targets[0] = 2;
	for (int i = 1; i <= 3; i++){
		if (abs(t) == 1) targets[i] = t*targets[i-1];
		targets[i] = times((-1)*t, targets[i-1]);
	}

  for (int i = 0; i < 4; i++) cout << targets[i] << " ";
	cout << endl;

	int bestBlockI = 4;
	int bestIndexI = 0;
	for (int i = 0; i <= L; i++){
		// Search among the partials for an 'i'
		for(int block = 0; block < bestBlockI; block ++){
			if (partials[i] == targets[block]) {
				bestBlockI = block;
				bestIndexI = i;
				if (block == 0) break;
			}
		}
	}
	if (bestBlockI == 4) return false;
	cout << bestBlockI << " " << bestIndexI << endl;
  

	// Do it for end of original string
	partials[0] = 1;
	for (int i = 1; i <= L; i++){
		int token = word[L-i] - 'g';
		partials[i] = times(token, partials[i-1]);
		cout << partials[i] << " ";
	}
	cout << endl;

	cout <<"FDJSKL"<<endl;

	targets[0] = 4;
	for (int i = 1; i <= 3; i++){
		if (abs(t) == 1) targets[i] = t*targets[i-1];
		targets[i] = times(targets[i-1], (-1)*t);
	}

  for (int i = 0; i < 4; i++) cout << targets[i] << " ";
	cout << endl;

	int bestBlockK = 4;
	int bestIndexK = 0;
	for (int i = 0; i <= L; i++){
		// Search among the partials for an 'i'
		for(int block = 0; block < bestBlockK; block ++){
			if (partials[i] == targets[block]) {
				bestBlockK = block;
				bestIndexK = i;
				if (block == 0) break;
			}
		}
	}
	if (bestBlockK == 4) return false;
	cout << bestBlockK << " " << bestIndexK << endl;
  
	int extraBlocks = 1;
  if(bestIndexI + bestIndexK > L) extraBlocks = 2;
	int totalBlocks = bestBlockI + bestBlockK + extraBlocks;
	cout << totalBlocks << endl;
	if(totalBlocks <= Xshort) return true;
	return false;


}

int main(int argc, char* argv[]){
	ifstream infile (argv[1]);
	ofstream outfile("output");
	int numTests, L;
	long int X;
	string word;
	infile >> numTests;
	for(int test = 1; test <= numTests; test++){
		infile >> L >> X;
		infile >> word;

		int Xshort;
		if (X > 8) Xshort = 8;
		else Xshort = X;

		int Xmod = X % 4;

		outfile << "Case #" << test << ": ";
		if (trial(L, word, Xshort, Xmod)) outfile << "YES" << endl;
		else outfile << "NO" << endl;
	}
	return 0;
}
