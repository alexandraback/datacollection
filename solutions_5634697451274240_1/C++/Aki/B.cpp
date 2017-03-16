#include "cmath"
#include "cstdio"
#include <iostream>
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long i64;


int main() {
	int T; scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti) {
		fprintf(stderr, "Case #%d of %d...\n", Ti, T);

		string S;
		cin >> S;
		
		int flipping = 0;

		while (true) {
			auto lb = find(S.rbegin(), S.rend(), '-');
			if (lb == S.rend()) break;
			size_t i = S.size() - 1 - (lb - S.rbegin());

			size_t fh = S.find('+');
			if (fh == 0) {
				// flip top
				size_t fb = S.find('-');
				reverse(S.begin(), S.begin() + fb);
				for (size_t j = 0; j < fb; ++j) {
					S[j] = S[j] == '+' ? '-' : '+';
				}
				++flipping;
			} else {
				reverse(S.begin(), S.begin() + i + 1);
				for (size_t j = 0; j <= i; ++j) {
					S[j] = S[j] == '+' ? '-' : '+';
				}
				++flipping;
			}
			
		}

		printf("Case #%d: %d\n", Ti, flipping);
	}
	return 0;
}
