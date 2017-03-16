#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <io.h>
#include <stdint.h>
#include <queue>
#include <map>
using namespace std;

typedef int32_t I32;
typedef int64_t I64;
typedef uint64_t UI64;

int v[100];
int main() {
	int T, TC = 1;;
	int R, N, M, K;
	
	scanf("%d", &T);
	scanf("%d%d%d%d", &R, &N, &M, &K);
	puts("Case #1:");
	vector<int> x(3), ans(3); double ap = 0;
	ans[0] = ans[1] =ans[2]  = 2;
	while (R--) {
		ans[0] = ans[1] =ans[2]  = 2;
		ap = 0;
		for (int i=0; i<K; i++) scanf("%d", &v[i]);
		for (x[0] = 2; x[0]<=M; x[0]++) for (x[1] = 2; x[1]<=M; x[1]++) for (x[2] = 2; x[2]<=M; x[2]++) {
			map<int, double> prob;
			for (int i=0; i<(1<<N); i++) {
				int t = 1;
				for (int j=0; j<N; j++) 
					if (i & (1<<j)) 
						t*= x[j];
				prob[t];
				prob[t] += (1.0 / (1<<N));
			}
			double p = 1;
			for (int i=0; i<K; i++) {
				prob[v[i]];
				p *= prob[v[i]];
			}
			if (p > ap) {
				for (int i=0; i<N; i++) ans[i] = x[i];
				ap = p;
			}
		}
		for (int i=0; i<N; i++) printf("%d", ans[i]);
		puts("");
	}
}