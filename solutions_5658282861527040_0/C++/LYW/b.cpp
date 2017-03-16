#include <cstdio>
#include <algorithm>
using namespace std;

int A, B, K;

int main(void) {
	int testNum;
	scanf("%d", &testNum);
	for (int testCase = 1; testCase <= testNum; testCase++) {

		scanf("%d %d %d", &A, &B, &K);

		int cnt = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				if ((i & j) < K)
					cnt ++;

			}
		}

		printf("Case #%d: %d\n", testCase, cnt);

	}

	return 0;
}
