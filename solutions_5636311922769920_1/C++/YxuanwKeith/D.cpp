#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int Test, K, C, S;

int main() {
	//freopen("D.in", "r", stdin), freopen("D.out", "w", stdout);
	
	scanf("%d", &Test);
	for (int i = 1; i <= Test; i ++) {
		scanf("%d%d%d", &K, &C, &S);
		int Ans = (K / C) + (K % C != 0);
		if (Ans > S) {
			printf("Case #%d: IMPOSSIBLE\n", i);
			continue;
		}
		printf("Case #%d:", i);
		LL Num = 1, Cnt = Ans * C;
		for (int i = 1; i <= Ans; i ++) {
			LL Tmp = 1, All = 0;
			for (int j = 1; j <= C; j ++) {
				LL p = (Cnt > K) ? K : Cnt;
				if (j != 1) p --; 
				All = All + p * Tmp;
				Tmp = Tmp * K;
				Cnt --;
			}
			printf(" %lld", All);
		}
		printf("\n");
	}
}