#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	freopen("D-large.in.txt", "r", stdin);
	//freopen("D-large-practice.in", "r", stdin);
	freopen("large.out", "w", stdout);
	long long T;
	cin >> T;
	for (long long i = 1; i <= T; i++) {
		long long K, C, S;
		cin >> K >> C >> S;
		printf("Case #%lld:", i);
		if (S >= ceil(floor(K)/C)) {
			for (long long j = 0; j < K; j += C) {
				long long pos = 0;
				for (long long l = 0; l < C; l++) {
					pos *= K;
					if (j+l >= K) pos += K-1;
					else pos += j+l;
				}
				printf(" %lld", pos+1);
			}

		}
		else printf(" IMPOSSIBLE");
		//for (long long i = 1; i <= S; i++) printf(" %d", i);
		printf("\n");
	}
	return 0;
}