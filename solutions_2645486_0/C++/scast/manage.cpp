#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAXN 10
#define MAXE 10
#define INFINITE 0x3f3f3f3f
int memo[MAXN][MAXE];
int T, E, R, N, v[MAXN];

int max_gain(int i, int j) {
    // printf("%d %d\n", i, j);
    if (i >= N) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int& best = memo[i][j];
    best = 0;
    for (int k=0; j>=k; k++) {
	best = max(best, v[i]*k + max_gain(i+1, min(j-k+R, E)));
    }
    return best;
}

int main() {
    scanf("%d", &T);
    for (int tt=1; tt<=T; tt++) {
	memset(memo, -1, sizeof memo);
	scanf("%d%d%d", &E, &R, &N);
	for (int i=0; i<N; i++) {
	    scanf("%d", v+i);
	}
	printf("Case #%d: %d\n", tt, max_gain(0,E));
    }
    return 0;
}
