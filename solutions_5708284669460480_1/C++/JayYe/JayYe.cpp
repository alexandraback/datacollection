#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 100+5;

int nxt[N], cnt[33], to[N][33];
double p[N], dp[N][N];
char s[N], target[N];
int K, L, S;
int dp2[N][N];

void get_next(char s[]) {
    int len = strlen(s+1);
    int i = 0, j = 1;
    nxt[1] = 0;
    while(j <= len) {
        if(i == 0 || s[i] == s[j]) {
            i++; j++;
            nxt[j] = i;
        }
        else
            i = nxt[i];
    }
}

double solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(p, 0, sizeof(p));
    for(int i = 0;i < K; i++) cnt[s[i]-'A']++;
    for(int i = 0;i < 26; i++) p[i] = 1.0*cnt[i]/K;
    target[L+1] = 'a'; target[L+2] = '0';
    get_next(target);
//    for(int i = 1;i <= L; i++) printf("%d ", nxt[i]); puts("");
    nxt[1] = 1;
    for(int i = 0;i <= L; i++) {
        for(int j = 0;j < 26; j++) {
            if(i == 0) {
                if(j == target[1]-'A') to[i][j] = 1;
                else    to[i][j] = 0;
            } else {
                int cur = i+1;
                while(cur != 1) {
                    if(target[cur]-'A'==j) {
                        to[i][j] = cur;
                        break;
                    }
                    else    cur = nxt[cur];
                }
                if(cur == 1) {
                    if(j==target[1]-'A') to[i][j] = 1;
                    else    to[i][j] = 0;
                }
            }
        }
    }
    memset(dp, 0, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    dp[0][0] = 1;
    dp2[0][0] = 0;
    double ans = 0;
//    for(int i = 0;i < 26; i++) printf("%f ", p[i]); puts("");
    for(int i = 1;i <= S; i++) {
        for(int j = 0;j <= L; j++) {
            for(int k = 0;k < 26; k++) {
                dp[i][to[j][k]] += dp[i-1][j]*p[k];
                if(dp2[i-1][j] >= 0 && p[k] > 0) {
                    int add = to[j][k] == L ? 1 : 0;
                    dp2[i][to[j][k]] = max(dp2[i][to[j][k]], dp2[i-1][j] + add);
                }
            }
        }
//        for(int j = 0;j <= L; j++) printf("%f ", dp[i][j]); puts("");
        ans += dp[i][L];
    }
    int mx = 0;
    for(int i = 0;i <= L; i++) {
        mx = max(mx, dp2[S][i]);
//        printf("dp[%d] = %d\n", i, dp2[S][i]);
    }
//    printf("mx = %d ans = %f\n", mx, ans);
    return mx-ans;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t, cas = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s", s);
        scanf("%s", target+1);
        printf("Case #%d: %.10f\n", cas++, solve());

    }
    return 0;
}
