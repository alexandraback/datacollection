#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct node {
  string state;
  int num, cnt;
};

int require[20][2];
map <string, bool> hash;
queue <node> qq;

bool check(node &c,int n) {
  for(int i = 1; i <= n; ++i)
    for(int i = 1; i <= n; ++i)
      if(c.state[i] != '2')
        return false;
  return true;
}

void change(node & cur,int level,int sinc,int ns) {
  node next = cur;
  next.state[level] = ns + '0';
  next.num += sinc;
  next.cnt++;
  if(hash.find(next.state) != hash.end())
    return;
  hash[next.state] = true;
  qq.push(next);
}

int work(int n) {
  node cur;
  while(!qq.empty())
    qq.pop();
  hash.clear();
  cur.state.clear();
  for(int i = 0;i <= n;++i)
    cur.state += '0';
  cur.num = 0;
  cur.cnt = 0;
  qq.push(cur);
  while(!qq.empty()) {
    cur = qq.front();
    qq.pop();
    if(check(cur,n))
      return cur.cnt;
    for(int i = 1; i <= n; ++i) {
      if(cur.state[i] == '2')
        continue;
      if(cur.state[i] == '0' && cur.num >= require[i][0])
        change(cur, i, 1, 1);
      if(cur.state[i] == '0' && cur.num >= require[i][1])
        change(cur, i, 2, 2);
      if(cur.state[i] == '1' && cur.num >= require[i][1])
        change(cur, i, 1, 2);
    }
  }
  return -1;
}

int main() {
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int T, cass, i, n, ans;
  scanf("%d", &T);
  for(cass = 1; cass <= T; ++cass) {
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
      scanf("%d %d", &require[i][0], &require[i][1]);
    ans = work(n);
    if(ans == -1)
      printf("Case #%d: Too Bad\n",cass);
    else
      printf("Case #%d: %d\n",cass,ans);
  }
}
