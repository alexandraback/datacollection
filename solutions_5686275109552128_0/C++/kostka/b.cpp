#include "bits/stdc++.h"

using namespace std;

class cmp
{
  public:
    bool operator() (pair<int,int> a, pair<int,int> b)
    {
      double x = 1.0*a.first/a.second;
      double y = 1.0*b.first/b.second;
      return x<y;
    }
};


long long test()
{
  int n;
  cin >> n;
  priority_queue <pair<int, int>, vector<pair<int, int>>, cmp> Q;
  int maks = 0;
  for(int i=0; i<n; i++)
  {
    int a;
    cin >> a;
    maks = max(maks, a);
    Q.push({a,1});
  }
  int res = 1<<30;
  for(int i=0; i<=maks; i++)
  {
    double t = 1.0*Q.top().first/Q.top().second;
    int tt = ceil(t);
    res = min(res, i+tt);
    pair<int, int> c = Q.top();
    Q.pop();
    Q.push({c.first,c.second+1});
  }
  return res;
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
    cout << "Case #" << tti << ": " << test() << "\n";
}
