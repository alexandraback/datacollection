#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define maxn 110
#define mod 1000000007
using namespace std;
int father[maxn];
int sum[maxn];
int G[maxn][maxn];
int ind[maxn],outd[maxn];
int used[maxn];
void init()
{
    for(int i=0;i<maxn;++i)
    {
        father[i]=i;
        sum[i]=1;
    }
}
int Find(int x)
{
    return father[x]==x?x:father[x]=Find(father[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x==y)return;
    father[y]=x;
    sum[x]+=sum[y];//¸üÐÂsum
}
string a[maxn];
char f[maxn],l[maxn];
int Count(int x){
    if(x==0||x==1)return 1;
    int ans = 1;
    while(x){
        ans = (ans *x)%mod;
        x--;
    }
    return ans ;
}
int n;
void dfs(int u){
    used[u]=1;
    for(int i=1;i<=n;++i){
        if(i!=u&&G[u][i]==1&&!used[i]){
            dfs(i);
        }
    }
}
int main ()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int t;
    cin>>t;
    for(int Case=1;Case<=t;++Case){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i){
            int len =a[i].length();
            f[i]=a[i][0];
            l[i]=a[i][len-1];
        }
        memset(G,0,sizeof(G));
        memset(ind,0,sizeof(ind));
        memset(outd,0,sizeof(outd));
        memset(used,0,sizeof(used));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(l[i]==f[j]&&i!=j){
                    G[i][j]=1;
                    outd[i]++;
                    ind[j]++;
                }
            }
        }
        int f=1;
        for(int i=1;i<=n;++i){
            if(outd[i]==0&&ind[i]==0){
                f=0;
                break;
            }
        }
        printf("Case #%d: ",Case);
        if(!f){printf("0\n");continue;}
        init();
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i!=j){
                    if(G[i][j]==1&&G[j][i]==1){
                        Union(i,j);
                    }
                }
            }
        }
        int ans=1;
        for(int i=1;i<=n;++i){
            ans = (ans*Count(sum[i]))%mod;
        }
        int cnt =0;
        for (int i=1;i<=n;++i){
            if(!used[i]){
                dfs(i);
                cnt++;
            }
        }
        ans = (ans*cnt)%mod;
        printf("%d\n",ans);
    }
}
