#include <iostream>
#include <cstdio>
using namespace std;
int map[105][105];
int tmap[105][105];
int n,m;
bool judge()
{
    for(int i=1;i<=n;i++)
    {
        int t=0;
        for(int j=1;j<=m;j++)
        {
            t=max(t,map[i][j]);
        }
        for(int j=1;j<=m;j++)
        {
            tmap[i][j]=t;
        }
    }
    for(int j=1;j<=m;j++)
    {
        int t=0;
        for(int i=1;i<=n;i++)
        {
            t=max(t,map[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            tmap[i][j]=min(tmap[i][j],t);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(map[i][j]!=tmap[i][j])
            {
                //cout<<"wrong "<<i<<" "<<j<<" "<<map[i][j]<<" "<<tmap[i][j]<<endl;
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        }
        printf("Case #%d: ",cas++);
        if(judge())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
