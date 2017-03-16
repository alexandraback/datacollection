#include <cstdio>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_BITS = 31;

long long solve(long long A, long long B, long long K) {
	unsigned long long cnt = 0;

	for(int i = 0; i < MAX_BITS; i++)
		if(A & (1ll << i))
		for(int j = 0; j < MAX_BITS; j++)
			if(B & (1ll << j))
			for(int k = 0; k < MAX_BITS; k++)
				if(K & (1ll << k)) {
					unsigned long long myp = 1;
					for(int z = MAX_BITS; z >= 0; --z) {
						vector<bool> apos, bpos, cpos;
						
						if(z > i)
							apos.push_back(A & (1ll << z));
						else if(z == i)
							apos.push_back(0);
						else {
							apos.push_back(0);
							apos.push_back(1);
						}

						if(z > j)
							bpos.push_back(B & (1ll << z));
						else if(z == j)
							bpos.push_back(0);
						else {
							bpos.push_back(0);
							bpos.push_back(1);
						}

						if(z > k)
							cpos.push_back(K & (1ll << z));
						else if(z == k)
							cpos.push_back(0);
						else {
							cpos.push_back(0);
							cpos.push_back(1);
						}
						
						unsigned int v = 0;

						for(bool a : apos)
							for(bool b : bpos)
								for(bool c : cpos) {
									if((a && b) == c)
										++v;
								}

						myp *= v;
					}

					cnt += myp;
				}

	return cnt;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		int A, B, K;
		scanf("%d%d%d", &A, &B, &K);
		printf("Case #%d: %lld\n", i, solve(A, B, K));
	}
}
