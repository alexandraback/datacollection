#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>

using namespace std;

int t;
int n, m, k;
int ans[70];
int ns[70];

long C[70][70];

void init()
{
    for(int i = 0; i <= 67; ++i)
    {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for(int i = 1; i <= 67; ++i)
    {
        for(int j = 1; j <= 67; ++j)
        C[i][j] = (C[i-1][j] + C[i-1][j-1]);
    }
}

int dfs(int x, int y, int z, int depth)
{
    int comb = (1<<m) - 1;
    int time = 1;
    if(time == k)
    {
        cout << bitset<sizeof(int)*8>(comb) << endl;
        return 1;
    }
    while(comb < 1<<(n+m))
    {
        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
        ++time;
        if(time == k)
        {
            cout << bitset<sizeof(int)*8>(comb) << endl;
            return 1;
        }
    }
    return 0;
}

void Solve()
{
    if(k > C[m+n][n])
    {
        cout << "Impossible" << endl;
        return;
    }

    memset(ans, 0, sizeof(ans));
    memset(ns, 0, sizeof(ns));
    dfs(n, m, k, 0);
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    cin >> t;
    init();
    int mizo=0;
    while(t--)
    {
        mizo++;
        cin >> n >> m >> k;
        cout<<"Case #"<<mizo<<":\n";
        Solve();
    }
    return 0;
}
