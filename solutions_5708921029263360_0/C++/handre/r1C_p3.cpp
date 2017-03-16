#include <cstdio>
#include <iostream>
#include <string>

int main(void) {

	int J, P, S, K;
	
	int cntJP[16][16], cntJS[16][16], cntPS[16][16];

	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++) {
		printf("Case #%i: ", t + 1);
		std::cin >> J >> P >> S >> K;

		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 16; j++) cntJP[i][j] = cntJS[i][j] = cntPS[i][j] = 0;
		}

		std::string out;
		int outCnt = 0;
		for (int j = 0; j < J; j++) {
			for (int p = 0; p < P; p++) {
				for (int s = 0; s < S; s++) {
					if (cntJP[j][p] < K && cntJS[j][s] < K && cntPS[p][s] < K) {
						cntJP[j][p]++;
						cntJS[j][s]++;
						cntPS[p][s]++;

						char buff[128];
						sprintf(buff, "%i %i %i\n", j + 1, p + 1, s + 1);

						out = out + std::string(buff);
						outCnt++;
					}
				}
			}
		}
		printf("%i\n%s", outCnt, out.c_str());
	}
	return 0;
}