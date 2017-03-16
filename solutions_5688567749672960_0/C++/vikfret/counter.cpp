#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <queue>

#define MAXN 1000002
#define INF (1<<30)

using namespace std;

typedef vector<int> vi;

int main() {
   int T, N;
   scanf("%d", &T);
for(int kase = 1; kase <= T; kase++) {
   scanf("%d", &N);
   queue<int> q;
   vi d(MAXN,INF);
   q.push(1); d[1] = 1;
   while(!q.empty()) {
      int u = q.front(); q.pop();
      if(d[u+1] == INF) {
         d[u+1] = d[u] + 1;
         q.push(u+1);
      }
      int v;
      string rev = to_string(u);
      reverse(rev.begin(), rev.end());
      v = atoi(rev.c_str());
      if(d[v] == INF and v <= N) {
         d[v] = d[u] + 1;
         q.push(v);
      }
   }
   printf("Case #%d: %d\n", kase, d[N]);
}
   return 0;
}
