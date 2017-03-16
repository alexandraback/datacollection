#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#define maxn 100
using namespace std;
long long dp[maxn+10][maxn+10];
long long aNum[maxn+10], aType[maxn+10], bNum[maxn+10], bType[maxn+10];
int CAS;
int n, m;
long long arr1[maxn + 10],arr2[maxn+10];
long long maxx(long long a,long long b)
{
    return a < b ? b : a;
}
long long minx(long long a,long long b)
{
    return a < b ? a : b;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&CAS);
    for(int cas = 1;cas <= CAS;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++)
            scanf("%I64d%I64d",aNum+i,aType+i);
        for (int i = 1; i <= m; i++)
            scanf("%I64d%I64d",bNum+i,bType+i);
        aNum[0] = bNum[0] = 0;
        aType[0] = bType[0] = maxn+10;
        memset(dp,0,sizeof(dp));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(i > 0)
                    dp[i][j] = maxx(dp[i-1][j], dp[i][j]);
                if(j > 0)
                    dp[i][j] = maxx(dp[i][j], dp[i][j-1]);
                if (i > 0 && j > 0)
                    dp[i][j] = maxx(dp[i][j], dp[i-1][j-1]);
                memset(arr1,0,sizeof arr1);
                for(int k = i+1; k <= n; k++)
                {
                    memset(arr2,0,sizeof arr2);
                    arr1[aType[k]] += aNum[k];
                    for(int p = j+1; p <= m; p++)
                    {
                        arr2[bType[p]] += bNum[p];
                        dp[k][p] = maxx(dp[k][p], dp[i][j] + min(arr1[aType[k]], arr2[aType[k]]));
                    }
                }
            }

        long long ans = 0;
        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= m;j++)
                ans = maxx(ans,dp[i][j]);
        printf("Case #%d: %I64d\n",cas,ans);
    }
    fclose(stdin);
    fclose(stdout);
}
