
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

int main()
{
  int T,n,s,t,p;
  int d1,d2;
  int sum;
  int tmp,l;
  cin>>T;
  REP(j,T)
  {
    cin>>n>>s>>p;
    sum = 0;
    d1 = 0;
    d2 = 0;
    REP(i,n)
    {
      cin>>t;
      tmp = t/3;
      l = t%3;
      if (l==0)
      {
        if (tmp>=p)
        {
          sum++;
          d1++;
        }else if (tmp+1 >= p && t>=3)
        {
          d2++;
        }
      }else if (l==1)
      {
        if (tmp+1 >=p)
        {
          sum++;
          d1++;
        }else if (tmp+1 >= p && t>=3)
        {
          d2++;
        }
      }else
      {
        if (tmp+1 >=p)
        {
          sum++;
          d1++;
        }else if (tmp+2 >= p )
        {
          d2++;
        }
      }
    }

    if (s>d2)
      s = d2;
    cout<<"Case #"<<j+1<<": "<<sum+s<<endl;
  }

  return 0;
} 
