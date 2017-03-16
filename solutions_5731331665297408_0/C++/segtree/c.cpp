#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n,m,g[10][10],s[10],cnt,t[10],w[10],top;
struct num
{
    int a[10];
    bool operator <(const num &o) const
    {
        for(int i=0;i<n;++i)
            if(w[a[i]]<w[o.a[i]]) return 1;
            else if(w[a[i]]>w[o.a[i]]) return 0;
        return 0;
    }
} l[10000005];
struct vtx
{
    int x,y;
    bool operator <(const vtx &o) const {return y<o.y;}
} p[10];
void go(int x,int y,int z,int w)
{
    if(w==-1) {t[y]=x; z|=1<<x; s[++top]=x;}
    //printf("%d %d %d %d %d\n",x,y,z,w,top);
    if(y==n-1)
    {
        for(int i=0;i<n;++i) l[cnt].a[i]=t[i];
        ++cnt; if(w==-1) --top; else s[++top]=w; return;
    }
    if(top>1) go(s[--top],y,z,x);
    for(int i=0;i<n;++i) if(g[x][i]&&!((1<<i)&z)) go(i,y+1,z,-1);
    if(w==-1) --top; else s[++top]=w; return;
}
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%d%d",&n,&m); memset(g,0,sizeof(g)); int x,y; cnt=top=0;
        for(int i=0;i<n;++i) {p[i].x=i; scanf("%d",&w[i]); p[i].y=w[i];}
        while(m--) {scanf("%d%d",&x,&y); --x; --y; g[x][y]=g[y][x]=1;}
        sort(p,p+n); go(p[0].x,0,0,-1); sort(l,l+cnt);
        printf("Case #%d: ",I);
        for(int i=0;i<n;++i) printf("%d",w[l[0].a[i]]);
        printf("\n");
        /*
        for(int i=0;i<cnt;++i)
        {
            for(int j=0;j<n;++j) printf("%d ",l[i].a[j]);
            printf("\n");
        }
        */
    }
    return 0;
}
