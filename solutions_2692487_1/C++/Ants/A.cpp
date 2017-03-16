#include <iostream>
#include <algorithm>

using namespace std;

int motes[200];
int N;

int solve(int A, int m);

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int A;
		cin >> A >> N;
		for (int n = 0; n < N; n++)
			cin >> motes[n];
		sort(motes, motes+N);
		if (A > 1) cout << "Case #" << t << ": " << solve(A,0) << endl;
		else cout << "Case #" << t << ": " << N << endl;
	}
}

int solve(int A, int m) {
	if (m >= N) return 0;
	while (m < N && motes[m] < A)
		A += motes[m++];
	int sol1 = N - m;
	int sol2 = 0;
	while (motes[m] >= A) {
		sol2 ++;
		A += A-1;
	}
	sol2 += solve(A,m);
	return sol2 < sol1 ? sol2 : sol1;
}
