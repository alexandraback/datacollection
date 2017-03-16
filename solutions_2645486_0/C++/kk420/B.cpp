#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MaxInt=numeric_limits<int>::max();
typedef vector<int> VI;
typedef vector<string> VS;
#define For(i,a,n) for (int i=a; i<n; ++i)
#define Fori(n) For(i,0,n)


vector<long long> vv;
long long e, r, n;
/*
int ilex(int ee, int ter)
{
  if (ter>=vv.size())
    return 0;
  int w=0, il=-1;
  for (int i=0; i<=ee; ++i)
  {
    int a=i*vv[ter]+ile(min(e, ee-i+r), ter+1);
    if (a>w)
    {
      w=a;
      il=i;
    }
  }
  cout<<ter<<' '<<ee<<' '<<il<<endl;
  return w;
}  */

long long ile(int pierw, int ost, long long ePocz, int minEK)
{
  if (pierw>ost || pierw>=n || ost<0)
    return 0;
  long long ma=0, pm=-1;
  for (int i=pierw; i<=ost; ++i)
    if (vv[i]>ma)
    {
      ma=vv[i];
      pm=i;
    }
  long long en=min(e, ePocz+r*(pm-pierw));
  int x=min(en, en-minEK+r*(ost-pm+1));
  return ile(pierw, pm-1, ePocz, en)+ma*x+ile(pm+1, ost, en-x+r, minEK);
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    vv.clear();
    cin>>e>>r>>n;
    r=min(e, r);
    Fori(n)
    {
      long long a;
      cin>>a;
      vv.push_back(a);
    }
    cout<<"Case #"<<ca<<": "<<ile(0, n-1, e, 0)<<endl;
  }


  return 0;
}
