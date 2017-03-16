#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <time.h>
#define maxn 10007
#define grantN 1000007
#define eps (5E-1)
#define minf2 (1E-10)
#define lim1 30
#define lim2 300

using namespace std;

typedef long long LL;
const double PI=4*atan(1);
const double PI2=PI*2;
int n,m,tot,gg,jj;

typedef struct sege
{
    double b,e;
    struct sege *nxt;
}E,*Ptr;

LL qpow(int x, LL y, int p)
{
    LL res=1,b=x;
    while (y)
    {
        if (y&1) res=res*b%p;
        b=b*b%p;
        y>>=1;
    }
    return res;
}

void extgcd(int a, int b, int &x, int &y)
{
    if (b != 0) {
        extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1;
        y = 0;
    }
}

int mod_inv(int a, int modp)
{
    int x, y;
    extgcd(a, modp, x, y);
    return (modp + x % modp) % modp;
}

int invm(int x, int p)
{
    x%=p;
    if (x==0) return 0;
    else return mod_inv(x,p);
}

int crt(int x, int m1, int y, int m2)
{
    if (y>x) return ((y-x)%m2*invm(m1,m2)%m2*m1%m2+x)%m2;
    else return ((x-y)%m1*invm(m2,m1)%m1*m2%m1+y)%m1;
}

char s[30],t[30];

void dfs1(int dep, int sum)
{
    if (dep==n)
    {
        if (gg<0||abs(m-sum)<abs(gg-jj)||abs(m-sum)==abs(gg-jj)&&(m<gg)||abs(m-sum)==abs(gg-jj)&&(m==gg)&&(sum<jj)) {
            gg=m; jj=sum;
        }
        return;
    }
    if (t[dep]=='?')
        for (int i=0;i<10;++i)
        {
            dfs1(dep+1,sum*10+i);
        }
    else dfs1(dep+1,sum*10+t[dep]-48);
}

void dfs0(int dep, int sum)
{
    if (dep==n)
    {
        m=sum;
        dfs1(0,0);
        return;
    }
    if (s[dep]=='?')
        for (int i=0;i<10;++i)
        {
            dfs0(dep+1,sum*10+i);
        }
    else dfs0(dep+1,sum*10+s[dep]-48);
}

void pri(int x, int b)
{
    int y=x;
    int cnt=0;
    if (y==0) cnt=1; else
    while (y)
    {
        y/=10;
        ++cnt;
    }
    for (int i=0;i<b-cnt;++i) printf("0");
    printf("%d",x);
}

int main()
{
    int T;
    LL N;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    //T=1;
    //while (scanf(" %s %s",s,t)!=EOF)
    srand(time(0));
    //printf("%d\n",strcmp("aaa","aaa"));
    //while (T--)
    for (int ci=1;ci<=T;++ci)
    {
        //scanf("%d",&n);
        scanf("%s%s",s,t);
        n=strlen(s);
        printf("Case #%d: ",ci);
        gg=-1; jj=-1;
        dfs0(0,0);
        pri(gg,n);
        printf(" ");
        pri(jj,n);
        printf("\n");
    }
    return 0;
}
