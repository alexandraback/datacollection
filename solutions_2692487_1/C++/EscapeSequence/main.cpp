#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vint;
typedef vector<int>::iterator vintit;

int process(int A, int N, vint motes) {
	sort(motes.begin(), motes.end());

	int optimal = -1, nAdded = 0;

	int i;
	for(i = 0; i < N; i++) {
		//cout << i << " -> " << motes[i] << ", have " << A << endl;
		while(motes[i] >= A) {
			A += (A-1);
			if(optimal == -1 || optimal > (N-i+nAdded)) optimal = N-i+nAdded;
			if(A == 1) return optimal;
			nAdded++;
			//cout << "Added!" << endl;
		}
		A += motes[i];
	}
	if(optimal == -1 || optimal > (N-i+nAdded)) optimal = N-i+nAdded;

	return optimal;
}

int main(int argc, char ** argv) {
	string filein = "tmp.dat";
	if(argc >= 2) filein = argv[1];
	ifstream in(filein.c_str());

	int T; in >> T;
	//cout << T << endl;
	for(int c = 1; c <= T; c++) {
		cout << "Case #" << c << ": ";
		int A, N; in >> A >> N;
		//cout << "A N = " << A << " " << N << endl;
		vint motes(N);
		for(int n = 0; n < N; n++) { in >> motes[n]; }
		
		cout << process(A, N, motes);
		cout << endl;
	}

	return 0;
}
