#include <assert.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
	int 	T;

	cin >> T;
	assert(T > 0 && T <= 100);

	int N, S, p;
	for (int i = 0; i < T; i++) {
		cin >> N >> S >> p;
		assert(N > 0 && S >= 0 && S <= N && p >= 0 && p <= 10);
//		cout << "N = " << N << "; S = " << S << "; p = " << p << endl;

		int upper		= 3 * p - 2;
		int	lower 		= max(3 * p - 5, 0);
		int middle 		= 0;
		int qualified 	= 0;
		int total;
		for (int j = 0; j < N; ++j) {
			cin >> total;
			if (total >= upper) {
				qualified++;
			} else if (total > lower) {
				middle++;
			}
		}
//		cout << "qualified = " << qualified << "; middle = " << middle << "; p = " << p << endl;
		qualified += min(middle, S);
		cout << "Case #" << i+1 << ": " << qualified << endl;
	}

	return 0;
}
