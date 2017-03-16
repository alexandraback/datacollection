#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
int n,m,len;
int a[110][110];
int ii[110];
int jj[110];
int s[128]={0};
int main()
{
        int i,j,k,tot,ttl;
        scanf("%d",&tot);
        for(ttl=1;ttl<=tot;ttl++)
        {
            scanf("%d%d",&n,&m);
            memset(ii,0,sizeof(ii));
            memset(jj,0,sizeof(jj));
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    scanf("%d",&a[i][j]);
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                {
                    ii[i]=max(ii[i],a[i][j]);
                    jj[j]=max(jj[j],a[i][j]);
                }
            int ans=1;
            for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(a[i][j]-ii[i]&&a[i][j]-jj[j])
                        ans=0;
            if(ans)
                printf("Case #%d: YES\n",ttl);
            else printf("Case #%d: NO\n",ttl);
        }
        
        return 0;
}
