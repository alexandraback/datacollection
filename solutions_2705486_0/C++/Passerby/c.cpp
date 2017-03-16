#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int m=521196;
char s[55]; int t,ans,n; bool f[55],g[55];
struct node
{
    bool f; node *c[26];
    node() {f=0; memset(c,0,sizeof(c));}
} *root=new node;
void ins(node *&p,char *s,int x,int l)
{
    if(!p) p=new node;
    if(x==l) ++p->f; else ins(p->c[s[x]-'a'],s,x+1,l);
}
void build()
{
    FILE *f=fopen("dict","r");
    for(int i=0;i<m;++i)
    {
        fscanf(f,"%s",s);
        ins(root,s,0,strlen(s));
    }
}
/*
char p[530000][11];
void build()
{
    FILE *f=fopen("dict","r");
    for(int i=0;i<m;++i) fscanf(f,"%s",p[i]);
}
*/
void trans(node *p,int x)
{
    if(!p||x>n) return;
    if(p->f) g[x]=1;
    if(!f[x]) trans(p->c[s[x]-'a'],x+1);
    else for(int i=0;i<26;++i) trans(p->c[i],x+1);
}
bool check()
{
    memset(g,0,sizeof(g)); g[0]=1;
    for(int i=0;i<n&&!g[n];++i) if(g[i]) trans(root,i);
    return g[n];
}
void go(int x,int y,int z)
{
    if(y>ans) return;
    if(x==n)
    {
        if(check()) ans=min(ans,y);
        return;
    }
    if(x>=z) {f[x]=1; go(x+1,y+1,x+5); f[x]=0;}
    go(x+1,y,z);
}
int main()
{
    freopen("in3","r",stdin);
    freopen("out3","w",stdout);
    build(); scanf("%d",&t);
    for(int I=1;I<=t;++I)
    {
        scanf("%s",s); ans=n=strlen(s);
        go(0,0,0); printf("Case #%d: %d\n",I,ans);
    }
    return 0;
}
