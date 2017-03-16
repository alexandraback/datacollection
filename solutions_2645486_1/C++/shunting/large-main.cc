#include <stdio.h>
#include <vector>

typedef unsigned long long ull;

ull varr[10000];
int next[10000];

int
main(void) {
	int T, seq;
	ull E, R;
	ull tot;
	int N;

	scanf("%d", &T);
	for (seq = 1; seq <= T; seq++) {
		scanf("%llu%llu%d", &E, &R, &N);
		for (int i = 0; i < N; i++) {
			scanf("%llu", &varr[i]);
		}
		
		std::vector<int> stk; // store index
		for (int i = 0; i < N; i++) {
			while (!stk.empty()) {
				int j = stk[stk.size() - 1];
				if (varr[i] < varr[j]) {
					break;
				}

				stk.pop_back();	
				next[j] = i;
			}
			stk.push_back(i);
		}

		while (!stk.empty()) {
			int j = stk[stk.size() - 1];
			next[j] = -1;
			stk.pop_back();
		}
		
		tot = 0;
		ull curE = E;
		for (int i = 0; i < N; i++) {
			if (next[i] == -1) {
				tot += curE * varr[i];
				curE = R;
			} else {
				int j = next[i];
				ull maxi = curE + R * (j - i);
				if (maxi > E) {
					ull t = maxi - E;
					if (t > curE) {
						t = curE;
					}
					tot += t * varr[i];
					curE = curE - t + R;
				} else {
					curE += R;
				}
			}
		}
		printf("Case #%d: %llu\n", seq, tot);
	}
	
	return 0;
}
