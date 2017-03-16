# include <stdio.h>
# include <string.h>
# include <algorithm>
# include <map>
# include <queue>
# include <iostream>

using namespace std;

# define testin freopen("C-small-attempt0 (1).in", "r", stdin)
# define testout freopen("out.txt", "w", stdout)
typedef long long int lli;


int C, D, V;
int d[35];
bool sc;
int a[35];
int n;

bool dfs(int i, int sum, int K)
{
    if (i == n) return sum == K;
    if (dfs(i+1, sum, K) || dfs(i+1, sum+a[i], K)) return true;
    return false;
}

bool check()
{
    for (int i = 1; i <= V; ++i) if (!d[i]) {
        if ( !dfs(0, 0, i) ) return false;
    }
    return true;
}

int main()
{
    testin;
    testout;

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        printf("Case #%d: ", ica);
        scanf("%d%d%d", &C, &D, &V);
        n = 0;
        memset(d,0,sizeof(d));
        for (int i = 0,x; i < D; ++i) scanf("%d", &x), d[x]=1, a[n++]=x;
        int ans = 0;
        sc = check();
        for (int i = 1; !sc && i*(i+1)/2<=V; ++i) {
            if (!d[i]) {
                ++ans;
                d[i] = 1;
                if (check()) break;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
