#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <iterator>
#include <utility>
#include <numeric>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

using namespace std;

const int MaxD = 110, MaxV = 110;

int C, D, V;
int a[MaxD];
bool used[MaxV], valid[MaxV][MaxV];
int ans;

inline bool check(const int &h)
{
    for (int i = 1; i <= V; ++i)
        if (! valid[h][i])
            return 0;
    return 1;
}

void dfs(const int &h, int i, const int &cnt)
{
    if (check(h-1))
    {
        ans = min(ans, cnt);
        return;
    }
    if (cnt+1 >= ans || i >= V)
        return;
    for (; i <= V; ++i)
        if (! used[i])
        {
            memcpy(valid[h], valid[h-1], sizeof(valid[0][0])*i);
            for (int j = i; j <= V; ++j)
                valid[h][j] = valid[h-1][j] || valid[h-1][j-i];
            dfs(h+1, i+1, cnt+1);
        }
}

int main()
{
    freopen("C-small-attempt0.in.txt", "r", stdin);
    freopen("C-small-attempt0.out.txt", "w", stdout);
    //freopen("C-large.in.txt", "r", stdin);
    //freopen("C-large.out.txt", "w", stdout);
    int TestCase;
    cin >> TestCase;
    for (int Test = 1; Test <= TestCase; ++Test)
    {
        ans = 0x7FFFFFFF;
        memset(used, 0, sizeof(used));
        memset(valid[0], 0, sizeof(valid[0]));
        cin >> C >> D >> V;
        for (int i = 0; i < D; cin >> a[i++]);
        for (int i = 0; i < D; used[a[i++]] = 1);
        for (int i = 0; ! (i >> D); ++i)
        {
            int k = 0;
            for (int j = 0; j < D; ++j)
                if ((i >> j) & 1)
                    k += a[j];
            if (k <= V)
                valid[0][k] = 1;
        }
        dfs(1, 1, 0);
        cout << "Case #" << Test << ": " << ans << endl;
    }
    return 0;
}
