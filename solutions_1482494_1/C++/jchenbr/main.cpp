#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int N=1000;


int get_ans()
{
    int n;
    cin>>n;
    int a[N+5],b[N+5];
    int vis[N+5];

    memset(vis,0,sizeof(vis));
    for (int i=0;i<n;i++)scanf("%d %d",a+i,b+i);

    int ret=0,now=0;
    bool ok=true;
    
    while (ok)
    {
        ok=false;
        for (int i=0;i<n;i++)
            if (b[i]<=now&&vis[i]!=2)
            {
                ret+=1;
                now+=2-vis[i];
                vis[i]=2;
                ok=true;
            }
        if (ok)continue;
        int u=-1,sta=-1;
        for (int i=0;i<n;i++)
            if (a[i]<=now&&vis[i]==0)
            {
                ok=true;
                if (b[i]>sta)
                {
                    u=i,sta=b[i];
                }
            }
        if (u>=0)
        {
            ret+=1;
            now+=1;
            vis[u]=1;
        }
    }
    if (now!=2*n)return -1;
    else return ret;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int total,cc=0;
    cin>>total;
    while (total--)
    {
        int tmp=get_ans();
        if (tmp<0)
            printf("Case #%d: Too Bad\n",++cc);
        else
            printf("Case #%d: %d\n",++cc,tmp);
    }
}