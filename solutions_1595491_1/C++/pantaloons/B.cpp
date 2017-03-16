#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int cc = 0; cc < T; cc++) {
		int N, S, p;
		cin >> N >> S >> p;
		vector<int> sums(N, 0);
		for(int i = 0; i < N; i++) cin >> sums[i];
		
		int good = 0, surprise = 0;
		for(int i = 0; i < N; i++) {
			if(sums[i] == 0) {
				if(p == 0) good++;
			}
			else if(sums[i] % 3 == 0) {
				int x = sums[i] / 3;
				if(x >= p) good++;
				else if(x + 1 >= p) surprise++;
			}
			else if(sums[i] % 3 == 1) {
				int x = 1 + (sums[i] / 3);
				if(x >= p) good++;
			}
			else if(sums[i] % 3 == 2) {
				int x = 1 + (sums[i] / 3);
				if(x >= p) good++;
				else if(x + 1 >= p) surprise++;
			}
		}
		cout << "Case #" << cc + 1 << ": " << good + min(surprise, S) << endl;
	}
}
