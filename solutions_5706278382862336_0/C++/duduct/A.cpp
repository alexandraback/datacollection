#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <ctime>
#include <deque>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#include <utility>

typedef long long i64;
typedef unsigned int u32;
typedef double lf;
typedef float ft;

#define ss second
#define ff first
#define xoa erase
#define chen insert
#define ii pair <int, int>
#define ll pair <long long , long long>
#define mp make_pair
#define fIn(file) freopen(file".inp","r",stdin);
#define fOut(file) freopen(file".out","w",stdout);
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pow2(x) (x*x)

#define MAXL LLONG_MAX
#define MINL LLONG_MIN
#define inf 1000111222
#define eps 1e-6

int times;
static const unsigned Mod37BitPosition[] = // map a bit value mod 37 to its position
{
    -1, 0, 1, 26, 2, 23, 27, 0, 3, 16, 24, 30, 28, 11, 0, 13, 4,
    7, 17, 0, 25, 22, 31, 15, 29, 10, 12, 6, 0, 21, 14, 9, 5,
    20, 8, 19, 18
};

i64 ctz(i64 n) {
    return Mod37BitPosition[(-n & n) % 37];
}

i64 gcd( i64 x, i64 y )
{
    if(x==y) return x;
    if(x==0) return y;
    if(y==0) return x;
    i64 cf2=ctz(x|y);
    x>>=ctz(x);
    for(;;)
    {
        y>>=ctz(y);
        if(x==y)
            break;
        if(x>y)
            std::swap(x,y);
        if(x==1)
            break;
        y-=x;
    }
    return x<<cf2;
}

using namespace std;

long long revN(long long a)
{
    long long b=0;
    while(a)
    {
        b=b*10+a%10;
        a/=10;
    }
    return b;
}

bool checkPalin(long long a)
{
    long long n=a;
    long long m=revN(a);
    while(n)
    {
        if(n%10!=m%10)
            return false;
        n/=10;m/=10;
    }
    return true;
}

bool checkSqr(long long a)
{
    long long t = sqrt(a);
    return (t*t==a);
}

bool isApproximateEqual(double x, double y)
{
    if( -eps <= (x-y) && (x-y) <= eps ) return true;
    if((-eps<=x && x<=eps )||( -eps <=y && y <=eps )) return false;
    return ((-eps <=(x-y)/x && (x-y)/x <= eps)||
            (-eps <=(x-y)/y && (x-y)/y <= eps));
}

#define mxN

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
long long p,q;
long long kq;

bool kiemTra(long long q)
{
    while(q%2==0)
        q/=2;
    if(q>1) return false;
    else return true;
}

int main ()
{
    #ifndef ONLINE_JUDGE
    fIn("A"); fOut("A");
    times=clock();
    #endif // ONLINE_JUDGE
    int t; cin>>t;
    for (int o=1; o<=t; o++)
    {
        printf("Case #%d: ",o);
        scanf("%lld/%lld",&p,&q);
        long long tmp=gcd(p,q);
        p/=tmp;
        q/=tmp;
        int lf, rg; lf=1, rg=40;
        if (kiemTra(q)==false)
        {
            puts("impossible");
            continue;
        }
        while(lf<=rg)
        {
            long long mid=(lf+rg)/2ll;
            long long chia=1LL<<mid;
            long long tmp=q/chia;
            if(tmp<=p)
            {
                kq=mid;
                rg=mid-1;
            }
            else lf=mid+1;
        }
        cout<<kq<<endl;
    }
    return 0;
}
