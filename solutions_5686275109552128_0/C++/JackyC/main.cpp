#include <iostream>

using namespace std;

void formatOutput(int nCase, int sol) {
	cout << "Case #" << nCase+1 << ": " << sol << endl;
}

void solve(int nCase) {
	int sol = 99999;
	int nPlates = 0;
	cin >> nPlates;

	int* plates = new int[nPlates];
	int nMax = 0;
	for (int i=0; i<nPlates; i++) {
		cin >> plates[i];
		nMax = max(plates[i], nMax);	
	}
	
	for (int i=1; i<=nMax; i++) {
		int dum = 0;	
		for (int j=0; j<nPlates; j++) {
			int val = plates[j]/i;
			if (plates[j]%i == 0) {
				val -= 1;
			}
			dum += val;
		}
		sol = min(sol, dum+i);
	}

	formatOutput(nCase, sol);
}

int main() {
	int nCase = 0;
	cin >> nCase;

	for (int i=0; i<nCase; i++) {
		solve(i);
	}
}
