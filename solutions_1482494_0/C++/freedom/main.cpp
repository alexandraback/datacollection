#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
struct Node {
  string state;
  int starnum,cnt;
};
int require[11][2];
queue<Node> open;
map<string,bool> hash;
bool check(Node & c,int n) {
  for(int i = 1;i <= n;++i)
    if(c.state[i] != '2') return false;
  return true;
}
void expand(Node & cur,int level,int sinc,int ns) {
  Node next = cur;
  next.state[level] = ns + '0';
  next.starnum += sinc;
  next.cnt++;
  if(hash.find(next.state) != hash.end()) return;
  hash[next.state] = true;
  open.push(next);
}
int Solve(int n) {
  Node cur;
  while(!open.empty()) open.pop();
  hash.clear();
  cur.state.clear();
  for(int i = 0;i <= n;++i)
    cur.state += '0';
  cur.starnum = 0;cur.cnt = 0;
  open.push(cur);
  while(!open.empty()) {
    cur = open.front();
    open.pop();
    if(check(cur,n)) return cur.cnt;
    for(int i = 1;i <= n;++i) {
      if(cur.state[i] == '2') continue;
      if(cur.state[i] == '0' && cur.starnum >= require[i][0]) {
        expand(cur,i,1,1);
      }
      if(cur.state[i] == '0' && cur.starnum >= require[i][1]) {
        expand(cur,i,2,2);
      }
      if(cur.state[i] == '1' && cur.starnum >= require[i][1]) {
        expand(cur,i,1,2);
      }
    }
  }
  return -1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int tt,cas,i,n,ans;
    scanf("%d",&tt);
    for(cas = 1;cas <= tt;++cas) {
      scanf("%d",&n);
      for(i = 1;i <= n;++i)
        scanf("%d %d",&require[i][0],&require[i][1]);
      ans = Solve(n);
      if(ans == -1) printf("Case #%d: Too Bad\n",cas);
      else printf("Case #%d: %d\n",cas,ans);
    }
}
