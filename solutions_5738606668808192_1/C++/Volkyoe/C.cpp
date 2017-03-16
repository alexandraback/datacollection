#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
using namespace std;
typedef long long LL;
int TC, T, N, J;
char S[40];
int main() {
	//freopen("C-small-attempt0.in", "r", stdin);
	//freopen("C-small-attempt0.txt", "w", stdout);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.txt", "w", stdout);
	scanf("%d", &TC);
	while (T < TC) {
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", ++T);
		for (int i = 0; i < N; i++) S[i] = '0';
		S[0] = S[1] = S[N-2] = S[N-1] = '1';
		for (int i = 2; i < N - 7; i++) {
			S[i] = S[i+1] = '1';
			for (int j = i + 2; j < N - 5; j++) {
				S[j] = S[j+1] = '1';
				for (int k = j + 2; k < N - 3; k++) {
					S[k] = S[k+1] = '1';
					printf("%s ", S);
					for (int b = 2; b <= 10; b++)
						printf("%d ", b + 1);
					printf("\n");
					if (--J == 0) return 0;
					S[k] = S[k+1] = '0';
				}
				S[j] = S[j+1] = '0';
			}
			S[i] = S[i+1] = '0';
		}
	}
}
