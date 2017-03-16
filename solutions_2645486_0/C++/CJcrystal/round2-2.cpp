#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int T,E,R,N;
    int f[10][10];
    int value[20];
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for(int k = 1;k <= T; ++k)
    {
        memset(f,0,sizeof(f));
        scanf("%d%d%d",&E,&R,&N);
        for(int i = 1;i <= N; ++i)
        {
            scanf("%d",&value[i]);
        }
        f[0][E] = 0;
        for(int i = 1;i <= N; ++i)
        {
            for(int j = 0;j <= E; ++j)
            {
                for(int t = 0; t <= j; ++t)
                {
                    f[i][min(E,j - t + R)] = max(f[i][min(E,j - t + R)],f[i - 1][j] + value[i] * t);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i <= E; ++i)
        {
            if(f[N][i] > ans)
                ans = f[N][i];
        }
        printf("Case #%d: ",k);
        printf("%d\n",ans);
    }
    return 0;
}
