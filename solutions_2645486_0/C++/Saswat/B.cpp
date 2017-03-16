#include <cstdio>

int v[16];
int T, E, R, N;

int startTask(int n, int X, int e) {
	int g = v[n]*e;
	X = (X-e)+R;
	if(X > E)	X = E;
	
	int max = 0;
	if(X && n < N-1) {
		for(int c = 0; c <= X; ++c) {
			int gain = startTask(n+1, X, c);
			if(gain > max)
				max = gain;
		}
	}
	
	return max+g;
}

int main() {
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		scanf("%d %d %d", &E, &R, &N);
		for(int j = 0; j < N; ++j)
			scanf("%d", v+j);

		int max = 0;
		for(int c = 0; c <= E; ++c) {
			int gain = startTask(0, E, c);
			if(gain > max)
				max = gain;
		}

		printf("Case #%d: %d\n", i, max);
	}
}
