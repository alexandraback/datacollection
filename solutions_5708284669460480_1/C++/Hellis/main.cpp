#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int NN = 105;
const double eps = 1e-8;

int nxt[NN];
void get_next(char s[], int len)
{
    nxt[0] = -1;
    for (int i = 2, j = 0; i <= len; i++)
    {
        while (j > -1 && s[i - 1] != s[j]) j = nxt[j];
        nxt[i] = ++j;
    }
}
int kmp(char s[], char t[], int ls, int lt)
{
    int cnt = 0;
    for (int i = 1, j = 0; i <= lt; i++)
    {
        while (j && s[j] != t[i - 1]) j = nxt[j];
        if (s[j] == t[i - 1]) j++;
        cnt += (j == ls);
    }
    return cnt;
}
int check(char s[], char ct, int ls, int j, int &cnt)
{
    while (j && s[j] != ct) j = nxt[j];
    if (s[j] == ct) j++;
    cnt = (j == ls);
    return j;
}

char sk[NN];
char sl[NN];

double f[NN][NN][NN];
int mark[NN][NN];
int marks[NN];
double ps[NN];

int main()
{
   // freopen("1.txt", "r", stdin);

    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);

    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++) {
        int k, l, s;
        cin >> k >> l >> s;
        scanf("%s", sk);
        scanf("%s", sl);

        memset(nxt, 0, sizeof(nxt));
        get_next(sl, l);

        memset(marks, 0, sizeof(marks));
        memset(ps, 0, sizeof(ps));
        for (int i = 0; i < k; i++) marks[sk[i] - 'A']++;
        for (int i = 0; i < 26; i++) ps[i] = 1.0 * marks[i] / k;

        memset(f, 0, sizeof(f));
        memset(mark, 0, sizeof(mark));
        f[0][0][0] = 1;
        for (int i = 0; i < s; i++)
        {
            for (int j = 0; j <= l; j++)
            {
                for (int t = 0; t <= mark[i][j]; t++)
                {
                    if (f[i][j][t] < eps) continue;
                    for (int h = 0; h < 26; h++)
                        if (ps[h] > eps)
                        {
                            char ct = 'A' + h;
                            int cnt = 0;
                            int now = check(sl, ct, l, j, cnt);
                            if (now < 0) printf("ssss");
                            mark[i + 1][now] = max(mark[i + 1][now], mark[i][j] + cnt);
                            f[i + 1][now][t + cnt] += f[i][j][t] * ps[h];
                        }
                }
            }
        }

        double ans1 = 0;
        int ans3 = 0;

        for (int j = 0; j <= l; j++)
        {
            for (int t = 0; t <= mark[s][j]; t++)
            {
                if (f[s][j][t] < eps) continue;
                ans3 = max(ans3, t);
                ans1 += f[s][j][t] * t;
            }
        }

        double ans = 1.0 * ans3 - ans1;
        printf("Case #%d: %.8f\n", cas, ans);
    }
    return 0;
}
