// g++ -std=c++0x p2.cpp; ./a.out < IN > OUT
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

size_t f(size_t k, size_t v, size_t R, size_t E, const vector <size_t>& best, size_t i) {
	return k * v + best[min(i - k + R, E)];
}

size_t dw() {
	size_t E, R, N;
	cin >> E >> R >> N;
	vector <size_t> vi(N);
	for (size_t i = 0; i < N; i++) {
		cin >> vi[i];
	}

	vector <size_t> best(E + 1);
	size_t horizon = N - 1;
	for (size_t i = 0; i <= E; i++) {
		best[i] = i * vi[horizon];
	}

	while (horizon > 0) {
		size_t v = vi[horizon - 1];
		vector <size_t> bestp(E + 1, 0);
		for (size_t i = 0; i < bestp.size(); i++) {
			for (size_t k = 0; k <= i; k++) {
				bestp[i] = max(bestp[i], f(k, v, R, E, best, i));
			}
			/* size_t lo = 0, hi = i, ans;
			while (lo <= hi) {
				size_t mid = lo + (hi - lo) / 2;
				
			}

			bestp[i] = max(f(0, v, R, E, best), f(i, v, R, E, best));
			bestp[i] = max(f(ans, v, R, E, best), bestp[i]); */
		}
		best = bestp;

		horizon--;
	}

	return best[E];
}

int main() {
	size_t T;
	cin >> T;
	for (size_t t = 0; t < T; t++) {
		cout << "Case #" << (t + 1) << ": " << dw() << endl;
	}
	return 0;
}

