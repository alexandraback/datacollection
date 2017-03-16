#include<bits/stdc++.h>

#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)

#define MP           make_pair
#define PB           push_back
#define REP(i, n)    for(int i = 0; i < n; i++)
#define INC(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)
#define CLEAR(a)     memset(a, 0, sizeof a)

using namespace std;

typedef long long          LL;
typedef unsigned long long ULL;
typedef vector<int>        VI;
typedef pair<int, int>     II;
typedef vector<II>         VII;

int dp[1000006];
inline int rev(int num)
{
      int ans = 0;
      while(num)
      {
            int d = num%10;
            ans = ans*10+d;
            num/=10;
      }
      return ans;
}
void precomp()
{
      INC(i,1,1000000)
            dp[i] = 1e9;
      dp[1] = 1;
      INC(i,2,1000000)
      {
            dp[i] = dp[i-1] + 1;
            if(rev(rev(i))==i)
                  dp[i] = min(dp[i],dp[rev(i)]+1);
      }
}
int main()
{
      int t;
      CLEAR(dp);
      precomp();
      s(t);
      REP(tt,t)
      {
            int n;
            s(n);
            printf("Case #%d: %d\n",tt+1,dp[n]);
      }
      return 0;
}
