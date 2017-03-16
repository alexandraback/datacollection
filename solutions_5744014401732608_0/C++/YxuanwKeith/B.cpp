#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long LL;

const int MAXN = 100;

int N, A[MAXN], Map[MAXN][MAXN];
LL M, Way[MAXN];

int main() {
	freopen("B.in", "r", stdin), freopen("B.out", "w", stdout);
	
	int Test;
	scanf("%d", &Test);
	for (int i = 1; i <= Test; i ++) {
		memset(Map, 0, sizeof Map);
		scanf("%d%lld", &N, &M);
		printf("Case #%d: ", i);
		LL t = M, Cnt = 0;
		Way[1] = Way[2] = 1;
		for (int j = 3; j <= N; j ++) Way[j] = Way[j - 1] * 2;
		for (int j = 1; j < N; j ++)
			for (int k = j + 1; k < N; k ++) Map[j][k] = 1;
		for (int j = N - 1; j; j --) 
			if (Way[j] <= M) Map[j][N] = 1, M = M - Way[j];
		if (M > 0) printf("IMPOSSIBLE\n"); else {
			printf("POSSIBLE\n");
			for (int i = 1; i <= N; i ++) {
				for (int j = 1; j <= N; j ++)
					printf("%d", Map[i][j]);
				printf("\n");
			}
		}
	}
}