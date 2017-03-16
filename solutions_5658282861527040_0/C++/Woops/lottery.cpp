#include <cstdio>

int i, j, m;
int numOfBlocks, A, B, K;

int solveQuest() {
	int result = 0;
	for (j = 0; j < A; j++) {
		for (m = 0; m < B; m++) {
			if ((j & m) < K) {
//				printf("debug: j:%d m:%d\n", j, m);
				result++;
			}
		}
	}
	return result;
}

int main() {
	scanf("%d", &numOfBlocks);
	for (i = 0; i < numOfBlocks; i++) {
		scanf("%d %d %d", &A, &B, &K);
//		printf("debug i:%d A:%d B:%d K:%d\n", i, A, B, K);

		// algorithm
		int result = solveQuest();
		printf("Case #%d: %d\n", i+1, result);		
	}
	return 0;
}