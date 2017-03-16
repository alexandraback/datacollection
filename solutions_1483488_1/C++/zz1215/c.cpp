#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<cassert>
#include<cstring>
#include<iomanip>
using namespace std;

#ifdef _WIN32
#define i64 __int64
#define out64 "%I64d\n"
#define in64 "%I64d"
#else
#define i64 long long
#define out64 "%lld\n"
#define in64 "%lld"
#endif

#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)
#define FF(i,a)         for( int i = 0 ; i < (a) ; i ++)
#define FFD(i,a)        for( int i = (a)-1 ; i >= 0 ; i --)
#define S64(a)          scanf(in64,&a)
#define SS(a)           scanf("%d",&a)
#define LL(a)           ((a)<<1)
#define RR(a)           (((a)<<1)+1)
#define SZ(a)           ((int)a.size())
#define PP(n,m,a)       puts("---");FF(i,n){FF(j,m)cout << a[i][j] << ' ';puts("");}
#define pb              push_back
#define CL(Q)           while(!Q.empty())Q.pop()
#define MM(name,what)   memset(name,what,sizeof(name))
#define read            freopen("C-small-attempt0.in","r",stdin)
#define write           freopen("out.txt","w",stdout)

const int inf = 0x3f3f3f3f;
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const double oo = 10e9;
const double eps = 10e-10;
const double pi = acos(-1.0);

i64 gcd(i64 _a, i64 _b)
{
    if (!_a || !_b)
    {
        return max(_a, _b);
    }
    i64 _t;
    while (_t = _a % _b)
    {
        _a = _b;
        _b = _t;
    }
    return _b;
};

i64 ext_gcd (i64 _a, i64 _b, i64 &_x, i64 &_y)
{
    if (!_b)
    {
        _x = 1;
        _y = 0;
        return _a;
    }
    i64 _d = ext_gcd (_b, _a % _b, _x, _y);
    i64 _t = _x;
    _x = _y;
    _y = _t - _a / _b * _y;
    return _d;
}

i64 invmod (i64 _a, i64 _p)
{
    i64 _ans, _y;
    ext_gcd (_a, _p, _ans, _y);
    _ans < 0 ? _ans += _p : 0;
    return _ans;
}

int a,b;
int T;
int len;
int xx[9];
int hash[2222222];

inline int ex(int x)
{
    int re;
    int temp = x;
    int ans=0;

    for(int i=1;i<len;i++)
    {
        re = temp%10;
        re *= xx[len-1];
        temp /= 10;
        temp += re;
        if(temp > b)
        {
            continue;
        }
        if(hash[temp] == x)
        {
            continue;
        }
        hash[temp] = x;
        if(x < temp )
        {
            ans++;
        }
    }
    return ans;
}

int start()
{
    int ans = 0;
    for(int i=a;i<=b;i++)
    {
        ans += ex(i);
    }
    return ans;
}

void init()
{
    xx[0]=1;
    xx[1]=10;
    xx[2]=100;
    xx[3]=1000;
    xx[4]=10000;
    xx[5]=100000;
    xx[6]=1000000;
    xx[7]=10000000;
    xx[8]=100000000;
    return ;
}

int main()
{
    freopen("C-large.in","r",stdin);
    write;
    init();
    cin>>T;
    for(int tt=1;tt<=T;tt++)
    {
        cin>>a>>b;
        MM(hash,0);
        int temp = b;
        len = 0;
        while(temp>0)
        {
            len++;
            temp /= 10;
        }
        cout<<"Case #"<<tt<<": ";
        cout<<start()<<endl;
    }
    return 0;
}



