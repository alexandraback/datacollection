#include <bits/stdc++.h>
using namespace std;

const int MAXN = 111;
const int MAXC = 26;

bool u1[MAXC], u2[MAXC];
int k, l, s, pre[MAXN];
string keys, tar;
double prob[MAXC], dp[MAXN][MAXC][MAXN];

int KMP() {
    memset(pre, 0, sizeof(pre));
    int j = -1;
    pre[0] = -1;
    for (int i = 1; i < l; i++) {
        while (j != -1 && tar[i] != tar[j + 1]) j = pre[j];
        if (tar[j + 1] == tar[i]) j++;
        pre[i] = j;
    }
    if (pre[l - 1] == -1)
        return s / l;
    else {
        int cnt = 1, delta = l - (pre[l - 1] + 1), init = l;
        while (init + delta <= s) {
            init += delta;
            cnt++;
        }
        return cnt;
    }
}

void solve(int ca) {
    cout << "Case #" << ca << ": ";
    cin >> k >> l >> s >> keys >> tar;
    memset(u1, false, sizeof(u1));
    memset(u2, false, sizeof(u2));
    memset(prob, 0, sizeof(prob));

    double r1 = 0.0, r2 = 0.0;
    for (int i = 0; i < l; i++) u2[tar[i] - 'A'] = true;
    for (int i = 0; i < k; i++) {
        prob[keys[i] - 'A'] += 1.0;
        u1[keys[i] - 'A'] = true;
    }
    for (int i = 0; i < MAXC; i++) if (u2[i] && !u1[i]) {
        printf("%.7f\n", r1 - r2);
        return ;
    }
    for (int i = 0; i < MAXC; i++) prob[i] /= k;

    r1 = KMP();
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < MAXC; i++) if (prob[i] > 1e-9) {
            if (tar[0] == i + 'A')
                dp[0][i][1] = prob[i];
            else
                dp[0][i][0] = prob[i];
        }

    for (int i = 0; i < s - 1; i++)
        for (int j = 0; j < MAXC; j++) {
            r2 += dp[i][j][l];
            int tk = pre[l - 1] + 1;
            dp[i][j][tk] += dp[i][j][l];
            for (int it = 0; it < l; it++) {
                for (int tj = 0; tj < MAXC; tj++) {
                    int tk = it - 1;
                    char ch = 'A' + tj;
                    double delta = prob[tj] * dp[i][j][it];
                    while (tk != -1 && tar[tk + 1] != ch) tk = pre[tk];
                    if (ch == tar[tk + 1]) tk++;
                    tk++;
                    dp[i + 1][tj][tk] += delta;
                }
            }
        }
    for (int i = 0; i < MAXC; i++) r2 += dp[s - 1][i][l];
    printf("%.7f\n", r1 - r2);
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve(i + 1);
    return 0;
}
