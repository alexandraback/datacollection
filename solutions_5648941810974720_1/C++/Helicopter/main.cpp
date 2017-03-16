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
int n,m,tot,gg;

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

char s[3000];
int u[30];
int v[10];

int getI(char x)
{
    return u[x-'A'];
}
void iI(char x,int y)
{
    u[x-'A']-=y;
}

int main()
{
    int T;
    LL N;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&T);
    //T=1;
    //while (scanf(" %s %s",s,t)!=EOF)
    srand(time(0));
    //printf("%d\n",strcmp("aaa","aaa"));
    //while (T--)
    for (int ci=1;ci<=T;++ci)
    {
        //scanf("%d",&n);
        scanf("%s",s);
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        n=strlen(s);
        for (int i=0;i<n;++i)
        {
            ++u[s[i]-65];
        }
        printf("Case #%d: ",ci);
        v[0]+=getI('Z');
        iI('Z',v[0]);
        iI('E',v[0]);
        iI('R',v[0]);
        iI('O',v[0]);
        v[6]=getI('X');
        iI('S',v[6]);
        iI('I',v[6]);
        iI('X',v[6]);
        v[7]=getI('S');
        iI('S',v[7]);
        iI('E',v[7]);
        iI('V',v[7]);
        iI('E',v[7]);
        iI('N',v[7]);
        v[5]=getI('V');
        iI('F',v[5]);
        iI('I',v[5]);
        iI('V',v[5]);
        iI('E',v[5]);
        v[4]=getI('F');
        iI('F',v[4]);
        iI('O',v[4]);
        iI('U',v[4]);
        iI('R',v[4]);
        v[3]=getI('R');
        iI('T',v[3]);
        iI('H',v[3]);
        iI('R',v[3]);
        iI('E',v[3]);
        iI('E',v[3]);
        v[2]=getI('W');
        iI('T',v[2]);
        iI('W',v[2]);
        iI('O',v[2]);
        v[1]=getI('O');
        iI('O',v[1]);
        iI('N',v[1]);
        iI('E',v[1]);
        v[8]=getI('G');
        iI('E',v[8]);
        iI('I',v[8]);
        iI('G',v[8]);
        iI('H',v[8]);
        iI('T',v[8]);
        v[9]=getI('I');
        for (int j=0;j<10;++j)
        for (int i=0;i<v[j];++i) printf("%c",48+j);
        printf("\n");
    }
    return 0;
}
