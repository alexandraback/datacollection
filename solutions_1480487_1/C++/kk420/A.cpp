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
    int n, s[200], su=0, ma=0;
    cin>>n;
    Fori(n) 
    { cin>>s[i];
      su+=s[i];
      ma=max(ma, s[i]);
    }
    cout<<"Case #"<<ca<<": ";
    Fori(n)
    {
      char c[100];
      double l=0, p=1;
      for (int j=0; j<100; ++j)
      {
        double sr=(l+p)/2;
        double mp=s[i]+sr*su;
        double zost=su-mp+s[i];
        for (int k=0; k<n; ++k)
          if (k!=i && s[k]<mp)
             zost-=mp-s[k];
        if (zost<=0) p=sr;
        else l=sr;      
      }
      sprintf(c, "%.7f", l*100);
      cout<<c<<' ';
    }
    cout<<endl;
  }


  return 0;
}
