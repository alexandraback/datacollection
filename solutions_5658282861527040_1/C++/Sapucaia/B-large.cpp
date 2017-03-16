#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

#define rep0(i,n) for(int i = 0;i < (int)n;i++)
#define rep1(i,n) for(int i = 1;i <= (int)n;i++)
#define per0(i,n) for(int i = (int)n-1;i >= 0;i--)
#define per1(i,n) for(int i = (int)n ;i >= 1;i--)

#define pb push_back
#define fill(d,v) memset(d,v,sizeof(d))

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;

//     b  sA sB sK
ll dp[33][2][2][2];
int A[33],B[33],K[33];

ll calc(int b,bool sA,bool sB,bool sK)
{
  if(b == -1)
    return 1;
  ll & ans = dp[b][sA][sB][sK];
  if(ans != -1)
    return ans;
  bool sA0,sA1,sB0,sB1,sK0,sK1;
  //newflags
  if(sA == 1 && A[b] == 0)
    sA0=1;
  else
    sA0=0;

  if(sA == 1 && A[b] == 1)
    sA1=1;
  else
    sA1=0;
  //---------------
  if(sB == 1 && B[b] == 0)
    sB0=1;
  else
    sB0=0;

  if(sB == 1 && B[b] == 1)
    sB1=1;
  else
    sB1=0;

  //---------------
  if(sK == 1 && K[b] == 0)
    sK0=1;
  else
    sK0=0;

  if(sK == 1 && K[b] == 1)
    sK1=1;
  else
    sK1=0;

  ans = 0;
  //00
  ans += calc(b-1,sA0,sB0,sK0);
  //01
  if(sB == 0 || B[b] == 1)
    {
      ans += calc(b-1,sA0,sB1,sK0);
    }
  //10
   if(sA == 0 || A[b] == 1)
    {
      ans += calc(b-1,sA1,sB0,sK0);
    }
  //11
   if((sA == 0 || A[b] == 1) && (sB == 0 || B[b] == 1) && (sK == 0 || K[b] == 1))
    {
      ans += calc(b-1,sA1,sB1,sK1);
    }
   return ans;
}
int main()
{
  cin.sync_with_stdio(false);
  int T_;
  cin >> T_;
  for(int t_ = 1; t_ <= T_;t_++)
    {
      int dA,dB,dK;
      cin >> dA >> dB >> dK;
      dA--,dB--,dK--;
      for(int i = 0; i <= 32;i++)
	{
	  A[i] = B[i] = K[i] = 0;
	  if(dA&1)
	    A[i] = 1;
	  if(dB&1)
	    B[i] = 1;
	  if(dK&1)
	    K[i] = 1;
	  dA >>= 1;
	  dB >>= 1;
	  dK >>= 1;
	}
      fill(dp,-1);
      cout << "Case #" << t_ << ": ";
      cout << calc(32,1,1,1);
      cout << "\n";
    }
  return 0;
}
