#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct point
{
    int x,y;
};
int n,m,d,ans,ix,iy;
int s[10000][3];
int top;
point l[10000];
int h,t;

inline int sqr(int x)
{
    return x*x;
}

int mod(int x,int y)
{
    if (x>0) return x%y;
    return x%y+y;
}

void up()
{
    ++t;
    s[t][0]=s[h][0]-2*mod(s[h][0],n);
    s[t][1]=s[h][1];
    s[t][2]=1;
}

void down()
{
    ++t;
    s[t][0]=s[h][0]+2*(n-mod(s[h][0],n));
    s[t][1]=s[h][1];
    s[t][2]=3;
}

void left()
{
    ++t;
    s[t][0]=s[h][0];
    s[t][1]=s[h][1]-2*mod(s[h][1],m);
    s[t][2]=4;
}

void right()
{
    ++t;
    s[t][0]=s[h][0];
    s[t][1]=s[h][1]+2*(m-mod(s[h][1],m));
    s[t][2]=2;
}

int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}

int abs(int x)
{
    if (x<0) return -x;
    return x;
}

void work()
{
    s[1][0]=ix;s[1][1]=iy;s[1][2]=0;
    h=0;t=1;
    while (h<t)
    {
        ++h;
        if (sqr(ix-s[h][0])+sqr(iy-s[h][1])>d*d)
            continue;
        if (h!=1)
        {
            l[++top].x=ix-s[h][0];
            l[top].y=iy-s[h][1];
            if (l[top].x==0) l[top].y/=abs(l[top].y);
            if (l[top].y==0) l[top].x/=abs(l[top].x);
            if (l[top].x!=0 && l[top].y!=0)
            {
                int g=gcd(l[top].x,l[top].y);
                g=abs(g);
                l[top].x/=g;l[top].y/=g;
            }
        }
        if (s[h][2]!=3)
            up();
        if (s[h][2]!=1)
            down();
        if (s[h][2]==0 || s[h][2]==2)
            right();
        if (s[h][2]==0 || s[h][2]==4)
            left();
    }
}

bool cmp(point x,point y)
{
    if (x.x<y.x) return true;
    if (x.x>y.x) return false;
    return x.y<y.y;
}

void final()
{
    sort(l+1,l+1+top,cmp);
    for (int i=1;i<=top;++i)
        if (i==1 || l[i].x!=l[i-1].x || l[i].y!=l[i-1].y)
        {
            ++ans;
        }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int tot_tc;
    scanf("%d",&tot_tc);
    for (int tc=1;tc<=tot_tc;++tc)
    {
        scanf("%d%d%d\n",&n,&m,&d);
        d*=2;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
            {
                char x;
                scanf(" %c",&x);
                if (x=='X')
                {
                    ix=2*i-1;
                    iy=2*j-1;
                }
            }
        n=2*n-4;m=2*m-4;
        ans=0;top=0;
        work();
        final();
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
