#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int rev(int x) {
  int y = 0;
  while(x) {
    y *= 10;
    y += x % 10;
    x /= 10;
  }
  return y;
}

int vis[2000005];

int bfs(int val) {
  queue<pair<int, int> > Q;
  Q.push(make_pair(0, 0));
  vis[0] = 1;
  while(!Q.empty()) {
    pair<int, int> p = Q.front();
    Q.pop();
    if(p.first == val) return p.second;
    if(!vis[p.first+1]) { Q.push(make_pair(p.first+1, p.second+1)); vis[p.first+1] = 1; }
    if(!vis[rev(p.first)]) { Q.push(make_pair(rev(p.first), p.second+1)); vis[rev(p.first)] = 1; }
  }
  return -1;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    int x;
    scanf("%d", &x);
    memset(vis, 0, sizeof(vis));
    printf("Case #%d: %d\n", t, bfs(x));
  }
  return 0;
}
  