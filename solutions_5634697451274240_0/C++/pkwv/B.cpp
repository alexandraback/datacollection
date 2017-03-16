//#pragma comment(linker,"/STACK:102400000,102400000")
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>
#include<list>
//#include<ext/rope>
#define PB push_back
#define MP make_pair
#define PF push_front
#define lson k<<1
#define rson k<<1|1
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;

const int N = 105;
const int INF = 1000000000;
int f[N][N][2][2];
char str[N], ch[] = "-+";

void update(int &res, int val)
{
    res = min(res, val);
}

int dfs(int l, int r, int d, int c)
{
    if(f[l][r][d][c] != -1) return f[l][r][d][c];
    if(l == r)
    {
        if(str[l] == ch[d]) f[l][r][d][c] = 0;
        else f[l][r][d][c] = 1;
        return f[l][r][d][c];
    }
    f[l][r][d][c] = INF;
    /// assume is better
    for(int i = l; i < r; i++)
        update(f[l][r][d][c], dfs(l, i, !d, 0) + 1 + dfs(i + 1, r, !d, 1));
//    if(l == 0 && r == 2 && d == 0)
//        printf("~~~  %d  %d  %d\n", d, c, f[l][r][d][c]);
    if(c == 0)
    {
        for(int i = r; i > l; i--)if(str[i] == ch[d])
            {
                update(f[l][r][d][c], dfs(l, i - 1, d, c));
            }
            else break;
//        if(l == 0 && r == 2 && d == 0) printf("~~~~~~~~~~~~  %d\n", f[l][r][d][c]);
    }
    else
    {
        for(int i = l; i < r; i++)
            if(str[i] == ch[d])
                update(f[l][r][d][c], dfs(i + 1, r, d, c));
            else break;
    }
//    bool ok(true);
//    for(int i = l; i <= r; i++)
//        if(str[i] != str[l]) ok = false;
//    if(ok)
//    {
//        int c(1);
//        if(d == 0 && str[l] == '-' || d == 1 && str[l] == '+') c = 0;
//        else c = 1;
//        update(f[l][r][d], c);
//    }
//    printf("%d  %d  %d  %d  %d==\n", l, r, d, c, f[l][r][d][c]);
    return f[l][r][d][c];
}

int main()
{
#ifdef PKWV
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out","w",stdout);
#endif // PKWV
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++)
    {
        scanf("%s", str);
        int len = strlen(str);
        memset(f, -1, sizeof(f));
        printf("Case #%d: %d\n", cas, dfs(0, len - 1, 1, 0));
    }
    return 0;
}

