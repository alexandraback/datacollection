#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T, N;
int H[3000];


int main()
{
	scanf(" %d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf(" %d", &N);
		memset(H, 0, sizeof(H));
		for (int i = 0; i < 2*N-1; i++) {
			int h;
			for (int j = 0; j < N; j++) {
				scanf(" %d", &h);
				H[h]++;
			}
		}

		printf("Case #%d:", cas);
		for (int i = 1;  i <= 2500; i++)
			if (H[i]%2 == 1)
				printf(" %d", i);
		puts("");
	}

	return 0;
}