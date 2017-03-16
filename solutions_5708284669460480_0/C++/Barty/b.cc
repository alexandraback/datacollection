#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200;
double Q[26];
struct Aho_Corasick {
    int ch[maxn][26], d[maxn], sz, fail[maxn], q[maxn], l, r;
    double dp[maxn][maxn][maxn];
    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    void insert(char *str) {
        int p = 0;
        for (; *str; ++str) {
            int x = (*str) - 'A';
            if (!ch[p][x]) {
                ch[p][x] = sz++;
                memset(ch[sz-1], 0, sizeof(ch[sz-1]));
                fail[sz-1] = 0;
                d[sz-1] = 0;
            }
            p = ch[p][x];
        }
        ++d[p];//同一个模式串可能出现多次
    }
    void build_automation() {
        memset(q, 0, sizeof(q));
        l = 1; r = 0;
        for (int i = 0; i < 26; ++i)
            if (ch[0][i]) q[++r] = ch[0][i];
        while (l <= r) {
            int now = q[l++];
            for (int i = 0; i < 26; ++i)
                if (ch[now][i]) {
                    q[++r]= ch[now][i];
                    fail[ch[now][i]] = ch[fail[now]][i];
                } else ch[now][i] = ch[fail[now]][i];
        }
    }
    double gao(int n) {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j < sz; ++j)
                for (int k = 0; k <= i; ++k)
                    for (int t = 0; t < 26; ++t) 
                        if (Q[t] > 1e-10) {
                            int dest = ch[j][t];
                            dp[i+1][dest][k+(dest==sz-1)] += Q[t] * dp[i][j][k];
                        }
        double sum = 0;
        int max_time = 0;
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j <= n; ++j) {
                sum += j * dp[n][i][j];
                if (dp[n][i][j] > 0) max_time = j;
            }
        return max_time - sum;
    }
}ac;
int main() {
    int T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        int k, l, s;
        scanf("%d%d%d", &k, &l, &s);
        memset(Q, 0, sizeof(Q));
        char str[1024];
        scanf("%s", str);
        for (int i = 0; i < k; ++i) {
            Q[str[i] - 'A']++;
        }
        for (int i = 0; i < 26; ++i)
            Q[i] /= k;
        scanf("%s", str);
        ac.init();
        ac.insert(str);
        ac.build_automation();
        printf("Case #%d: %.10f\n", ca, ac.gao(s));
    }
    return 0;
}
