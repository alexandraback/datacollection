#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int s[2000][2000];
bool vis[2000];
bool boo[2000];
bool gao2(int x)
{
    if(vis[x]) return true;
    vis[x] = true;
    for(int i = 1; i <=s[x][0]; i++)
    {
        int tmp = s[x][i];
        if(gao2(tmp)) return true;
    }
    return false;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int Cas,cas,i,j,n,m;
    scanf("%d",&Cas);
    for (int cas=0; cas<Cas; cas++)
    {
        memset(s,0,sizeof(s));
        memset(boo,0,sizeof(boo));

        scanf("%d",&n);
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for (int j=0; j<m; j++)
            {
                int tmp;
                scanf("%d",&tmp);
                s[i][0]++;
                s[i][s[i][0]]=tmp;
                boo[tmp]=true;
            }
        }
        printf("Case #%d: ",cas+1);
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            if(!boo[i])
            {
                memset(vis,0,sizeof(vis));
                if(gao2(i))
                    flag=1;
            }
        }
        if (flag==1) printf("Yes\n");
        else printf("No\n");


    }
}
