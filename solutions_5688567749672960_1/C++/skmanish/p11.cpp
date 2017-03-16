#include<bits/stdc++.h>

#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
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
LL POW10[17];
inline LL rev(LL num)
{
      LL ans = 0;
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
inline int digcount(LL num)
{
      int ret = 0;
      while(num)
            num/=10, ret++;
      return ret;
}
LL countTx(LL start,LL end1)
{
      int d = digcount(start);
      //if(d!=digcount(end1))
      //      printf("%lld %lld \n",start,end1);
      assert(d==digcount(end1));
      LL ret = end1-start;
      
      if(d==1) return end1-start;
      bool f = false;
      if(end1%10==0)
      {
            end1--;
            f = true;
      }
      INC(dend,1,d-1)
      {
            LL num1 = end1%POW10[dend]-1;
            LL num2 = rev(end1/POW10[dend]);
            LL curr = num1 + num2 + 1;
            ret = min(curr+f,ret);
      }
      return ret;
}
int main()
{
      int t;
      CLEAR(dp);
      precomp();
      POW10[0] = 1;
      INC(i,1,16)
            POW10[i] = POW10[i-1]*10;

      s(t);
      REP(tt,t)
      {
            LL n;
            sl(n);

            int d = 1;
            LL num = 1;
            LL ans = 1;
            LL temp;
            while(num<n)
            {
                  if(POW10[d]<=n)
                  {
                        temp = POW10[d]-1;
                        d++;
                  }
                  else 
                        temp = n;
                  //printf("num = %lld, temp = %lld\n",num,temp);
                  ans += countTx(num,temp);
                  num = temp;
                  if(num!=n)
                        num++, ans++;
                  //printf("num = %lld, ans = %lld\n",num,ans);
            }
            printf("Case #%d: %lld\n",tt+1,ans);
            //printf("Case #%d: %d\n",tt+1,dp[n]);
      }
      /*INC(i,2,1000000)
      {
            if(i%10==0 && dp[i]!=dp[i-1]+1)
            {
                  printf("%d\n",i);
                  break;
            }
      }*/
      return 0;
}
