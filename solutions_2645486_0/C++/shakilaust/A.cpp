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
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()


using namespace std;


template< class T > T gcd(T a, T b)
{
    return (b != 0 ? gcd<T>(b, a%b) : a);
}
template< class T > T lcm(T a, T b)
{
    return (a / gcd<T>(a, b) * b);
}
int dp[20][200],val[20],n,k,e;
int DP(int idx,int eng)
{
       if(idx==n) return 0;
       if(dp[idx][eng]!=-1) return dp[idx][eng];
       int i;
       int limit=min(eng,e);
       int ans=-1;
       for(i=0;i<=limit;i++)
       {
              int ret=(i*(val[idx]))+DP(idx+1,(limit-i)+k);
              ans=max(ans,ret);
       }
       return dp[idx][eng]=ans;
}

int main()
{

   // freopen("in.txt", "r", stdin);
   // freopen("out.txt","w",stdout);
              int cs,T;
              sc(T);
              rep(cs,T)
              {      int i;
                     cin>>e>>k>>n;
                     rep(i,n) cin>>val[i];
                    // rep(i,n) printf("%d %d\n",i,val[i]);
                     memo(dp,-1);
                     printf("Case #%d: %d\n",cs+1,DP(0,e));
              }

}
