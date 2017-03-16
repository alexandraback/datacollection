#import <iostream>
#import <sstream>
#import <algorithm>
#import <map>
#import <set>
#import <vector>
#import <queue>

#import <cstdio>
#import <cstdlib>
#import <cstring>
#import <cmath>
#import <cctype>

using namespace std;
typedef unsigned long long LL;
typedef vector<int> VI;
const int MAXN = 11;
int E,R,N;
int V[MAXN];

int dp[MAXN][MAXN];


int solve()
{
   memset(dp,0,sizeof(dp));

   for(int i = 0; i <= E; i++) {
      dp[0][E-i] = V[0] * i;
   }

   for(int i = 0; i < N-1; i++) {
      for(int energy = 0; energy <= E; energy++) {
         int next = i + 1;
         int gained = min(E,(energy + R));
         for(int j = 0; j <= gained; j++) {
            dp[next][gained-j] = max(dp[next][gained-j], V[next] * j + dp[i][energy]);
         }
      }
   }

   int ret = 0;
   for(int i = 0; i <= E; i++) ret = max(ret, dp[N-1][i]);
   return ret;
}
int main()
{
   freopen("B-small-attempt1.in","r",stdin);
   freopen("B-small.out","w",stdout);
   int T;
   cin>>T;
   for(int tc = 1; tc <= T; tc++) {
        cin>>E>>R>>N;
        for(int i = 0; i < N; i++) cin>>V[i];
        int ret = solve();
       cout<<"Case #"<<tc<<": "<<ret<<endl;
   }
   return 0;
}
