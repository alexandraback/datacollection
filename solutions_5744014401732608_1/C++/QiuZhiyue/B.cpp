#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[55][55];
int main()
{
    freopen("2lar.in","r",stdin);
    freopen("2lar.out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        int n;
        long long m;
        cin>>n>>m;
        if((1LL<<(n-2))<m)
        {
            printf("Case #%d: IMPOSSIBLE\n",++cas);
            continue;
        }
        printf("Case #%d: POSSIBLE\n",++cas);
        memset(a,0,sizeof(a));
        for(int i=1;i<n;i++)
        for(int j=i+1;j<n;j++) a[i][j]=1;
        for(int i=2;i<n;i++)
        {
            if(m&(1LL<<(i-2)))
            a[i][n]=1;
        }
        if((1LL<<(n-2))==m)
        for(int i=1;i<n;i++) a[i][n]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
            printf("%d",a[i][j]);
            printf("%d\n",a[i][n]);
        }
    }

    return 0;
}
