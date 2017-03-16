
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i ++)
#define REP(i,n) FOR(i, 0, n)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back

int a,b;

int getCount(int x, int n)
{
  if (n < 2)
    return 0;
  set<int> buf;
  int ans = 0;
  int y;
  int f1,f2;
  FOR(i,1,n)
  {
    f1 = pow(10,i);
    f2 = pow(10, n-i);
    y = x/f1 + x%f1*f2;
    if (y>x && y<=b)
    {
      buf.insert(y);
      ans++;
    }
  }

  return buf.size();
}

int main()
{
  int T;
  int n;
  int tmp;
  int sum;
  cin>>T;
  REP(k, T)
  {
    sum = 0;
    n = 0;
    cin>>a>>b;
    tmp = a;
    while(tmp > 0)
    {
      tmp/=10;
      n++;
    }
    FOR(i,a,b)
    {
      sum += getCount(i,n);
    }
    cout<<"Case #"<<k+1<<": "<<sum<<endl;
  }

  return 0;
}
