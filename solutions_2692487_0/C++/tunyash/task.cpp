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

int dp[105][105];
int b[105];
void solve(int test)
{
   int a, n;
   cin >> a >> n;
   for (int i = 0; i < n; i++) cin >> b[i];
   sort(b, b + n);
   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
         dp[i][j] = -1;
   dp[0][0] = a;
   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
      {
       //  cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
         //perf operation
         dp[i][j+1] = max(dp[i][j+1], dp[i][j] + dp[i][j] - 1);
         //go without deleting
         if (dp[i][j] > b[i]) dp[i+1][j] = max(dp[i+1][j], dp[i][j] + b[i]);
         //delete next
         dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]); 
      } 
   int ans = 1e9;
   for (int i = 0; i <= n; i++)
     if (dp[n][i] > 0) {ans = i; break;}
   cout << "Case #" << test << ": " << ans << endl;  
}

int main()
{
   int t;
   cin >> t;
   for (int i = 1; i <= t; i++) solve(i);
}