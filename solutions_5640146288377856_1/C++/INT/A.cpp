#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int f[1<<20];

int dfs(int p,int c,int w)
{
    //printf("P: %d\n",p);
    if (f[p]!=0x3f3f3f3f) return f[p];
    int cnt=0;
    int tmp=0;
    for (int i=0;i<c;i++)
    {
        if (p&(1<<i)) tmp=0;
        else
        {
            tmp++;
            if (tmp==w)
            {
                cnt++;
                tmp--;
            }

        }
        //printf("%d %d %d\n",i,tmp,cnt);
    }
    if (cnt==1) return f[p]=w;
    if (cnt==0) return f[p]=0x3f3f3f3f;
    int ret=0x3f3f3f3f;
    for (int i=0;i<c;i++)
        if (!(p&(1<<i)))
            ret=min(ret,dfs(p|(1<<i),c,w)+1);
    return f[p]=ret;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        int r,c,w;
        scanf("%d%d%d",&r,&c,&w);
        int ans=0;
        ans+=(r-1)*(c/w);
        memset(f,0x3f,sizeof(f));
        ans+=dfs(0,c,w);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
