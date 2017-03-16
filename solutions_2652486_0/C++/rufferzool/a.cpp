#include <cstdio>

using namespace std;

int subsets[126], seq[5], act[126];

bool valid(int a, int b, int c) {
	for(int i = 0; i <= 125; i ++)
		act[i] = 0;
	act[a] ++;
	act[b] ++;
	act[c] ++;
	act[1] ++;
	act[a * b] ++;
	act[a * c] ++;
	act[b * c] ++;
	act[a * b * c] ++;
	for(int i = 0; i <= 125; i ++)
		if(act[i] == 0 && subsets[i] != 0)
			return false;
	return true;
}

int main() {
	int T;
	scanf(" %d", &T);
	printf("Case #1:\n");
	int R, N, M, K;
	scanf(" %d %d %d %d", &R, &N, &M, &K);
	for(int z = 0; z < R; z ++) {
		for(int i = 0; i <= 125; i ++) {
			subsets[i] = 0;
			act[i] = 0;
		}
		for(int i = 0; i < K; i ++) {
			int temp = 0;
			scanf(" %d", &temp);
			subsets[temp] ++;
		}
		for(int i = 2; i <= M; i ++)
			for(int k = i; k <= M; k ++)
				for(int j = k; j <= M; j ++)
					if(valid(i, j, k)) {
						seq[0] = i;
						seq[1] = j;
						seq[2] = k;
					}
		for(int i = 0; i < 3; i ++)
			printf("%d", seq[i]);
		printf("\n");
	}
}
