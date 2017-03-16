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
#define Read()  freopen("B-large.in", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)

#define M 137
#define N 107

using namespace std;

int n,m;
int mat[N][N];
int rma[N],cma[N];

int main()
{
    Read();
    Write();
    int T,i,j;
    int cas = 1;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= m; ++j)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        for (i = 1; i <= n; ++i) rma[i] = mat[i][1];

        for (i = 1; i <= m; ++i) cma[i] = mat[1][i];

        for (i = 1; i <= n; ++i)
        {
            for (j = 1; j <= m; ++j)
            {
                rma[i] = max(rma[i],mat[i][j]);
                cma[j] = max(cma[j],mat[i][j]);
            }
        }
//        for (i = 1; i <= n; ++i) printf("%d ",rma[i]);
//        printf("\n");
//        for (i = 1; i <= m; ++i) printf("%d ",cma[i]);
//        printf("\n");
        bool flag = true;
        for (i = 1; i <= n && flag; ++i)
        {
            for (j = 1; j <= m && flag; ++j)
            {
                if (mat[i][j] < rma[i] && mat[i][j] < cma[j])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        printf("Case #%d: YES\n",cas++);
        else
        printf("Case #%d: NO\n",cas++);

    }
}
