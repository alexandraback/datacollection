//humanity is a very illusive quality

/*
Name:
OJ:
Link:
Algorithm:
Type:
Difficulty:
Interest:
Additional:
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

const int    inf = (1<<28);
const double pi  = (2.0*acos(0.0));
const double eps = 1e-9;

//typedef long long           lli;
//typedef __int64             lli;
//typedef unsigned long long  llu;
//typedef unsigned __int64    llu;
//typedef pair < int , int >  pii;
//typedef vector < int >      vi;
//typedef vector < string >   vs;

#define isp2( a ) (!(a & (a-1)))
#define CLR( a )  memset(a , 0  , sizeof (a))
#define SET( a , b)  memset(a , b , sizeof (a))
#define SZ( a )   ((int)a.size())
#define all( a )  a.begin(),a.end()


//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x )  for( i = ( a ) ; i <= ( b ) ; i += x )
#define rep( i, n )        _rep( i, 0, n - 1, 1 )
#define _rrep( i, a, b, x ) for( i = (a) ; i >= (b) ; i -= x )
#define rrep( i, a, b)     _rrep( i, a, b, 1)
#define xrep( i, a, b)     _rep( i, a, b, 1)

#define SD( a ) scanf("%d",&a)
#define SL( a ) scanf("%lld",&a)
#define SI( a ) scanf("%I64d",&a)
#define SS( a ) scanf("%s",a)
#define SF( a ) scanf("%lf",&a);

#define pb push_back
#define ff first
#define ss second
int n , a[25];
map < int , bool > mp;
int main(void)
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k,kase=0;
    int t;SD(t);
    while(t--)
    {
        printf("Case #%d:\n",++kase);
        SD(n);mp.clear();
        rep(i,n) SD(a[i]);
        int range = (1<<n);
        bool valid = false;
        int sm;
        rep(i,range)
        {
            sm=0;
            rep(j,n)
                if(i & (1<<j))
                    sm+=a[j];
            if(mp.find(sm)!=mp.end())
            {valid=true;break;}
            mp[sm]=true;
        }
        int X = sm;
        if(!valid)
        {
            printf("Impossible\n");
            continue;
        }
        int cnt =0;
        rep(i,range)
        {
            sm=0;
            queue<int> Q;
            rep(j,n)
                if(i & (1<<j))
                    Q.push(a[j]),sm+=a[j];
            if(sm == X)
            {
                cnt++;
                printf("%d",Q.front());
                Q.pop();
                while(!Q.empty())
                    printf(" %d",Q.front()) , Q.pop();
                printf("\n");
            }
            if(cnt==2)break;
        }
    }
    return 0;
}
