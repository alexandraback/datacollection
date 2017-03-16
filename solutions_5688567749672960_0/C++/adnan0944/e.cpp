#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

using namespace std;


typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;



#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)

template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}


const int MX = 1e6 + 10 ;
bool vis[MX] ;
int rev( int x)
{
    vector < int > num ;
    while( x )
    {
        num.pb( x % 10 );
        x/=10;
    }
    reverse ( num.begin() , num.end() );
    int i ;
    int mul = 1 ;
    int cur = 0 ;
    rep( i , num.size() )
    {
        cur = cur + ( num[i] * mul );
        mul *= 10 ;
    }
    return cur ;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("outsmall_A.txt","w",stdout);


     int cs , t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         int n = II ;
         queue < pii > q ;
         rep( i ,  n + 1 ) vis[i] = 0 ;
         q.push( mp( 1 , 1 ) ) ;
         vis[1] = 1 ;
         int ans = 0 ;
         while( !q.empty() )
         {
             int now = q.front().ff ;
             int c = q.front().ss ;
             q.pop();
             if( now == n )
             {
                 ans = c  ;
                 break;
             }
             if( now  + 1 <= n && !vis[now + 1 ] )
             {
                 vis[now + 1] = 1 ;
                 q.push( mp ( now  + 1 ,c + 1 ));
             }
             int rv = rev( now );
             if( rv <= n && !vis[rv] )
             {
                 vis[rv] = 1 ;
                 q.push( mp ( rv , c + 1 ) );
             }
         }
         printf("Case #%d: %d\n",cs,ans);


     }


    return 0;
}
