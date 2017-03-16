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
    int a, b, k, wyn=0;
    cin>>a>>b>>k;
    for (int aa=0; aa<a; ++aa)
      for (int bb=0; bb<b; ++bb)
        if ((aa&bb)<k)
          ++wyn;
  
  
  
  
    cout<<"Case #"<<ca<<": "<<wyn<<endl;
  }


  return 0;
}
