#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

#define MAXD 1000
#define MAXP 1000

using namespace std;

int main() {
	//freopen("tmp.txt", "r", stdin);	

	int t, T;
	cin >> T;
	for (t = 0; t < T; ++t) {
		int D;
		cin >> D;

		int m[MAXP+10] = {0};
		
		for (int i = 0; i < D; ++i) {
			int p;
			cin >> p; 
			m[p]++;
		}

		int res[MAXP+10] = {0};

		for (int i = MAXP+5; i >= 1; --i) {
			if (m[i] != 0) {
				for (int j = 1; j < i; ++j) {
					if ((i%j) == 0) {
						res[j] += m[i]*((i/j)-1);
					} else {
						res[j] += m[i]*(i/j);
					}
				}				
			}
		}

		int best = res[1] + 1;
		for (int i = 2; i <= MAXP; ++i) {
			best = min(best, res[i]+i);
		}




		cout << "Case #" << (t+1) << ": " << best << endl;
	}
	return 0;
}