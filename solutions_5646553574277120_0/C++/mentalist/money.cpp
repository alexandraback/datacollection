#include <stdio.h>
#include <queue>
#include <set>

using namespace std;

bool dp[33][50];

bool eval(int bit, int upper) {
  for(int i=1; i<=upper; ++i) dp[0][i] = false;
  dp[0][0] = true;
  for(int i=1; i<=30; ++i) {
    for(int w=0; w<=upper; ++w) {
      if((bit & (1<<(i-1))) && i <= w) dp[i][w] = (dp[i-1][w] || dp[i-1][w-i]);
      else dp[i][w] = dp[i-1][w];
    }
  }
  for(int w=1; w<=upper; ++w) {
    if(!dp[30][w])
      return false;
  }
  return true;
}

int bfs(int bit, int upper) {
  set<int> vis;
  queue<int> Q;
  Q.push(bit);
  vis.insert(bit);
  while(!Q.empty()) {
    bit = Q.front();
    Q.pop();
    if(eval(bit, upper)) return __builtin_popcount(bit);
    if(__builtin_popcount(bit) > 12) return -1;
    for(int i=0; i<30; ++i) {
      int nbit = bit;
      nbit |= (1<<i);
      if(vis.find(nbit) == vis.end()) {
        Q.push(nbit);
        vis.insert(nbit);
      }
    }
  }
  return -1;
}
  
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    int C, D, V, bit = 0;
    scanf("%d %d %d", &C, &D, &V);
    for(int i=0; i<D; ++i) {
      int val;
      scanf("%d", &val);
      bit |= (1<<(val-1));
    }
    printf("Case #%d: %d\n", t, bfs(bit, V) - D);
  }
  return 0;
}
    