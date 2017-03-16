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

bool pal(long long l)
{
  int c[20], lc=0;
  while (l)
  {
    c[lc++]=l%10;
    l/=10;
  }
  for (int i=0, j=lc-1; i<j; ++i, --j)
    if (c[i]!=c[j])
      return false;
  return true;
}

int main()
{
  vector<long long> p;
  for (long long l=1; ; ++l)
  {
    long long ll=l*l;
    if (ll>100000000000000ll)
      break;
    if (pal(l) && pal(l*l)) 
      p.push_back(ll);
  }      

  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    long long a, b;
    cin>>a>>b;
    int wyn=0;
    Fori(p.size())
      if (a<=p[i] && p[i]<=b)
        ++wyn;
    cout<<"Case #"<<ca<<": "<<wyn<<endl;
  }
  return 0;
}
