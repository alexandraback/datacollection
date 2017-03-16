#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <time.h>
#define maxn 10007
#define grantN 1000007
#define modp 1000000007
#define eps (5E-1)
#define minf2 (1E-10)
#define lim1 30
#define lim2 300

using namespace std;

typedef long long LL;
const double PI=4*atan(1);
const double PI2=PI*2;
int n,m,tot;
LL gg,jj;

typedef struct sege
{
    int b,e;
    //struct sege *nxt;
    friend int operator<(struct sege x, struct sege y)
    {
        return x.b<y.b;
    }
}E,*Ptr;

typedef struct mat {
    int m[10][10];
    int n;
    friend struct mat operator*(struct mat x, struct mat y)
    {
        struct mat r;
        r.n=x.n;
        for (int i=0;i<r.n;++i)
        for (int j=0;j<r.n;++j)
        {
            r.m[i][j]=0;
            for (int k=0;k<r.n;++k) r.m[i][j]+=x.m[i][k]*y.m[k][j];
        }
        return r;
    }
}MA;

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

int mod_inv(int a, int p)
{
    int x, y;
    extgcd(a, p, x, y);
    return (p + x % p) % p;
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

int check(MA x)
{
    for (int i=1;i<x.n;++i)
        for (int j=0;j<i;++j) if (x.m[j][i]) return 1;
    return 0;
}

int dfs(int dep, int x, int y, int t, MA* f)
{
    if (dep==f->n*(f->n-1)/2)
    {
        MA tmp=*f;
        int ans=0;
        while (check(tmp))
        {
            ans+=tmp.m[0][tmp.n-1];
            tmp=tmp*(*f);
        }
        if (ans==t) return 1;
        else return 0;
    }
        int xx=x,yy=y;
        ++xx;
        if (xx==y) {
            ++yy;
            xx=0;
        }
        f->m[x][y]=0;
        if (dfs(dep+1,xx,yy,t,f)) return 1;
        f->m[x][y]=1;
        return dfs(dep+1,xx,yy,t,f);
}

int f[3][20][20];

int main()
{
    int T;
    LL N;
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    scanf("%d",&T);
    //T=1;
    //while (scanf(" %s %s",s,t)!=EOF)
    srand(time(0));
    //printf("%d\n",strcmp("aaa","aaa"));
    //while (T--)
    for (int ci=1;ci<=T;++ci)
    {
        //scanf("%d",&n);
        int J,P,S,K;
        scanf("%d%d%d%d",&J,&P,&S,&K);
        printf("Case #%d: ",ci);
        memset(f,0,sizeof(f));
        int ans=0;
        for (int i=1;i<=J;++i)
        {
            for (int j=1;j<=P;++j)
            {
                for (int k=1;k<=S;++k)
                {
                    if (f[0][i][j]>=K||f[1][j][k]>=K||f[2][i][k]>=K) continue;
                    ++f[0][i][j];
                    ++f[1][j][k];
                    ++f[2][i][k];
                    ++ans;
                }
            }
        }
        printf("%d\n",ans);
        memset(f,0,sizeof(f));
        for (int i=1;i<=J;++i)
        {
            for (int j=1;j<=P;++j)
            {
                for (int k=1;k<=S;++k)
                {
                    if (f[0][i][j]>=K||f[1][j][k]>=K||f[2][i][k]>=K) continue;
                    ++f[0][i][j];
                    ++f[1][j][k];
                    ++f[2][i][k];
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }

        //memset(0,f,sizeof(f));
        //printf("\n");
    }
    return 0;
}
