#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
#include <numeric>
#include <sstream>
#include <stack>
#include <map>
#include <queue>

#define CL(arr, val)    memset(arr, val, sizeof(arr))

#define lc l,m,rt<<1
#define rc m + 1,r,rt<<1|1
#define pi acos(-1.0)
#define ll __int64
#define L(x)    (x) << 1
#define R(x)    (x) << 1 | 1
#define MID(l, r)   (l + r) >> 1
#define Min(x, y)   (x) < (y) ? (x) : (y)
#define Max(x, y)   (x) < (y) ? (y) : (x)
#define E(x)        (1 << (x))
#define iabs(x)     (x) < 0 ? -(x) : (x)
#define OUT(x)  printf("%I64d\n", x)
#define lowbit(x)   (x)&(-x)
#define Read()  freopen("A-small-attempt0.in", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)

#define M 137
#define N 7

using namespace std;

const int inf = 100000007;

char str[N][N];
char tmp[N][N];
int ans;

void check(int mk)
{
    int i,j;
    if (mk == 1)
    {
        for (i = 0; i < 4; ++i)
        {
            for (j = 0; j < 4; ++j)
            {
                tmp[i + 1][j + 1] = str[i][j];
                if (str[i][j] == 'T')
                {
                    tmp[i + 1][j + 1] = 'X';
                }
            }
        }
        for (i = 1; i <= 4; ++i)
        {
            for (j = 1; j <= 4; ++j)
            {
                if (tmp[i][j] != 'X') break;
            }
            if (j > 4) ans = 1;
        }
        for (j = 1; j <= 4; ++j)
        {
            for (i = 1; i <= 4; ++i)
            {
                if (tmp[i][j] != 'X') break;
            }
            if (i > 4) ans = 1;
        }
        for (i = 1; i <= 4; ++i)
        {
            if (tmp[i][i] != 'X') break;
        }
        if (i > 4) ans = 1;
        for (i = 1; i <= 4; ++i)
        {
            if (tmp[i][5 - i] != 'X') break;
        }
        if (i > 4) ans = 1;
    }
    else
    {
        for (i = 0; i < 4; ++i)
        {
            for (j = 0; j < 4; ++j)
            {
                tmp[i + 1][j + 1] = str[i][j];
                if (str[i][j] == 'T')
                {
                    tmp[i + 1][j + 1] = 'O';
                }
            }
        }
        for (i = 1; i <= 4; ++i)
        {
            for (j = 1; j <= 4; ++j)
            {
                if (tmp[i][j] != 'O') break;
            }
            if (j > 4) ans = 2;
        }
        for (j = 1; j <= 4; ++j)
        {
            for (i = 1; i <= 4; ++i)
            {
                if (tmp[i][j] != 'O') break;
            }
            if (i > 4) ans = 2;
        }
        for (i = 1; i <= 4; ++i)
        {
            if (tmp[i][i] != 'O') break;
        }
        if (i > 4) ans = 2;
        for (i = 1; i <= 4; ++i)
        {
            if (tmp[i][5 - i] != 'O') break;
        }
        if (i > 4) ans = 2;
    }
}

int main()
{
    Read();
    Write();
    int i,j;
    int T,cas = 1;
    scanf("%d",&T);
    while (T--)
    {
        bool flag = false;
        for (i = 0; i < 4; ++i)
        {
            scanf("%s",str[i]);
            for (j = 0; j < 4; ++j)
            {
                if (str[i][j] == '.') flag = true;
            }
        }
        ans = 0;
        check(1);
        if (ans == 0) check(2);

        if (ans == 0)
        {
            if (flag) ans = 4;
            else ans = 3;
        }
        if (ans == 1) printf("Case #%d: X won\n",cas++);
        else if (ans == 2) printf("Case #%d: O won\n",cas++);
        else if (ans == 3) printf("Case #%d: Draw\n",cas++);
        else printf("Case #%d: Game has not completed\n",cas++);
    }
    return 0;
}
