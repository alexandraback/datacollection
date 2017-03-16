#pragma comment(linker, "/stack:640000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI=acos(-1.0);

#define    READ(f) 	         freopen(f, "r", stdin)
#define    WRITE(f)   	     freopen(f, "w", stdout)
#define    MP(x, y) 	     make_pair(x, y)
#define    PB(x)             push_back(x)
#define    rep(i,n)          for(int i = 1 ; i<=(n) ; i++)
#define    repI(i,n)         for(int i = 0 ; i<(n) ; i++)
#define    FOR(i,L,R) 	     for (int i = L; i <= R; i++)
#define    ROF(i,L,R) 	     for (int i = L; i >= R; i--)
#define    FOREACH(i,t)      for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define    ALL(p) 	         p.begin(),p.end()
#define    ALLR(p) 	         p.rbegin(),p.rend()
#define    SET(p) 	         memset(p, -1, sizeof(p))
#define    CLR(p)            memset(p, 0, sizeof(p))
#define    MEM(p, v)         memset(p, v, sizeof(p))
#define    getI(a) 	         scanf("%d", &a)
#define    getII(a,b) 	     scanf("%d%d", &a, &b)
#define    getIII(a,b,c)     scanf("%d%d%d", &a, &b, &c)
#define    getL(a)           scanf("%lld",&a)
#define    getLL(a,b)        scanf("%lld%lld",&a,&b)
#define    getLLL(a,b,c)     scanf("%lld%lld%lld",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define    bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define    bitOff(a,k)       (a&(~(1<<(k))))
#define    bitOn(a,k)         (a|(1<<(k)))
#define    iseq(a,b)          (fabs(a-b)<EPS)
#define    vi 	 vector < int >
#define    vii 	 vector < vector < int > >
#define    pii 	 pair< int, int >
#define    ff 	 first
#define    ss 	 second
#define    ll	 long long
#define    ull 	 unsigned long long

template< class T > inline T _abs(T n)
{
    return ((n) < 0 ? -(n) : (n));
}
template< class T > inline T _max(T a, T b)
{
    return (!((a)<(b))?(a):(b));
}
template< class T > inline T _min(T a, T b)
{
    return (((a)<(b))?(a):(b));
}
template< class T > inline T _swap(T &a, T &b)
{
    a=a^b;
    b=a^b;
    a=a^b;
}
template< class T > inline T gcd(T a, T b)
{
    return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template< class T > inline T lcm(T a, T b)
{
    return ((a) / gcd((a), (b)) * (b));
}
template <typename T> string NumberToString ( T Number )
{
    ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef mamun
#define debug(args...) {cerr<<"*: "; dbg,args; cerr<<endl;}
#else
#define debug(args...)  // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator, (const T& v)
    {
        cerr<<v<<" ";
        return *this;
    }
} dbg;
///****************** template ends here ****************
int t,n,m;
string a,b;
int dif,ans1,ans2;
string x,y;
void call(int pos,int val1,int val2,string tmp1,string tmp2)
{
//    debug(val1,val2,tmp1,tmp2)
    if(pos==n)
    {
        if(abs(val1-val2)<dif)
        {
            ans1=val1;
            ans2=val2;
            dif=abs(val1-val2);
            x=tmp1;
            y=tmp2;
            return;
        }
        else if(abs(val1-val2)==dif)
        {
            if(val1<ans1)
            {
                ans1=val1;
                ans2=val2;
                x=tmp1;
                y=tmp2;
            }
            else if(val1==ans1)
            {
                if(val2<=ans2)
                {
                    ans2=val2;
                    y=tmp2;

                }

            }
        }
        return;
    }
    if(a[pos]=='?')
    {
        repI(i,10)
        {
            if(b[pos]=='?')
            {
                repI(j,10)
                {
                    call(pos+1,val1*10+i,val2*10+j,tmp1+(char)(i+48),tmp2+(char)(j+48));
                }
            }
            else call(pos+1,val1*10+i,val2*10+b[pos]-'0',tmp1+(char)(i+48),tmp2+b[pos]);
        }
    }
    else
    {
        if(b[pos]=='?')
        {
            repI(j,10)
            {
                call(pos+1,val1*10+a[pos]-'0',val2*10+j,tmp1+a[pos],tmp2+(char)(j+48));
            }
        }
        else call(pos+1,val1*10+a[pos]-'0',val2*10+b[pos]-'0',tmp1+a[pos],tmp2+b[pos]);

    }
}

int main()
{
    ///check for 0 or -1 if input not specified
#ifdef mamun
    READ("in.txt");
        WRITE("out.txt");
#endif // mamun
    getI(t);
    rep(cs,t)
    {
        cin>>a>>b;
//        debug(a,b)
        printf("Case #%d: ",cs);
        dif=INF;
        ans1=INF;
        ans2=INF;
        n=a.size();
        x="";y="";
//        debug(dif)
        call(0,0,0,"","");
//        debug(ans1,ans2)
        cout<<x<<" "<<y<<endl;
    }



    return 0;
}

