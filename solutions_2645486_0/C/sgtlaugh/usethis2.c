#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define inf (-(1LL << 60LL))
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

int t, n, E, R;
bool visited[10010][110];
long long int ar[10010], dp[10010][110];

long long int F(int e, int i){
    if (e < 0) return inf;
    if (i == n) return 0;
    if (visited[e][i]) return dp[e][i];

    int j;
    long long int res = inf;
    for (j = 0; j <= e; j++){
        int y = e - j + R;
        if (y > E) y = E;
        long long int x = (ar[i] * j) + F(y, i + 1);
        if (x > res) res = x;
    }

    visited[e][i] = true;
    return (dp[e][i] = res);
}

int main(){
    int line, i, j;

    scanf("%d", &t);
    for (line = 1; line <= t; line++){
        scanf("%d %d %d", &E, &R, &n);
        for (i = 0; i < n; i++) scanf("%lld", &ar[i]);

        clr(visited);
        long long int res = F(E, 0);
        printf("Case #%d: %lld\n", line, res);
    }
    return 0;
}
