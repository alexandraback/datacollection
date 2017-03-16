#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;

const int MAXN = 1e3;

int N, Ans[MAXN];

int main() {
	freopen("B.in", "r", stdin), freopen("B.out", "w", stdout);
	int Test;
	scanf("%d", &Test);
	for (int Num = 1; Num <= Test; Num ++) {
		memset(Ans, 0, sizeof Ans);
		scanf("%d", &N);
		for (int i = 1; i <= 2 * N - 1; i ++) 
			for (int j = 1; j <= N; j ++) {
				int Now;
				scanf("%d", &Now);
				Ans[Now] ^= 1;
			}
		printf("Case #%d:", Num);
		for (int i = 0; i <= MAXN; i ++) if (Ans[i] > 0) printf(" %d", i);
		printf("\n");
	}
}