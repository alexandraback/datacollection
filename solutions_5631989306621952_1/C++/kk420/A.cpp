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
    string s, wyn;
    cin>>s;
    wyn+=s[0];
    for (int i=1; i<s.length(); ++i)
      if (s[i]<wyn[0]) wyn+=s[i];
      else wyn=s[i]+wyn;
    
    
    cout<<"Case #"<<ca<<": "<<wyn<<endl;
  }

  return 0;
}
