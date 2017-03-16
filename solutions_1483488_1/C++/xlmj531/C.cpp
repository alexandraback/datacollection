#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 8;

int c[maxn], d[maxn], rec[maxn];
int A, B, n, tot, cas;

void trans(int x )
{
    n = 0;
    for (; x; x/=10 ) c[n++] = x%10;
}

int trans2(int d[] )
{
    int ret = 0;
    for (int i = n-1; i>=0; i-- )
        ret = ret*10+d[i];
    return ret;
}

int main()
{
    freopen("C1.in","r",stdin);
    freopen("C1.out","w",stdout);
    scanf("%d",&cas);
    for (int run = 1; run<=cas; run++ )
    {
        scanf("%d%d",&A,&B);
        int ans = 0;
        for (int x = A; x<=B; x++ )
        {
            trans(x);
            tot = 0;
            for (int i = 1; i<n; i++ )
            {
                for (int j = 0; j<n; j++ )
                    d[j] = c[(j+i)%n];
                if (d[n-1])
                {
                    int y = trans2(d);
                    if (y<x && A<=y)
                    {
                        bool ok = 1;
                        for (int k = 0; k<tot; k++ )
                            if (y==rec[k]) ok = 0;
                        if (ok) { ++ans; rec[tot++] = y; }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",run,ans);
    }
    //system("pause");
    return 0;
}
