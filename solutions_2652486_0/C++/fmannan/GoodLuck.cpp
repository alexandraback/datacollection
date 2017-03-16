#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

bool isValid(int comb[3], int val) {
	if(val == 1) return true;
	// factorize using comb
	int tmp = val;
	for(int i = 0; i < 3; i++) {
		if(tmp % comb[i] == 0) tmp = tmp / comb[i];
	}
	if(tmp == 1) return true;
	return false;
}

int main(int argc, char ** argv) {
	int T;
	cin >> T;
	for(int tcases = 1; tcases <= T; tcases++) {

		cout << "Case #" << tcases << ":" << endl;

		int R, N, M, K;
		cin >> R >> N >> M >> K;
		// N = 3, M = 5
		// generate all possible combinations
		int combinations[64][3];
		int idx = 0;
		for(int a0 = 2; a0 <= 5; a0++) {
			for(int a1 = a0; a1 <= 5; a1++) {
				for(int a2 = a1; a2 <= 5; a2++) {
					combinations[idx][0] = a0;
					combinations[idx][1] = a1;
					combinations[idx][2] = a2;
					
					//cout << idx << ". " << a0 << a1 << a2 << endl;
					idx++;
				}
			}
		}
		int combinationCount = idx;
		//cout << combinationCount << endl;
		int values[20]; // size of K
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < K; j++) {
				cin >> values[j];
			}

			// check if each combination can produce that number
			int jj;
			for(jj = 0; jj < combinationCount; jj++) {
				int k;
				for(k = 0; k < K; k++) {
					if(values[k] == 1) continue; // skip 1s					
					else if(!isValid(combinations[jj], values[k])) {
						break;
					}
				}
				if(k == K) {// found a solution
					cout << combinations[jj][0] << combinations[jj][1] << combinations[jj][2] << endl;
					break;
				}
			}
			if(jj == combinationCount) // not found
				cout << "222" << endl;
		}
	}
	return 0;
}