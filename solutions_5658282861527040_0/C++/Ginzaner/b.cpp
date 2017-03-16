#include <cstdio>

using namespace std;

int main() {

	int T; 
	scanf("%d", &T);
	
	for(int k = 1; k <= T; k++) {
		printf("Case #%d: ", k);
		
		int A,B,K;
		scanf("%d %d %d", &A, &B, &K);
		
		int count = 0;
		for(int i = 0; i < A; i++) {
			for(int j = 0; j < B; j++) {
				if((j&i) < K) count++;
			}
		}
		
		printf("%d\n", count);
	}

	return 0;
}
