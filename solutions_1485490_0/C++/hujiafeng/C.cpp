#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
long long a[1000][2],b[1000][2],c[1000][2];
long long ans,tmp;
int N,M;
bool v[100];
long long t;
#define MAXN 2000000000
void dfs(int s,int k,long long tmp)
{
    int i;

    if(s==N)
    {
        ans=max(ans,tmp);
        return ;
    }
    if(k==M)
    {
        ans=max(ans,tmp);
        return;
    }
    if(t>MAXN) return;
    t++;
    if(v[b[k][1]]==0) dfs(s,k+1,tmp);
    else
    {

        for(i=s; i<N; i++)
        {
            if(a[i][1]==b[k][1])
            {
                if(a[i][0]<=b[k][0])
                {
                    b[k][0]-=a[i][0];
                    dfs(i+1,k,tmp+a[i][0]);
                    b[k][0]+=a[i][0];
                }
                else
                {
                    a[i][0]-=b[k][0];
                    dfs(i,k+1,tmp+b[k][0]);
                    a[i][0]+=b[k][0];
                }
            }
        }
        dfs(s,k+1,tmp);
    }
}
int main()
{
    freopen("C-small-attempt3.in","r",stdin);
    freopen("C.out","w",stdout);
    int T,i;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        t=0;
        printf("Case #%d: ",cas);
        scanf("%d%d",&N,&M);
        memset(v,0,sizeof(v));
        for(i=0; i<N; i++)
        {
            scanf("%lld%lld",&a[i][0],&a[i][1]);
            v[a[i][1]]=1;
        }
        for(i=0; i<M; i++)
        {
            scanf("%lld%lld",&c[i][0],&c[i][1]);
        }
        int kk=-1,num=0;
        for(i=0;i<M;i++)
        {
            if(v[c[i][1]]==0) continue;
            else
            {
                if(kk==-1)
                {
                    kk=0;
                    b[num][0]=c[i][0];
                    b[num][1]=c[i][1];
                    num++;
                }else if(b[num-1][1]==c[i][1])
                {
                    b[num-1][0]==c[i][0];
                }else
                {
                    b[num][0]=c[i][0];
                    b[num][1]=c[i][1];
                    num++;
                }
            }
        }
        M=num;
        ans=0;
        dfs(0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
