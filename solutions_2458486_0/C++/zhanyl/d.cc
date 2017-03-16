#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

struct point
{
    int begin[1<<20],next[21000000],end[21000000],k;
    void ini()
    {
        memset(begin,-1,sizeof(begin));
        k=0;
    }
    void insert(int u,int v)
    {
        end[k]=v;
        next[k]=begin[u];
        begin[u]=k++;
    }
}a;

int maxn,n,f[25],g[25][45],s[25],k,h[25];
bool vis[1<<20];
map<int,int>S;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d",&k,&n);
        for(int i=0;i<k;i++)
            scanf("%d",&h[i]);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&f[i],&s[i]);
            for(int j=0;j<s[i];j++)
                scanf("%d",&g[i][j]);
        }
        a.ini();
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        maxn=1<<n;
        for(int i=0;i<maxn;i++)
        {
            if(!vis[i])continue;
            S.clear();
            for(int j=0;j<k;j++)
                S[h[j]]++;
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                {
                    for(int k=0;k<s[j];k++)
                        S[g[j][k]]++;
                    S[f[j]]--;
                }
            for(int j=0;j<n;j++)
                if((i&(1<<j))==0 && S[f[j]])
                {
                    vis[i|(1<<j)]=1;
                    a.insert(i|(1<<j),i);
                }
        }
        if(!vis[maxn-1])
           {
               printf("Case #%d: IMPOSSIBLE\n",cas);
               continue;
           }
        memset(vis,0,sizeof(vis));
        vis[maxn-1]=1;
        for(int i=maxn-1;i>=0;i--)
        {
            if(!vis[i])continue;
            for(int j=a.begin[i];j!=-1;j=a.next[j])
                vis[a.end[j]]=1;
        }
        printf("Case #%d:",cas);
        int now=0;
        while(now<maxn-1)
        {
            int i=now;
            S.clear();
            for(int j=0;j<k;j++)
                S[h[j]]++;
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                {
                    for(int k=0;k<s[j];k++)
                        S[g[j][k]]++;
                    S[f[j]]--;
                }
            for(int j=0;j<n;j++)
                if((i&(1<<j))==0 && S[f[j]] && vis[i|(1<<j)])
                {
                    vis[i|(1<<j)]=1;
                    now=i|(1<<j);
                    printf(" %d",j+1);
                    break;
                }
        }
        puts("");
    }
    return 0;
}
