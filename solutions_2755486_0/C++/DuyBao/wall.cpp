#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAXW 5000
#define MAXN 1000

typedef struct
{
    int fd, w, e, s;

} attack;

bool comp(attack k1, attack k2)
{
    return k1.fd < k2.fd;
}

int main()
{
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int nTest = 0;
    cin >> nTest;
    for (int test = 1; test <= nTest; ++test)
    {
        int n = 0;
        cin >> n;
        int fd[MAXN], natt[MAXN], w[MAXN], e[MAXN], s[MAXN], dd[MAXN], dp[MAXN], ds[MAXN];
        for (int i = 0; i < n; ++i)
        {
            cin >> fd[i];
            cin >> natt[i];
            cin >> w[i] >> e[i];
            cin >> s[i];
            cin >> dd[i];
            cin >> dp[i];
            cin >> ds[i];
        }

        int a[MAXW + MAXW + 5] = {0};
        attack b[MAXW * 2];
        int nDays = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < natt[i]; ++j)
            {
                b[nDays].fd = fd[i] + j * dd[i];
                b[nDays].w = w[i] + j * dp[i] + MAXW;
                b[nDays].e = e[i] + j * dp[i] + MAXW;
                b[nDays].s = s[i] + j * ds[i];
                nDays++;
            }
        }
        sort(b, b + nDays, comp);

        int res = 0, i = 0;
        for (int i = 0; i < nDays;)
        {
            int j;
            for (j = i; j <= nDays; ++j)
            {
                bool succ = 0;
                if (j == nDays || b[j].fd != b[i].fd)
                    break;
                for (int k = b[j].w; k < b[j].e; ++k)
                    if (a[k] < b[j].s)
                        succ = 1;
                res += succ;
            }
            for (j = i; j <= nDays; ++j)
            {
                if (j == nDays || b[j].fd != b[i].fd)
                    break;
                for (int k = b[j].w; k < b[j].e; ++k)
                    if (a[k] < b[j].s)
                        a[k] = b[j].s;
            }
            i = j;
        }
        cout << "Case #" << test << ": " << res << endl;
    }
    return 0;
}
