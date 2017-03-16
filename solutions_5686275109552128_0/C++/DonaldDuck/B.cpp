#include <iostream>
#include <stdio.h>
#include <cassert>
#include <algorithm>
#include <string.h>

#define MAXN 1010

using namespace std;

int A[MAXN];
int B[MAXN];

int solve() {
	int N;
	cin >> N;
	int best = 0;

	for (int i=0; i<N; i++) {
		cin >> A[i];
		B[i] = 1;
		best = max(best, A[i]);
	}
		
	sort(A, A+N);
	
	for (int i=1; i<best; i++) {
		// Trovo quello da spezzare
		int c = 0;
		for (int j=0; j<N; j++)
			if (ceil(A[j]/(1.0*B[j])) > ceil(A[c]/(1.0*B[c])))
				c = j;
				
		B[c]++;
		int tempo = 0;
		for (int j=0; j<N; j++)
			tempo = max(tempo, (int)ceil(A[j]/(1.0*B[j])));
			
		//cout << tempo << endl;
		best = min(best, tempo+i);
	}

	return best;
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
	return 0;
}
