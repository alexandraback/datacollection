
//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pf(a) printf("%d\n",a)
#define pf2(a,b) printf("%d %d\n",a,b)
#define pfcs(cs,a) printf("Case %d: %d\n",cs,a)
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX 1000000
#define INF 1<<29
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
int n,m;
int a[105][105],MaxRow[105],MaxCol[105];
bool check()
{

      int i,j;
      rep(i,n)
        rep(j,m)  if(a[i][j]<MaxRow[i] && a[i][j]<MaxCol[j]) return false;
        return true;

}
int main()
{

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int cs,T,i,j,mx;
    sc(T);
    FOR(cs,1,T)
    {      bool flag=false;
           cin>>n>>m;
           rep(i,n) rep(j,m) cin>>a[i][j];
           rep(i,n)
           {  mx=a[i][0];
              rep(j,m) mx=max(mx,a[i][j]);
              MaxRow[i]=mx;

           }
           rep(i,m)
           {
                  mx=a[0][i];
                  rep(j,n) mx=max(mx,a[j][i]);
                  MaxCol[i]=mx;
           }
           if(check())
           {
                  printf("Case #%d: YES\n",cs);
           }
           else printf("Case #%d: NO\n",cs);

    }


}
