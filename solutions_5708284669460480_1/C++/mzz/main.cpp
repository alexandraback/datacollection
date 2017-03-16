#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 110
int K, L, S, P[MAXN], cnt[MAXN][MAXN];
double dp[MAXN][MAXN];
bool cal[MAXN][MAXN];
char s[MAXN], key[MAXN];
void KMP() {
    P[0] = P[1] = 0;
    for(int i = 2, j = 0; i <= L; i ++) {
        while(j > 0 && s[j + 1] != s[i]) {
            j = P[j];
        }
        if(s[j + 1] == s[i]) {
            ++ j;
        }
        P[i] = j;
    }
}
void dfs(int cur, int st) {
    if(cal[cur][st]) {
        return ;
    }
    if(cur == S) {
        if(st == L) {
            cnt[cur][st] = 1;
            dp[cur][st] = 1.0;
            return ;
        }
        cnt[cur][st] = 0;
        dp[cur][st] = 0.0;
        return ;
    }
    if(st == L) {
        dfs(cur, P[L]);
        cnt[cur][st] = 1 + cnt[cur][P[L]];
        dp[cur][st] = 1.0 + dp[cur][P[L]];
        return ;
    }
    double ans = 0.0;
    int max = 0;
    for(int i = 1; i <= K; i ++) {
        int j = st;
        while(j > 0 && s[j + 1] != key[i]) {
            j = P[j];
        }
        if(s[j + 1] == key[i]) {
            ++ j;
        }
        dfs(cur + 1, j);
        max = std::max(max, cnt[cur + 1][j]);
        ans += dp[cur + 1][j] / K;
    }
    cal[cur][st] = true;
    cnt[cur][st] = max;
    dp[cur][st] = ans;
}
int main() {
    //freopen("input.txt", "rb", stdin);
    freopen("B-large.in", "rb", stdin);
    freopen("output.txt", "wb", stdout);
    int t;
    scanf("%d", &t);
    for(int tt = 1; tt <= t; tt ++) {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s", key + 1);
        scanf("%s", s + 1);
        KMP();
        for(int i = 0; i <= S; i ++) {
            for(int j = 0; j <= L; j ++) {
                cal[i][j] = false;
            }
        }
        dfs(0, 0);
        printf("Case #%d: %.8f\n", tt, cnt[0][0] - dp[0][0]);
    }
    return 0;
}
