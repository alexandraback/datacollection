#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int s[501][5001];
int main()
{
    int cas,n,m,K,i,j,k;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d%d%d",&n,&m,&K);
        memset(s,0,sizeof(s));
        for (i=1; i<=n; i++)
        {
            s[1][i]=1;
        }
        for ( i=2; i<=m; i++)
        {
            for ( k=0; k<=K; k++)
            {
                for (j=1; j<=n; j++)
                {
                    if (k-j>0)
                    {
                        s[i][k]+=s[i-1][k-j];

                    }
                }
                s[i][k]%=10000;
            }
        }
        printf("%d\n",s[m][K]);
    }
    return 0;
}
