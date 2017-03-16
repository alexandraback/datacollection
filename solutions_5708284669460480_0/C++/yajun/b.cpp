# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <map>
# include <queue>
# include <iostream>

using namespace std;

# define testin freopen("B-small-attempt0.in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
typedef long long int lli;


int K, L, S;
char k[10];
char w[10];
char t[10];

int sum;
int mx;

int get(char *s)
{
    int ret = 0;
    char *p = s;
    while (1) {
        p = strstr(p, w);
        if (p != NULL) ++ret, ++p;
        else break;
    }
    return ret;
}

void dfs(int cnt)
{
    if (cnt == S) {
        int tt = get(t);
        sum += tt;
        mx = max(tt, mx);
    } else {
        for (int i = 0; i < K; ++i) {
            t[cnt] = k[i];
            dfs(cnt+1);
        }
    }
}

int main()
{
    testin;
    testout;

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        printf("Case #%d: ", ica);
        scanf("%d%d%d%s%s", &K, &L, &S, k, w);
        sum = 0;
        mx = 0;
        memset(t, 0, sizeof(t));
        dfs(0);
        double total = 1.0;
        for (int i = 0; i < S; ++i) total *= K;
        double ans = sum * 1.0 / total;
        printf("%.9lf\n", mx - ans);
    }

    return 0;
}

