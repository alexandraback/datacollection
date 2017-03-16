#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
typedef unsigned long long ull;

typedef pair<int,int> pii;

pii hikers[20];

void solve()
{
  int n;
  cin >> n;
  int hcount = 0;
  for (int i=0; i<n; ++i)
  {
    int d, h, m;
    cin >> d >> h >>m;
    for (int j=0; j<h; ++j)
    {
      hikers[hcount++] = make_pair(d, m+j);
    }
  }
  int best = hcount; //infinifast
  for (int i=0; i<hcount; ++i)
  {
    int count = 0;
    double arrTime = ((360.0 - hikers[i].first)/360.0) * hikers[i].second;
    for (int j=0; j<hcount; ++j)
    {
      if (i==j) continue;
      double arrTime2 = ((360.0 - hikers[j].first)/360.0) * hikers[j].second;
      if (arrTime2 > arrTime)
      {
	++count;
      }
      else
      {
	count += max(0,(int)((arrTime-arrTime2)/hikers[j].second));
      }
    }
    if (count<0) count = 1.0e9;
    best = min(best, count);
  }
  printf("%d", best);
  return;
}

int main()
{
  int C;
  cin >> C;
  for (int i=1; i<=C; ++i)
  {

    printf("Case #%d: ", i);
    solve();
    printf("\n");    
  }
  return 0;
}
