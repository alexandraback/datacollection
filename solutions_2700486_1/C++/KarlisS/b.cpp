#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

static ll gcnt(ll lev)
{
  ll k = 2*lev -1;
  return (k*(k+1))/2;
}

  const int k2 = 2*1024;
long double tb[k2][k2];
long double dp[k2];
  
int main()
{
  int t;
  cin >> t;
  const int mxl = 50000;
  int dat[mxl];

  for(int i=0; i<k2; i++)
  {
    tb[i][0] = 1;
    tb[i][i] = 1;
    for(int j=1; j<i; j++)tb[i][j] = tb[i-1][j-1] + tb[i-1][j];
  }
  
  dp[0] =1;
  for(int i=1; i<k2; i++)dp[i] = dp[i-1]*2;
  for (int t1=1; t1<=t; t1++)
  { 
      double ans = 0;
      ll n,x,y;
      cin >> n >> x >> y;
      if (x < 0)x=-x;
      ll l = 0, r = mxl;
      ll lf=0;
      while(l < r)
      {
        ll m  = (l+r+1)/2;
        ll nk = gcnt(m);
        if (nk > n){
          r = m-1;
        }else{
          l = m;
        }
      }
      lf = l;
      ll levc =gcnt(lf);
      ll lp = (x+y)/2 + 1;
     // std::cerr << lf << " " << levc << " "<< lp << "\n";
      if (lp <= lf)
      {
        ans = 1;
      }
      else if(lp > lf + 1)
      {
        ans = 0;
      }
      else if(levc == n)
      {
        ans = 0;
      }
      else if(x == 0)
      {
        ans = 0;
      }
      else
      {
        ll bl = n - levc;
        ll h = 2*lf+1;
        int ch = y+1;
        if (bl < h)
        {
          if(ch > bl)
          {
            ans = 0;
          }
          else
          {
            ll sm = 0;
            for(int i=0; i<ch; i++)
            {
              sm += tb[bl][i];
            }
            long double v = 1;
            ans = v - (sm/dp[bl]);
           // cout << sm << " " << dp[bl] << " " << bl << "\n";
          }
        }
        else
        {
          ll minh  = bl - (h-1);
          if (ch <= minh)
          {
            ans = 1;
          }
          else
          {
            ll sm = 0;
            for(int i=0; i<ch; i++)
            {
              sm += tb[bl][i];
            }
            long double v = 1;
            ans = v - (sm/dp[bl]);
          }
        }
      }
      
      cout << "Case #" << t1 << ": ";
      cout.precision(10);
      cout << std::fixed;
      cout << ans;
      cout << "\n";
  }
  return 0;
}
