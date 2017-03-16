#include <iostream>
#include <cstdio>
using namespace std;

int K, C, S;
long long len;

int main() {
	int Tc; cin >> Tc;
	for (int T = 1; T <= Tc; ++T) {
		printf("Case #%d: ", T);
		cin >> K >> C >> S;
		len = 1; for (int i = 0; i < C; ++i) len *= K;
		if (C == 1) {
			if (S < K) { printf("IMPOSSIBLE\n"); continue; }
			for (int i = 1; i <= K; ++i) printf("%d ", i); printf("\n"); continue;
		}
		if (S < (K + 1) / 2) { printf("IMPOSSIBLE\n"); continue; }
		long long pos = 0;
		for (int i = 2; i <= K; i += 2) {
			printf("%lld ", pos + i); 
			pos += len / K * 2; 
		}
		if (K % 2) printf("%d ", K); printf("\n");
	}
}