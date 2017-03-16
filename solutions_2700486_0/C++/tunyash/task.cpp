#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int INF = 1000000000;
const int prime = 9241;
const ld pi = acos(-1.);

int lev[2005];
int lsum[2005];
ld dp[2005][2005];
void solve(int test)
{
   int n, x, y;
   cin >> n >> x >> y;
   lev[0] = 1;
   for (int i = 1; i < 2005; i++) lev[i] = lev[i-1] + 4;
   lsum[0] = lev[0];
   for (int i = 1; i < 2005; i++) lsum[i] = lsum[i-1] + lev[i];
   int last = 0;
   for (int i = 1; i < 2005; i++)
      if (lsum[i] > n) {last = i;  break;}
   assert(last > 0);
   
   int mylev = (abs(x) + y) / 2;
 //  cout << "last=" << last << endl;
 //  cout << "mylev=" << mylev << endl;
   if (mylev > last)
   {
      cout << "Case #" << test << ": " << 0 << endl;
      return;
   }
   if (mylev < last)
   {
      cout << "Case #" << test << ": " << 1 << endl;
      return;
   }
   int maxn = last * 2;
   for (int i = 0; i <= maxn; i++)
      for (int j = 0; j <= maxn; j++)
         dp[i][j] = 0.;
   dp[0][0] = 1.;

   for (int i = 0; i <= maxn; i++)
      for (int j = 0; j <= maxn; j++)
      {
       //  if (dp[i][j] < 1e-15) continue;
         //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
         if (i == maxn) dp[i][j+1] += dp[i][j];
         else if (j == maxn) dp[i+1][j] += dp[i][j];
         else
         {
            dp[i+1][j] += dp[i][j] * .5;
            dp[i][j+1] += dp[i][j] * .5;
         }
      }
   ld ans = 0.;
   for (int i = 0; i <= maxn; i++)
      for (int j = 0; j <= maxn; j++)
         if (i+j == n - lsum[last-1] && i > y) ans += dp[i][j];
   assert(ans < 1 + 1e-6);
   cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
   int t;
   cin >> t;
   cout.precision(15);
   for (int i = 1; i <= t; i++) solve(i);
}