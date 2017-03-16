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
    int a, b;
    cin>>a>>b;
    double wyn=b+2, pd=1;
    Fori(a)
    {
      double p;
      cin>>p;
      pd*=p;
      int lk=a-(i+1)+b-(i+1)+1;
      wyn=min(wyn, pd*lk+(1-pd)*(lk+b+1));
      
    }
    char s[100];
    sprintf(s, "%.8f", wyn);
    cout<<"Case #"<<ca<<": "<<s<<endl;
  }

  return 0;
}
