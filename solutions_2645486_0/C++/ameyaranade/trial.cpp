#include<cstdio>
#include<math.h>
using namespace std;

#define LINT unsigned long long int
#define MAX 10000
#define MAXE 10000000

int val[MAX];
int T, E, R, N, v;
LINT ER[MAXE], EC[MAXE];


LINT solve() {
	int remain;
	LINT gain, max;
	for(int i=N-1;i>=0;i--) {
		// do some cleanup.
		for (int e=0;e<=E;e++) {
			ER[e] = (i == (N-1))? 0 : EC[e];
		}

		// at i'th task, if I had R<=e<=E energy, what is max gain from then.
		for (int e =R;e <= E;e++) {
			// at given energy e, use curr energy.
			max  = 0;
			for (int curr=0;curr<=e;curr++) {
				remain = e + R - curr;
				if (remain > E) remain = E;
				gain  = (LINT)val[i]*curr + ER[remain];
				if (max < gain) max = gain;
			}
			// so max is max at index i, and energy level e
			EC[e] = max;
		}
	}
	// now at index 0, find real max.
	max = 0;
	for (int e=R;e<=E;e++) {
		if (max < EC[e]) max = EC[e];
	}
	return max;
}

int main() {
	freopen("a.in", "r", stdin);
    freopen("op.out", "w", stdout);
	scanf("%d", &T);
	int count=1;
	while(T--) {
		scanf("%d %d %d", &E, &R, &N);
		for(int i=0;i<N;i++) {
			scanf("%d", &v);
			val[i] = v;
		}
		printf("Case #%d: %llu\n", count++, solve());
	}
	return 0;
}