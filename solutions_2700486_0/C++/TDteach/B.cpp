#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

#define maxn 137

double f[maxn][maxn];
int n;

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    
    int cases, k;
    int x, y;
    int l, r, tmp, w;
    int i, j;
    double ans;
    
    scanf("%d",&cases);
    for (k = 1; k <= cases; ++k) {
        printf("Case #%d: ",k);
        scanf("%d%d%d",&n,&x,&y);
        if (x < 0) x = -x;
        if ((x+y)&1) {
            printf("0.000000\n");
            continue;
        }
        l = 0; tmp = 1;
        for (i = 0; i < (x+y)/2; ++i) {
            l += tmp+tmp-1;
            tmp += 2;
            if (l >= n) break;
        }
        r = l+tmp+y;
        if (x == 0) l = r-1;
        if (n <= l) {
            printf("0.000000\n");
            continue;
        }
        if (n >= r) {
            printf("1.000000\n");
            continue;
        }
        n -= l;
        ++y;
        f[0][0] = 1;
        for (i = 0; i < tmp; ++i) {
            if (i > 0)
                f[i][0] = f[i-1][0]*0.5;
            for (j = 1; j < y; ++j) {
                f[i][j] = 0;
                f[i][j] += f[i-1][j]*0.5;
                f[i][j] += f[i][j-1]*0.5;
                if (i == tmp-1)
                    f[i][j] += f[i][j-1]*0.5;
            }
        }
        ans = 1;
        for (j = 0; j < y; ++j) {
            if (n-j >= tmp) continue;
            ans -= f[n-j][j];
        }
        printf("%.6lf\n",ans);
    }
    
    return 0;
}
