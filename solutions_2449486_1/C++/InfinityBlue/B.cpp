#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
#define INF 0x73737373
#define EPS 1e-8
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
int lawn[105][105];
int n, m;
bool can_cut(int x, int y)
{
    int val = lawn[x][y];
    bool row_can = true, col_can = true;
    for(int i = 1; i <= m; i++)
        if(lawn[x][i] > val)
        {
            row_can = false;
            break;
        }
    for(int i = 1; i <= n; i++)
        if(lawn[i][y] > val)
        {
            col_can = false;
            break;
        }
    return row_can || col_can;
}
bool check()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(!can_cut(i, j)) return false;
    return true;
}
int main()
{
    int t;
    freopen("B-large.in", "r", stdin);
    freopen("bans.out", "w", stdout);
    scanf("%d", &t);
    for(int ca = 1; ca <= t; ca++)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &lawn[i][j]);
        bool can = check();
        printf("Case #%d: ", ca);
        puts(can? "YES" : "NO");
    }
	return 0;
}
