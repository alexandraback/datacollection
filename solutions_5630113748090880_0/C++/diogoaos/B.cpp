#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int T, N;
	bool flip[2510];
	
	scanf("%d", &T);
	
	for (int test = 1; test <= T; test++) {
		printf("Case #%d:", test);
		
		scanf("%d", &N);
		
		memset(flip, 0, sizeof(flip));
		
		int h;
		for (int i = 0; i < 2 * N - 1; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &h);
				flip[h] = !flip[h];
			}
		}
		
		for (int i = 0; i < 2510; i++) {
			if (flip[i]) {
				printf(" %d", i);
			}
		}
		
		printf("\n");
	}
	return 0;
}