#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct node
{
  string zhuangtai;
  int countt, cnt;
};

int laa[20][2];
map <string, bool>hash;
queue <node>q;

bool check(node &c,int n)
{
  for(int i=1;i<=n;++i)
  {
    for(int i=1;i<=n;++i)
    {
      if(c.zhuangtai[i]!='2')
        return false;
    }
  }
  return true;
}

void change(node & cur,int level,int sinc,int ns)
{
  node next=cur;
  next.zhuangtai[level]=ns+'0';
  next.countt+=sinc;
  next.cnt++;
  if(hash.find(next.zhuangtai)!=hash.end())
    return;
  hash[next.zhuangtai]=true;
  q.push(next);
}

int work(int n)
{
  node cur;
  while(!q.empty())
    q.pop();
  hash.clear();
  cur.zhuangtai.clear();
  for(int i=0;i<=n;++i)
    cur.zhuangtai+='0';
  cur.countt=0;
  cur.cnt=0;
  q.push(cur);
  while(!q.empty())
  {
    cur=q.front();
    q.pop();
    if(check(cur,n))
      return cur.cnt;
    for(int i=1;i<=n;++i)
    {
      if(cur.zhuangtai[i]=='2')
        continue;
      if(cur.zhuangtai[i]=='0'&&cur.countt>=laa[i][0])
        change(cur,i,1,1);
      if(cur.zhuangtai[i]=='0'&&cur.countt>=laa[i][1])
        change(cur,i,2,2);
      if(cur.zhuangtai[i]=='1'&&cur.countt>=laa[i][1])
        change(cur,i,1,2);
    }
  }
  return -1;
}

int main() {
  freopen("B-small-attempt1.in", "r", stdin);
  freopen("out.txt", "w", stdout);
  int cases,cass,i,n,ans;
  scanf("%d",&cases);
  for(cass=1;cass<=cases;++cass)
  {
    scanf("%d",&n);
    for(i=1;i<=n;++i)
      scanf("%d%d",&laa[i][0],&laa[i][1]);
    ans=work(n);
    if(ans==-1)
      printf("Case #%d: Too Bad\n",cass);
    else
      printf("Case #%d: %d\n",cass,ans);
  }
}
