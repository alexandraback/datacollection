#include <bits/stdc++.h>

#define C 100
#define BIG 1000000000000000000ULL

using namespace std;

typedef unsigned long long ull;

ull pos[C]; // botar como ull
ull inc[C]; // botar como ull

int main(void){
	ull t, k, c, s, i, j, x, counter;

	scanf("%llu", &t);

	for (i = 0; i < t; i++){
		// printf("k c s\n");
		scanf("%llu%llu%llu", &k, &c, &s);

		// Descubro C tiles iniciais por posição ótima
		// Portanto:
		if (c * s >= k){
			printf("Case #%llu:", i + 1);

			// How many positions I need. Missing the last position if k % c != 0
			for (j = 0; j < k / c; j++){
				// printf("First for\n");
				pos[0] = j * c + 1;
				inc[0] = pos[0] - 1;

				for (x = 1; x < c; x++){
					inc[x] = inc[x - 1] * k + 1;
					pos[x] = pos[x - 1] + inc[x];
				}

				printf(" %llu", pos[x - 1]);
			}

			if (k % c){
				// printf("First for\n");
				pos[0] = j * c + 1;
				counter = k % c;

				inc[0] = pos[0] - 1;

				// for (x = 1; x < c; x++){
				for (x = 1; counter > 1; x++, counter--){
					inc[x] = inc[x - 1] * k + 1;
					pos[x] = pos[x - 1] + inc[x];
				}

				for (; x < c; x++){
					pos[x] = (pos[x - 1] - 1) * k + 1;
				}

				printf(" %llu", pos[x - 1]);
			}

			printf("\n");
		}
		else{
			
			printf("Case #%llu: IMPOSSIBLE\n", i + 1);
		}
	}

	return 0;
}