#include <cstdio>
#include <cstdlib>
#include <cstring>
int t,n,m,x,y,lim; double ans; long long u,v;
void go(int x,int y,int z)
{
    if(x==y) {v+=(z>=lim); ++u; return;}
    if(x+1-z<=m*2) go(x+1,y,z); if(z+1<=m*2) go(x+1,y,z+1);
}
double calc(int x,int y)
{
    v=0,u=0; lim=x; go(0,y,0);
    return (double)v/(double)u;
}
int main()
{
    freopen("in2","r",stdin);
    freopen("out2","w",stdout);
    scanf("%d",&t);
    for(int I=1;I<=t;++I)
    {
        scanf("%d%d%d",&n,&x,&y); x=abs(x); y=abs(y);
        m=0; while(((++m)*2-1)*2-1<=n) n-=(m*2-1)*2-1; --m;
        if(x+y<=(m-1)*2) ans=1;
        else if(x+y>(m-1)*2+2) ans=0;
        else ans=calc(y+1,n);
        printf("Case #%d: %.8lf\n",I,ans+1e-8);
    }
    return 0;
}
