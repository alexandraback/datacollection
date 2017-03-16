#include <iostream>
#include <vector>

using namespace std;

int T, E, R, N;
vector<int> v;

int solve(int i, int eGot) {
	if (i == N) return 0;
	int maxGain = 0;
	for (int eSpend = eGot; eSpend >= 0; --eSpend) {
		int eNext = R + eGot - eSpend;
		int gain = v[i] * eSpend + solve(i + 1, min(eNext, E));
		if (gain > maxGain)
			maxGain = gain;
		if (eNext > E)
			break;
	}
	return maxGain;
}

int main(int argc, char* argv[]) {
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> E >> R >> N;
		v.resize(N);
		for (int n = 0; n < N; ++n)
			cin >> v[n];
		cout << "Case #" << (t + 1) << ": " << solve(0, E) << "\n";
	}
	return 0;
}

