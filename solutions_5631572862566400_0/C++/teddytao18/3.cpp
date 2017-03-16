#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

bool used[1010];
int bff[1010];

int dfs(int now, int depth, int n, int start, int last, int second)
{
    if (used[now])
        return 0;
    int i,res1,res2;
    /*
    for (i=1;i<=n;i++)
        if (used[i] || i==now)
            printf("%d ",i);
    printf("\n");
    printf("now: %d %d %d %d %d\n",now,depth,start,last,second);
    */
    res1=0; res2=0; used[now]=true;
    if (!used[bff[now]] && (bff[last]==now || !last))
    {
        if (now==start)
            res1=dfs(bff[now],depth+1,n,start,now,bff[now]);
        else res1=dfs(bff[now],depth+1,n,start,now,second);
    }
    for (i=1;i<=n;i++)
        if ((bff[i]==now && !used[i]) || 
                (last && bff[now]==last && bff[last]==now && !used[i]))
            if (bff[now]==last || bff[now]==i)
            {
                if (now==start)
                    res2=max(res2,dfs(i,depth+1,n,start,now,i));
                else res2=max(res2,dfs(i,depth+1,n,start,now,second));
            }
    used[now]=false;
    if (res1>depth || res2>depth)
        return max(res1,res2);
    if (bff[start]==now || bff[now]==start ||
            (bff[start]==second && bff[now]==last))
    {
        //printf("return %d\n",depth);
        return depth;
    }
    else return 0;
}

int main()
{
    int i,j,n,t,ans,count,T;
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            scanf("%d",&bff[i]);
        ans=0;
        for (i=1;i<=n;i++)
        {
            memset(used,0,sizeof(used));
            /*
               while (!used[j])
               {
               used[j]=true;
               j=bff[j];
               count++;
               }
               ans=max(ans,count);
             */
            ans=max(ans,dfs(i,1,n,i,0,0));
        }
        printf("%d\n",ans);
    }
}
