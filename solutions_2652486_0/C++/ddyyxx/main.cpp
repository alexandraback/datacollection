#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10],ans[10],n,m,k,vis[10];
int dfs(int now)
{
    int i,j;
    if(now==n+1)
    {
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++)
        vis[ans[i]]++;
        for(i=1;i<=k;i++)
        {
            if(a[i]==1)
            continue;
            int tmp=a[i];
            for(j=2;j<=m;j++)
            {
                if(vis[j]>0)
                {
                    int num=vis[j];
                    while(1)
                    {
                        if(num==0||tmp%j)
                        break;
                        tmp/=j;
                        num--;
                    }
                }
            }
            if(tmp!=1)
            return 0;
        }
        for(i=1;i<=n;i++)
        printf("%d",ans[i]);
        return 1;
    }
    for(i=2;i<=m;i++)
    {
        ans[now]=i;
        if(dfs(now+1))
        return 1;
    }
    return 0;
}
int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("out.txt","w+",stdout);
    int r,ncase,time=0;
    scanf("%d",&ncase);
    while(ncase--)
    {
        printf("Case #%d:\n",++time);
        scanf("%d%d%d%d",&r,&n,&m,&k);
        int i,num=0;
        while(r--)
        {
            for(i=1;i<=k;i++)
            scanf("%d",&a[i]);
            if(!dfs(1))
            {
                //for(i=0;i<n;i++)
                //{
                    printf("234");
                //}
            }
            printf("\n");
        }
    }
    return 0;
}
