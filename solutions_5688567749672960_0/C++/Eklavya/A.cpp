#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cassert>
using  namespace  std;

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;


//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

#define PI acos(-1.0)
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define FORR(i, b, e) for(int i = b; i >= e; i--)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define MAX 10000007
#define EPS 1e-9
int dp[1000005];
int rev[1000005];
int mul[10];
int fun(int n)
{
   int number=n, reverse = 0;
   for( ; number!= 0 ; )
   {
      reverse = reverse * 10;
      reverse = reverse + number%10;
      number = number/10;
   }
   return reverse;
}
int N;
int  solve(int n)
{
    //pr(n);
    if(n==N)return 0;
    if(dp[n]!=-1)return dp[n];
    int ans=10000000;
    if(rev[n]>n&&rev[n]<=N)
        ans=1+solve(rev[n]);
    ans=min(ans,1+solve(n+1));
    return dp[n]=ans;
}
int main()
{
    READ("A-small-attempt0.in");
    WRITE("out.out");
    int T;
    mul[0]=1;
    FOR(i,1,6)
    {
        mul[i]=mul[i-1]*10;
    }
    FOR(i,1,1000000)
    {
        rev[i]=fun(i);
    }
    scanf("%d",&T);

    FOR(t,1,T)
    {
        scanf("%d",&N);
        mem(dp,-1);
        int res=solve(1);
        printf("Case #%d: %d\n",t,res+1);
    }
    return 0;
}


