#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int NN = 105;
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

char sk[NN];
char sl[NN];
char ts[NN];

int ans1;
int ans2;
int ans3;

void dfs(int step, int k, int l, int s)
{
    if (step == s)
    {
        int tmp = kmp(sl, ts, l, s);
        ans1 += tmp;
        ans3 = max(ans3, tmp);
        ans2 ++;
        return ;
    }
    for (int i = 0; i < k; i++)
    {
        ts[step] = sk[i];
        dfs(step + 1, k, l, s);
    }
}

int main()
{
   // freopen("1.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T;
    cin >> T;
    for (int cas = 1; cas <= T; cas++)
    {
        int k, l, s;
        cin >> k >> l >> s;
        scanf("%s", sk);
        scanf("%s", sl);

        memset(nxt, 0, sizeof(nxt));
        get_next(sl, l);

        vector <int> vid;
        for (int i = 0; i < k; i++) vid.push_back(i);

        ans1 = ans2 = ans3 = 0;
        dfs(0, k, l, s);
        double ans = 1.0 * ans3 - 1.0 * ans1 / (1.0 * ans2);
        printf("Case #%d: %.8f\n", cas, ans);
    }
    return 0;
}
