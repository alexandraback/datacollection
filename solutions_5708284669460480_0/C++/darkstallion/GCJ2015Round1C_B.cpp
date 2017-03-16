//darkstallion's template

#include<bits/stdc++.h>
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

int s,maxB,sum,cnt;
string keys,target,buffer;

int countBanana()
{
  int ret = 0;
  FORN(i,buffer.sz()-target.sz()+1)
  {
    int x = 0;
    bool sama = true;
    while (x < target.sz())
      if (buffer[i+x] == target[x])
        x++;
      else
      {
        sama = false;
        break;
      }
    if (sama)
      ret++;
  }
  return ret;
}

void dfs(int z)
{
  if (z == s)
  {
    int x = countBanana();
    maxB = max(maxB,x);
    sum += x;
    cnt++;
    return;
  }
  FORN(i,keys.sz())
  {
    buffer += keys[i];
    dfs(z+1);
    buffer.del(buffer.end()-1);
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    int x,y;
    scanf("%d%d%d",&x,&y,&s);
    cin >> keys >> target;
    buffer = "";
    maxB = 0;
    sum = 0;
    cnt = 0;
    dfs(0);
    printf("Case #%d: %.6lf\n",i+1,(double)maxB-((double)sum/(double)cnt));
  }
}