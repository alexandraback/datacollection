#include<stdio.h>
#include<algorithm>
#define maxn 10005
using namespace std;

int T,L,X,n,sol;
int a[5][5]={ {0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1} };
int v[maxn],p[maxn],used[10];
char s[maxn];

void read()
{
    scanf("%d %d\n",&L,&X);
    scanf("%s\n",s+1);

    for(int i=1;i<X;i++)
     for(int j=1;j<=L;j++)
      s[i*L+j]=s[j];

    n=L*X;
}

int sig(int x)
{
    if(x<0) return -1;
    if(x>0) return 1;
    return 0;
}

int conv(char ch)
{
    if(ch=='1') return 1;
    return ch-'i'+2;
}

int trans(int x)
{
    if(x<0) return -x+4;
    return x;
}

void solve()
{
    if(n<3) {sol=0; return;}

    int x;
    for(int i=1;i<=n;i++) v[i]=conv(s[i]);

    p[1]=v[1];
    for(int i=2;i<=n;i++)
      p[i]= a[abs(p[i-1])][v[i]]*sig(p[i-1]);

    for(int i=1;i<=10;i++) used[i]=0;

    int nr=v[n];
    if(nr==4) used[ trans(p[n-1]) ]=1;

    sol=0;
    for(int i=n-2;i;i--)
    {
        if(p[i]==2)
        {
            x=a[abs(p[i])][3]*sig(p[i]);
            if(used[ trans(x) ]) {sol=1; break;}
        }

        nr=a[v[i+1]][abs(nr)]*sig(nr);
        if(nr==4) used[ trans(p[i]) ]=1;
    }
}

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d\n",&T);
    for(int it=1;it<=T;it++)
    {
        read();
        solve();
        if(sol) printf("Case #%d: YES\n",it);
        else printf("Case #%d: NO\n",it);
    }

    return 0;
}
