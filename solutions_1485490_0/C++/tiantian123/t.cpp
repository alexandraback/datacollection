#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

typedef long long ll;
ll totalA[150], totalB[150], typeA[150], typeB[150], answer;
int n, m;

void findans(int i, ll irst, int j, ll jrst, ll ans) {
    if (i > n || j > m) {
        answer = MAX(answer, ans);
        return;
    }
    if (typeA[i] == typeB[j]) {
        if (irst < jrst) {
            findans(i + 1, totalA[i + 1], j, jrst - irst, ans + irst);
        } else {
            findans(i, irst - jrst, j + 1, totalB[j + 1], ans + jrst);
        }
        return;
    }
    findans(i + 1, totalA[i + 1], j, jrst, ans);
    findans(i, irst, j + 1, totalB[j + 1], ans);
}

int main() {
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
    int test, counting = 0, i;
    scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &m);
        for (i = 1; i <= n; i++)
            scanf("%lld%lld", totalA + i, typeA + i);
        for (i = 1; i <= m; i++)
            scanf("%lld%lld", totalB + i, typeB + i);
        answer = 0;
        findans(1, totalA[1], 1, totalB[1], 0);
        printf("Case #%d: %lld\n", ++counting, answer);
    }
    return 0;
}
