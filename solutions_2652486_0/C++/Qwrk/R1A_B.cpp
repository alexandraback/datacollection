#include <iostream>
#include <vector>


int solve (int *_k, int _K, int _M, int _N)
{
	int Z[4] = { 2, 3, 4, 5 };
	int n[3]; bool found = false;
	for (int i = 0; i < 4 && !found; ++i) {
		n[0] = Z[i];
		for (int j = 0; j < 4 && !found; ++j) {
			n[1] = Z[j];
			for (int k = 0; k < 4 && !found; ++k) {
				n[2] = Z[k];

				int tt = 0;
				for (int l = 0; l < _K; ++l) {
					int tn = _k[l];
					for (int m = 0; m < 3; ++m) {
						if (!(tn % n[m])) {
							tn /= n[m];
						}
						if (tn == 1) {
							++tt; break;
						}
					}
				}
				if (tt == _K) {
					found = true;
				}
			}
		}
	}

	return n[0] * 100 + n[1] * 10 + n[2];
}


int main()
{
	int T, R, N, M, K;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cout << "Case #1:\n";
		std::cin >> R >> N >> M >> K;
		while (R--) {
			int *k = new int[K];
			for (int i = 0; i < K; ++i) {
				std::cin >> k[i];
			}
			std::cout << solve (k, K, M, N) << '\n';
			delete[] k;
		}
	}


	return 0;
}