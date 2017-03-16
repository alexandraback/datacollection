

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>


#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-8



#define pii pair<int,int>
#define FFF freopen("test","r",stdin)
#define all(a) a.begin(),a.end()

using namespace std;


void output(i64 x)
{
    if(x<0) putchar('-'),x=-x;
    if(x==0)
    {
        putchar('0');
        return;
    }
    int a[20],num=0;
    while(x) a[++num]=x%10,x/=10;
    while(num>0) putchar('0'+a[num--]);
}

inline i64 myInt()
{
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    int flag=1;
    if(c=='-') flag=-1,c=getchar();
    i64 x=0;
    while(isdigit(c))
    {
        x=(x*10)+(c-'0');
        c=getchar();
    }
    if(-1==flag) return -x;
    return x;
}


const i64 INF=1e16;
const int mod=1000000007;
const int N=1000005;



int a[22][22];




int n,m,d,h,D1,D2;

int cal()
{
    n=myInt();
    int t1,t2;
    for(int i=0;i<n;i++)
    {
        d=myInt();
        h=myInt();
        m=myInt();
        if(h==2) D1=d,D2=d,t1=m,t2=m+1;
        if(i==0&&h==1) D1=d,t1=m;
        if(i==1&&h==1) D2=d,t2=m;
    }
    if(t1<t2) swap(t1,t2),swap(D1,D2);
    double tmp1=(360-D1)/360.0*t1;
    double tmp2=(360-D2)/360.0*t2;
    if(tmp1>tmp2) swap(t1,t2),swap(tmp1,tmp2);
    return tmp1+t1<=tmp2;
}


int main()
{
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("ans","w",stdout);
    int T=myInt();
    int num=0;
    while(T--)
    {
        printf("Case #%d: %d\n",++num,cal());
    }
    return 0;
}
