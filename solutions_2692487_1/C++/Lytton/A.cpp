#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (100+10)
#define oo (100000)

int  f[MAXN][1000];
int t, m, p, n;
int a[MAXN];

void doit()
{
    int i, j;
    int p = 0;

    for (int i = 0;i <= n;++i)
        for (int j = 0;j <= n;++j)
            f[i][j] = -oo;
    f[0][0] = m;
    for (int j = 1;j <= n;++j)
    {
        f[0][j] = 2*f[0][j-1]-1;
        if (f[0][j] > a[n]+1)
        {
            f[0][j] = a[n]+1;
          //  p = j;
         //   break;
        }
       //  cout << 0 << ' ' << j << ' ' << f[i][j] << endl;
    }
   // cout << f[0][3] << endl;
    for (int i = 1;i <= n;++i)
        for (int j = 0;j <= n;++j)
        {
            if (j > 0)
            {
                f[i][j] = f[i-1][j-1];
            }
            if (f[i-1][j] > a[i]) f[i][j] = max(f[i][j], f[i-1][j]+a[i]);
          //  for (int k = 0;k < j;++k)
          //  {
                if (j > 0 && 2*f[i-1][j-1]-1 > a[i])
                {
                    f[i][j] = max(f[i][j], 2*f[i-1][j-1]-1+a[i]);
                }
          //  }
            if (f[i][j-1]*2-1 > a[i])
                f[i][j] = max(f[i][j], f[i][j-1]*2-1);
            if (f[i][j] > a[n]+1) f[i][j] = a[n]+1;
        //    cout << i << ' ' << j << ' ' << f[i][j] << endl;
        }
    j = n;
    while (f[n][j] > 0 && j >= 0) --j;
    printf("%d\n",j+1);

}

int main()
{
    int k;

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    cin >> t;

    for (int w = 1;w <= t;++w)
    {
        cin >> m >> n;
        for (int i = 1;i <= n;++i)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
     //   cout << a[1] << endl;
        printf("Case #%d: ",w);
        doit();
    }

    return 0;
}
