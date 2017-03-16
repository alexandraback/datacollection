#include <cstdio>
#include <cstring>

int T, EG, R, N;
int v[20];
int dp[20][20];

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int E, int ac) {
    // printf("%d %d\n", E, ac);
    if (ac == N)
        return dp[E][ac] = 0;
    if (E < 0)
        return -1e9;
    if (dp[E][ac] != -1)
        return dp[E][ac];
    int mx = -1;
    for (int e=0 ; e<=5 ; e++) {
        if (e <= E) 
            mx = max(mx, v[ac]*e + solve(min(EG, E-e+R), ac+1));
    }
    return dp[E][ac] = mx;
}

int main() {
    scanf("%d", &T);   
    for (int c=1 ; c<=T ; c++) {
        scanf("%d %d %d", &EG, &R, &N);
        for (int i=0 ; i<N ; i++)
            scanf("%d", &v[i]);
        memset(dp, -1, sizeof dp);
        printf("Case #%d: %d\n", c, solve(EG, 0));
    }
}