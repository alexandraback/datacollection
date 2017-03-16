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
#define Read()  freopen("C-small-attempt0.in", "r", stdin)
#define Write() freopen("dout.txt", "w", stdout);
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)

#define M 137
#define N 1002

using namespace std;

const int inf = 100000007;

int tmp[20],len;
int zp[20],lz;

int res[N];

int main()
{
    Read();
    Write();
    int i,j,k;
    int T,cas = 1;
    int ans = 0;
    CL(res,0);
    for (i = 1; i <= 1000; ++i)
    {
        double p = sqrt(i);
        if (p == (int)p)
        {
            int no = i; len = 0;
            while (no)
            {
                tmp[len++] = no%10;
                no/=10;
            }
            no = (int)p; lz = 0;
            while (no)
            {
                zp[lz++] = no%10;
                no/=10;
            }

            int flag = 0;
            for (k = 0,j = len - 1; k <= j; ++k,--j)
            {
                if (tmp[k] != tmp[j]) break;
            }
            if (k > j) flag++;
            for (k = 0,j = lz - 1; k <= j; ++k,--j)
            {
                if (zp[k] != zp[j]) break;
            }
            if (k > j) flag++;

            if (flag == 2) ans++;

            res[i] = ans;
        }
        else res[i] = ans;
    }
    scanf("%d",&T);
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
//        printf(">>>%d %d\n",res[x - 1],res[y]);
        printf("Case #%d: %d\n",cas++,res[y] - res[x - 1]);
    }

    return 0;
}
