#include <iostream>
#include <list>

using namespace std;

int calculate(int A, int N, list<int> motes) {
	int i, j;
	int c = 0;
	int t, tc;
	int left = N;
	int worstCase = 10e6;

	list<int>::iterator it;
	if (A == 1) {
	     return N;
	}

	for (it=motes.begin(); it!=motes.end(); ++it) {
		j = *it;

		// cout << A << ' ' <<  j << endl;
		if (A > j) {
			A += j;
		} else {
			// what to do?
			// pop or append?
			t = A;
			tc = 0;
			do {
				t = t * 2 -1;
				tc++;
			} while (t <= j);

			if (left + c < worstCase) {
				worstCase = left + c;
			}

			if (tc > left) {
				tc = c + left;
				if (tc > worstCase) {
					return worstCase;
				} else {
					return tc;
				}
			}

			A = t + j;
			c += tc;
		}
		--left;
	}
	if (worstCase > c) {
		return c;
	} else {
		return worstCase;
	}
}

int main() {
	int T;
	int A, N;
	int i, j;
	int t;
	list<int> motes;

	cin >> T;

	for (i = 1;  i <= T; ++i) {
		cin >> A >> N;
		motes.clear();
		for (j = 0; j < N; ++j) {
			cin >> t;
			motes.push_back(t);
		}
		motes.sort();
		cout << "Case #" << i << ": " << calculate(A, N, motes) << endl;
	}
}
