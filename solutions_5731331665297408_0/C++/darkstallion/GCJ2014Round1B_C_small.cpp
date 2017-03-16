//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI acos(-1)
#define eps 1e-9
using namespace std;

int n;
vector<int> edge[8];
string st[8];
stack<int> stk;
bool udah[8];

string dfs(int i, int mode)
{
  bool bisa = false;
  FORN(j,n)
    if (!udah[j])
    {
      bisa = true;
      break;
    }
  if (!bisa)
    return st[i];
  string tmp = "z";
  if (stk.sz()) // coba return
  {
    int z = stk.top();
    stk.pop();
    tmp = dfs(z,1);
    int x = 0;
    FORN(j,n)
      if (!udah[j])
        x++;
    if (tmp.sz() < x*5)
      tmp = "z";
    stk.push(z);
  }
  FORN(j,edge[i].sz())
    if (!udah[edge[i][j]])
    {
      udah[edge[i][j]] = true;
      stk.push(i);
      string s = dfs(edge[i][j],0);
      stk.pop();
      udah[edge[i][j]] = false;
      int x = 0;
      FORN(j,n)
        if (!udah[j])
          x++;
      if (s.sz() < x*5)
        s = "z";
      tmp = min(tmp,s);
    }
  if (mode == 0)
    return st[i]+tmp;
  return tmp;
}

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    int m;
    scanf("%d%d",&n,&m);
    string tmp = "99999";
    int z;
    FORN(j,n)
    {
      edge[j].clear();
      cin >> st[j];
      if (st[j] < tmp)
      {
        tmp = st[j];
        z = j;
      }
    }
    FORN(j,m)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      x--;
      y--;
      edge[x].pb(y);
      edge[y].pb(x);
    }
    RES(udah,false);
    while (stk.sz())
      stk.pop();
    udah[z] = true;
    printf("Case #%d: %s\n",i+1,dfs(z,0).c_str());
  }
}