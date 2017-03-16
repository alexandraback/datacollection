#include <iostream>
#include <vector>

using namespace std;

typedef vector<long long> gains_t;
typedef vector<int> values_t;

long long energy(int E, int R, int N, const values_t &v) {
	gains_t gains(E + 1);
	gains_t prev_gains(E + 1);

	for(int e = 0; e <= E; ++e) {
		gains[e] = e * v[N-1];
	}

	for(int i = N-2; i >= 0; --i) {
		for(int Einit = 0; Einit <= E; ++Einit) {
			long long max_gain = 0;
			for(int e = 0; e <= Einit; ++e) {
				max_gain = max(max_gain, e * v[i] + gains[min(E, Einit - e + R)]);
			}
			prev_gains[Einit] = max_gain;
		}
		swap(gains, prev_gains);
	}
	return gains[E];
}

int main(int argc, char **argv) {
	int T, E, R, N;
	cin >> T;
	
	for(int t = 1; t <= T; ++t) {
		cin >> E >> R >> N;
		values_t v(N);
		for(int i = 0; i < N; ++i) {
			cin >> v[i];
		}
		cout << "Case #" << t << ": " << energy(E, R, N, v) << endl;
	}
	return 0;
}
