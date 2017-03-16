#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t >> ws;

	for (int i = 1; i <= t; ++i) {
		uint64_t A, B, K, R = 0;
		input >> A >> B >> K;

		if (B < A)
			swap(A, B);
		K = min(A, K);

		// All cases where (a < K) || (b < K)
		R += (K*B) + (K*A) - K*K;

		for (uint64_t a = K; a < A; ++a) {
			for (uint64_t b = K; b < B; ++b) {
				if ((a&b) < K)
					++R;
			}
		}


		output << "Case #" << i << ": " << R << endl;
	}


	return 0;
}

