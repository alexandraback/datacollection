#include <cstdio>
#include <algorithm>
using namespace std;

int T;
int J, P, S, K;

int main(){
	scanf("%d", &T);

	for(int tt = 1; tt <= T; tt++){
		scanf("%d %d %d %d", &J, &P, &S, &K);

		printf("Case #%d: %d\n", tt, J * P * min(S ,K));
		for(int i = 1; i <= J; i++)
			for(int j = 1; j <= P; j++)
				for(int k = 0; k < min(S, K); k++)
					printf("%d %d %d\n", i, j, ((i + j + k - 1) % S) + 1);
	}
}