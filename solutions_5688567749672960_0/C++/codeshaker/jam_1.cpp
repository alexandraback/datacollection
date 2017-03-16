/*
   nitesh kumar ( codeshaker )
*/

/**********START HERE ************/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <climits>
#include <complex>
typedef long long ll;
using namespace std;

#define pb push_back
#define nl puts ("")
#define ff first
#define ss second
#define mp make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef  vector<int> vi;
typedef  vector<ll> vl;
typedef  vector<string> vs;
typedef  pair<int,int> pii;
typedef  pair<pii,int> ppi;
typedef  vector<pii> vpii;

#define mx7   10000007
#define mx6   1000006
#define mx5   100005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   ll(1e9+7)

/********** END HERE ***********/

int dp[mx6];

int main(void)
{
    #ifndef ONLINE_JUDGE
  //  freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
    #endif
         ios::sync_with_stdio(false);
         int tc,num,r,n;
         scanf("%d",&tc);
         int c=0;

         FOR(i,10,1000000)
         dp[i]=inf;
         FOR(i,1,9)
         dp[i]=i;

         FOR(i,10,1000000)
         {
             dp[i]=MIN(dp[i],dp[i-1]+1);
             num=i;
             r=0;
             while(num)
             {
                 r=r*10+(num%10);
                 num/=10;
             }
             if(r<=1000000)
                dp[r]=MIN(dp[r],dp[i]+1);
         }
          //FOR(i,10,20)
         // cout<<dp[i]<<endl;
         while(tc--)
         {
             c++;
             scanf("%d,",&n);
             printf("Case #%d: %d\n",c,dp[n]);
         }


           return 0;
}

