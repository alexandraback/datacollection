#include<cstdio>
#include<cstring>
#define fd(i,a,b) for(i=a;i>=b;--i)
#define fo(i,a,b) for(i=a;i<=b;++i)
const int mn=1000;
int n,m,K,ans=0;
int d[mn],kd[mn];
bool f[mn];
bool sol=0;
void dfs(int r,int la,int v)
{
    if(r>n)
    {
        memset(f,0,sizeof f);
        f[1]=1;
        int i,j,lx=1;
        fo(j,1,n)
        {
            fd(i,lx,1)
                if(f[i])
                    f[i*d[j]]=1;
            lx*=d[j];
        }
        fo(i,1,K)if(!f[kd[i]])return;
        sol=1;
        ans=v;
        return;
    }
    int i;
    fo(i,la,m)
    {
        d[r]=i;
        dfs(r+1,i,v*10+i);
        if(sol)return;
    }
}
int main()
{
    int T,i,Q;
    scanf("%d",&T);
    puts("Case #1:");
    scanf("%d%d%d%d",&Q,&n,&m,&K);
    while(Q--)
    {
        fo(i,1,K)scanf("%d",kd+i);
        sol=0;
        dfs(1,2,0);
        printf("%d\n",ans);
    }
    return 0;
}
