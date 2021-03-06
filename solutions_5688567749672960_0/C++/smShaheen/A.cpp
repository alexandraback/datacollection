///==========================================================================
///
///                   Bismillah ir-Rahman ir-Rahim
///
/// ==========================================================================
///
///                    S.M.SHAHEEN SHA
///
///                    Dept. of Computer Science and Engineering
///                    Jahangirnagar University , Bangladesh
///
///                    Email : shaheen.cse20@gmail.com
///                    ID    : shaheen_bd
/// ==========================================================================

//#include<bits/stdc++.h>

#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

using namespace std;

#define LL long long
#define ULL unsigned long long

// I/O
#define I(X)                        scanf("%d", &(X))
#define II(X, Y)                    scanf("%d%d", &(X), &(Y))
#define III(X, Y, Z)                scanf("%d%d%d", &(X), &(Y), &(Z))

#define DI(X) int (X);              scanf("%d", &X)
#define DII(X, Y) int X, Y;         scanf("%d%d", &X, &Y)
#define DIII(X, Y, Z) int X, Y, Z;  scanf("%d%d%d", &X, &Y, &Z)

#define IL(X)                       scanf("%lld", &(X))
#define IIL(X,Y )                   scanf("%lld", &(X),&Y)
#define IIIL(X,Y,Z)                 scanf("%lld", &(X),&Y,&Z)

#define DIL(X)       LL X;          scanf("%lld", &(X))
#define DIIL(X,Y)    LL X,Y;        scanf("%lld", &(X),&Y)
#define DIIIL(X,Y,Z) LL X,Y,Z;      scanf("%lld", &(X),&Y,&Z)

#define SS(s) scanf("%s",s)

// LOOP
#define repv(i,a) for(int i=0;i<(int)a.size();i++)
#define revv(i,a) for(int i=((int)a.size())-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;

// array initialization
#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)

// min-max
#define Max(a,b) (a>b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define Min(a,b) (a<b?a:b)
#define _Min(a,b,c) Min(a,Min(b,c))
#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))

#define SQR(n) (n*n)
#define eps (1e-9)
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)

#define all(a) a.begin(),a.end()
#define pb push_back

#define NL printf("\n");
// pair
#define X first
#define Y second

// binary search
#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())

// segment tree
#define LEFT (idx<<1)
#define RIGHT (LEFT+1)

// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define _cin  ios_base::sync_with_stdio(0); cin.tie(0);

// BIT operation
#define countbit(x) __builtin_popcount(x)

#define pline cout << "_________________________" << endl;

// bit operation
template< class T, class X > inline bool checkbit(T a, X i) { T t=1; return ((a&(t<<i))>0); }
template< class T, class X > inline T      setbit(T a, X i) { T t=1;return (a|(t<<i));      }
template< class T, class X > inline T    resetbit(T a, X i) { T t=1;return (a&(~(t<<i)));   }
template< class T, class X > inline T   togglebit(T a, X i) { T t=1;return (a^(t<<i));      }

// mathematics
template<typename T> T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T> T Bigmod(T base,T power,T mod) { T ret=1; while(power)  { if(power & 1) ret=(ret*base)%mod; base=(base*base)%mod;  power>>=1; }return ret; }
template<typename T> T ModInverse(T number,T mod) { return Bigmod(number,mod-2,mod); }
template<typename T> T GCD(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T> T LCM(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<typename T> T EUCLIDE(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T> T ABS(T a) {if(a<0)return -a;else return a;}

// geometry
double DEG(double x) { return (180.0*x)/(PI);}
double RAD(double x) { return (x*(double)PI)/(180.0);}
template<typename T> T DIS(T x1,T y1,T x2, T y2){return sqrt( (double)( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) );}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2){ return atan( double(y1-y2) / double(x1-x2));}
template<typename T> LL isLeft(T a,T b,T c) { return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y); }

// minmax
template<class T> inline bool setmin(T& a, T b) { return a>b? a=b, true: false; }
template<class T> inline bool setmax(T& a, T b) { return a<b? a=b, true: false; }

// debug
void P_ARR(int *ar,int a,int b) {  if(a>b) swap(a,b); if(a<=b) cout << ar[a]; for(int i=a+1;i<=b;i++) cout << " "<<ar[i];  cout << endl; }

template<typename T> T in(){ char ch; T n = 0; bool ng = false; while (1) { ch = getchar(); if (ch == '-') { ng = true; ch = getchar(); break;} if (ch>='0' && ch<='9') break; }    while (1) { n = n*10 + (ch - '0'); ch = getchar(); if (ch<'0' || ch>'9')   break;    }  return (ng?-n:n);  }

#define VI  vector< int >
#define VII vector< VI >
#define VLL vector< LL >
#define PII pair< int , int >
#define PLL pair< LL , LL >
#define VPI vector< PII >

//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; ///month
// dir[][0] = x value, dir[][1] = y value
//int dir[5][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1} }; /// 4 Direction
//int dir[9][2] = { {0,0},{1,0},{0,1},{-1,0},{0,-1},{-1,1},{-1,-1},{1,-1},{1,1}}; /// 8 direction
//int dir[9][2] = { {0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} }///Knight Direction
//int dir[8][2] = { {0,0},{2,0},{1,1},{-1,1} ,{-2,0} , {-1,-1} ,{1,-1} };///Hexagonal Direction

/// ======================================================================================================

///             0123456789
#define  MX     1000007
#define  MOD    1000000007
#define  inf    1000000000

LL dorev(LL n)
{
    LL m=0;
    while(n) {
        m=m*10LL+(n%10LL);
        n/=10LL;
    }
    return m;
}

LL cst[2*MX];


void BFS()
{
    queue< LL >q;

    q.push(1LL);
    cst[1] = 1LL;

    while( !q.empty() )
    {
        LL u = q.front();
        q.pop();

//        cout << u << " => " << endl;

        LL v = u+1;

        if( v>1  && v<MX && cst[v]==0  ) cst[v] = inf;

        if(v>1 && v<MX && cst[v]>cst[u]+1)
        {
            cst[v] = cst[u]+1;
            q.push(v);
        }

        v = dorev(u);

        if(u>v) continue;

        if(  v>1  && v<MX && cst[v]==0 ) cst[v] = inf;

        if(v>1 && v<MX && cst[v]>cst[u]+1)
        {
            cst[v] = cst[u]+1;
            q.push(v);
        }

    }

}

int main()
{
    //cout << dorev(10003) << endl;


    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    BFS();

    DI(tc);

    rep(cas,1,tc)
    {
        DIL(n);
        printf("Case #%d: %lld\n",cas,cst[n]);
    }

    return 0;
}
