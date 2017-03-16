#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 210
using namespace std;
struct node
{
    int order[22],top;
    void clear()
    {
        top=0;
    }
    bool operator < (const node a)
    {
        for(int i=0;i<top;i++)
        {
            if(order[i]==a.order[i])continue;
            return order[i]<a.order[i];
        }
    }
    void push(int x)
    {
        order[top++]=x;
    }
}hh[1<<21];
int vis[1<<21],cnt[N],fa[1<<21];
int own[22][N],key[22];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        memset(own,0,sizeof(own));
        memset(fa,-1,sizeof(fa));
        int k,n;
        scanf("%d%d",&k,&n);
        for(int i=1;i<=k;i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        for(int i=1;i<=n;i++)
        {
            int m;
            scanf("%d%d",&key[i],&m);
            for(int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                own[i][x]++;
            }
        }
        vis[0]=1;hh[0].clear();
        int all=(1<<n)-1;
        for(int i=0;i<=all;i++)
        {
            if(!vis[i])continue;
            for(int j=0;j<n;j++)
                if(!(i&(1<<j)))
                {
                    int h=key[j+1];
                    int num=cnt[h];
                    for(int k=0;k<n;k++)
                        if(i&(1<<k))
                        {
                            if(key[k+1]==h)num--;
                            num+=own[k+1][h];
                        }
                    if(num>0)
                    {
                        int id=i|(1<<j);
                        if(!vis[id])
                        {
                            vis[id]=1;
                            hh[id]=hh[i];
                            hh[id].push(j+1);
                        }
                        else
                        {
                            node temp=hh[i];
                            temp.push(j+1);
                            if(temp<hh[id])
                                hh[id]=temp;
                        }
                    }
                }
        }
        printf("Case #%d:",++T);
        if(!vis[all])puts(" IMPOSSIBLE");
        else
        {
            for(int i=0;i<hh[all].top;i++)
            {
                printf(" %d",hh[all].order[i]);
            }
            puts("");
        }
    }
    return 0;
}
