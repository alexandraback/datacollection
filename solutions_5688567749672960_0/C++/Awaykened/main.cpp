#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
unordered_map<long long,int> dp;
long long n;
queue<long long > q;
long long flip(long long num) {
      long long ret = 0;
      while (num) {
            int c = num%10;
            ret = ret*10+c;
            num /= 10;

      }
      return ret;
}
int t;
int main() {
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
      scanf("%d",&t);
      for (int test = 1;test<=t;test++) {
            scanf("%lld",&n);
            dp.clear();
            while (!q.empty()) q.pop();
            q.push(1);
            dp[1] = 1;
            if (dp.count(n))
                  printf("Case #%d: %d\n",test,dp[n]);
            else {
                  while (!q.empty()) {
                        long long u = q.front();
                        q.pop();
                        if (u == n) {printf("Case #%d: %d\n",test,dp[u]);break;}
                        if (!dp.count(u+1)) {
                              dp[u+1] = dp[u] + 1;
                              q.push(u+1);
                        }
                        long long v = flip(u);
                        if (!dp.count(v)) {
                              dp[v] = dp[u] + 1;
                              q.push(v);
                        }
                  }
            }
      }
}