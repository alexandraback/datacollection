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

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    unsigned long long r, t, n=1;
    cin>>r>>t;
    while ((2*r+2*n-1)*n<t)
      n*=2;
    
  unsigned long long l=0, p=n;
  while (l<p)
  {
    unsigned long long sr=(l+p)/2;
    if ((2*r+2*sr-1)*sr<t) l=sr+1;
    else p=sr;
  }
  if ((2*r+2*l-1)*l<=t) n=l;
  else n=l-1;

  
    cout<<"Case #"<<ca<<": "<<n<<endl;
  }


  return 0;
}
