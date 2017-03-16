#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
#include"queue"
using namespace std;
typedef long long LL;
int TC, T, K, C, S;
queue<LL> Q[105];
int main() {
	//freopen("D-small-attempt1.in", "r", stdin);
	//freopen("D-small-attempt1.txt", "w", stdout);
	freopen("D-large.in", "r", stdin);
	freopen("D-large.txt", "w", stdout);
	scanf("%d", &TC);
	while (T < TC) {
		scanf("%d%d%d", &K, &C, &S);
		int R = ceil(K / C);
		if (S < R) {
			printf("Case #%d: IMPOSSIBLE\n", ++T);
			continue;
		}
		printf("Case #%d: ", ++T);
		for (int k = 0; k < K; k += C) {
			LL X = 0;
			for (int j = 0; j < C; j++) 
				X = (X * K) + (k + j >= K? 0: k + j);
			printf("%lld ", X + 1);
		}
		printf("\n");
	}
}
