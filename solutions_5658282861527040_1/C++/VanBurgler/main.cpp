#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		uint32_t A, B, K;
		cin >> A >> B >> K;

		if (K > A) K = A;
		if (K > B) K = B;

		if (B < A) {
			uint32_t temp = B;
			B = A;
			A = temp;
		}

		uint32_t fnumbers = 0;

		// B - A
		fnumbers += K * (A - K);
		fnumbers += (B - K) * K;
		fnumbers += K * K;

		for (uint32_t a = K; a < A; a++)
			for (uint32_t b = K; b < B; b++)
				if ((a & b) < K)
					fnumbers++;		

		cout << "Case #" << (i+1) << ": ";
		cout << fnumbers;
		cout << endl;
	}

	return 0;
}