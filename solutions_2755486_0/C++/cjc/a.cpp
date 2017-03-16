#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct node
{
  int s, w, e;
};

vector<node> att[555];

void init()
{
  int d, n, w, e, s, dd, dp, ds;
  cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
  for (int i = 0; i < n; i++)
  {
    node m = node();
    m.s = s, m.w = w, m.e = e;
    att[d].push_back(m);
    d += dd;
    w += dp;
    e += dp;
    s += ds;
  }
}

int cal()
{
  map<int, int> wall;
  for(int i = -500; i <= 500; i++) wall[i] = 0;
  int res = 0;
  for (int i = 0; i < 555; i++)
  {
    int sz = att[i].size();
    if (!sz) continue;
    for (int j = 0; j < sz; j++)
    {
      int s = att[i][j].s;
      int w = att[i][j].w;
      int e = att[i][j].e;
      bool f = 0;
      for (int p = w; p < e; p++)
      {
        if (wall[p] < s) f = 1;
      }
      if (f) res++;
    }
    for (int j = 0; j < sz; j++)
    {
      int s = att[i][j].s;
      int w = att[i][j].w;
      int e = att[i][j].e;
      for (int p = w; p < e; p++)
      {
        wall[p] = max(wall[p], s);
      }
    }
  }
  return res;
}

int main()
{
  int T;
  cin>>T;
  for (int i = 1; i <= T; i++)
  {
    int n;
    cin>>n;
    for (int j = 0; j < n; j++) init();
    printf("Case #%d: %d\n", i, cal());
  }
}
