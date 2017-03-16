#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

const int N = 1e2+10;
const int inf = 1e9;

typedef long long ll;

using namespace std;

ll dp[N];
bool e[N][N];
bool solve()
{
    memset(e,0,sizeof(e));
    int n;
    ll m;
    scanf("%d%lld", &n,&m);
    ll all = (1LL << (n-2));
    if (all < m) {
        puts("IMPOSSIBLE");
        return 0;
    }
    puts("POSSIBLE");
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i+1; j < n - 1; ++j)
            e[i][j] = 1;
    }
    
    if (m == all)
        for (int i = 0; i < n - 1; ++i)
            e[i][n-1] = 1;
    else
        for (int i = 1; m; i++, m/=2)
            e[i][n-1]=(m&1);
    
    for (int i = 0; i < n; ++i, puts(""))
        for (int j = 0; j < n; ++j)
            printf("%c", "01"[e[i][j]]);
    
    return false;
}

int main()
{
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    int countTests;
    scanf("%d", &countTests);
    for (int curTest = 1; curTest <= countTests; ++curTest) {
        printf("Case #%d: ", curTest);
        solve();
    }
    
    return 0;
}
