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
#define ll long long
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


#define M 30007
#define N 1000007

using namespace std;

const int inf = 100000007;
const int mod = 1000000007;
const double eps = 1e-6;

char s[N];
int a[N];

int main()
{
    Read();
    Write();
    int n,T;
    int cas = 1;
    int i,j,k,p;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s%d",s,&n);
        int len = strlen(s);
        for (i = 0; i < len; ++i)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            a[i] = 0;
            else a[i] = 1;
        }
//        for (i = 0; i < len; ++i) printf("%d",a[i]);
//        printf("\n");
        ll ans = 0;
        for (k = n; k <= len; ++k)
        {
            for (i = 0; i + k <= len; ++i)
            {
                j = i + k;
                int cnt = 0;
//                printf("%d %d\n",i,j);
                for (p = i; p < j; ++p)
                {
                    if (a[p] == 1)
                    {
                        cnt++;
                        if (cnt >= n)
                        {
                            ans++;
                            break;
                        }
                    }
                    else cnt = 0;
                }
            }
        }
        cout<<"Case #"<<cas++<<":"<<" "<<ans<<endl;
    }

    return 0;
}
